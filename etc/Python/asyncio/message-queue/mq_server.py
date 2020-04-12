import asyncio
from asyncio import StreamReader, StreamWriter, Queue
import contextlib
from collections import deque, defaultdict
from typing import Deque, DefaultDict, Dict
from msgproto import read_msg, send_msg

# Sending and receiving messages are decoupled to resolve the problem where
# a slow subscriber would also slow down receiving new messages.
SUBSCRIBERS: DefaultDict[bytes, Deque] = defaultdict(deque)
SEND_QUEUES: DefaultDict[StreamWriter, Queue] = defaultdict(Queue)
CHAN_QUEUES: Dict[bytes, Queue] = {}


async def client(reader: StreamReader, writer: StreamWriter):
    peername = writer.get_extra_info('peername')
    subscribe_chan = await read_msg(reader)
    SUBSCRIBERS[subscribe_chan].append(writer)
    # Create a long-lived task that will do all the sending of data to
    # this client.
    send_task = asyncio.create_task(send_client(writer, SEND_QUEUES[writer]))
    print(f'Remote {peername} subscribed to {subscribe_chan}')

    try:
        while True:
            channel_name = await read_msg(reader)
            if not channel_name:
                break
            data = await read_msg(reader)
            # Create a new, dedicated Queue for every destination channel
            if channel_name not in CHAN_QUEUES:
                CHAN_QUEUES[channel_name] = Queue(maxsize=10)
                asyncio.create_task(chan_sender(channel_name))
            # Place the newly received data onto the specific channel's queue.
            # If the queue fills up, we'll wait here until there is space
            # for the new data.
            await CHAN_QUEUES[channel_name].put(data)
    except asyncio.CancelledError:
        print(f'Remote {peername} closing connection.')
        writer.close()
        await writer.wait_closed()
    except asyncio.IncompleteReadError:
        print(f'Remote {peername} disconnected')
    finally:
        print(f'Remote {peername} closed')
        # None message will break send_client
        await SEND_QUEUES[writer].put(None)
        await send_task
        del SEND_QUEUES[writer]
        SUBSCRIBERS[subscribe_chan].remove(writer)


async def send_client(writer: StreamWriter, queue: Queue):
    while True:
        try:
            data = await queue.get()
        except asyncio.CancelledError:
            continue

        if not data:
            break

        try:
            await send_msg(writer, data)
        except asyncio.CancelledError:
            await send_msg(writer, data)

    writer.close()
    await writer.wait_closed()


async def chan_sender(name: bytes):
    with contextlib.suppress(asyncio.CancelledError):
        while True:
            writers = SUBSCRIBERS[name]
            if not writers:
                await asyncio.sleep(1)
                continue
            if name.startswith(b'/queue'):
                writers.rotate()
                writers = [writers[0]]  # grab the first
            msg = await CHAN_QUEUES[name].get()
            if not msg:
                break
            for writer in writers:
                if not SEND_QUEUES[writer].full():
                    print(f'Sending to {name}: {msg[:19]}...')
                    await SEND_QUEUES[writer].put(msg)


async def main(*args, **kwargs):
    server = await asyncio.start_server(*args, **kwargs)
    async with server:
        await server.serve_forever()


if __name__ == '__main__':
    try:
        asyncio.run(main(client, host='127.0.0.1', port=5000))
    except KeyboardInterrupt:
        print('Exited')
