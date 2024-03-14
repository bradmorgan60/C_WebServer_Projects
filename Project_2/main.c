/*
Basic web server in C
functions needed:
1. Socket -- create an endpoint for communication
2. Bind -- bind the socket to a search and address
3. sockaddr_in -> used for IPv4 addresses
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
// #include <sys/sendfile.h>
#include <netinet/in.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

void main() {
    int s = socket(PF_INET, SOCK_STREAM, 0);
    struct sockaddr_in addr = {
        AF_INET,
        "0x901f",
        0
    };

    bind(s, &addr, sizeof(addr));
    listen(s, 10);
    int client_fd = accept(s, 0, 0);
    char buffer[256] = {0};
    recv(client_fd, buffer, 256, 0);

    char* f = buffer + 5;
    *strchr(f, ' ') = 0;
    int opened_fd = open(f, O_RDONLY);
    send(client_fd, opened_fd, 0, 256);
    close(opened_fd);
    close(client_fd);
    close(s);
}