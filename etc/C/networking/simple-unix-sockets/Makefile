CC=/opt/mcst/lcc-1.23.17.e2k-v4.1c+.4.9/bin.toolchain/e2k-linux-gcc
CFLAGS=-fcontrol-spec

all:
	$(CC) $(CFLAGS) client.c util.c -o client
	$(CC) $(CFLAGS) server.c util.c -o server

clean:
	rm -rf *.o client server
