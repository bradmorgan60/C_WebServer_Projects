#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// the below ones are new to me
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>

#define PORT 8080
#define BUFFER_SIZE 1024 // this is bytes?


struct Server {
    int domain;
    int service;
    int protocol;
    u_long interface;
    int port;
    int backlog;

    struct sockaddr_in address;
    int socket;
    void (*launch)(void);
};