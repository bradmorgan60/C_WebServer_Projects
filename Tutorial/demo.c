#include "header.h"

struct Server server_constructor(int domain, int service, int protocol,
    u_long interface, int port, int backlog, void (*launch)(struct Server *server))
{
    struct Server server;
    server.domain = domain;
    server.service = service;
    server.protocol = protocol;
    server.interface = interface;
    server.port = port;
    server.backlog = backlog;

    server.address.sin_family = domain;
    server.address.sin_port = htons(port);
    server.address.sin_addr.s_addr = htonl(interface);

    // Create our own socket
    server.socket = socket(domain, service, protocol);
    if (server.socket < 0) {
        perror("Failed to create socket...\n");
        exit(EXIT_FAILURE);
    }

    // binding the socket to the port on the local machine
    // in a production scenario, this socket would bind to another node
    if ((bind(server.socket, (struct sockaddr *)&server.address, sizeof(server.address)) < 0)) {
        perror("Failed to bind socket...\n");
        exit(EXIT_FAILURE);
    }

    if ((listen(server.socket, server.backlog)) < 0) {
        printf("Server failed to start listening...\n");
        exit(EXIT_FAILURE);
    }

    server.launch = launch;
    return server;

}

int main() {
    struct Server;


    return 0;
}