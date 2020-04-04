#pragma once

#include <sys/types.h>
#include <unistd.h>

#define SOCKPATH "/tmp/demo_1.sock"
#define BUF_SIZE 20

ssize_t send_size(int fd, const void *buf, size_t length);
int recv_size(int fd, void *buf, size_t length);
void setblocking(int fd, int state);
