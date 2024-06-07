// Chapter 2 content and exploration

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>     // For inet_pton and inet_ntoa
#include <netinet/in.h>    // For sockaddr_in and INADDR_ANY
#include <sys/socket.h>    // For socket, bind, listen, accept

#define PORT 8080
#define BUFFER_SIZE 1024

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};
    const char *hello = "Hello from server";

    // Create socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Set up the address structure
    address.sin_family = AF_INET;           // Address family (IPv4)
    address.sin_addr.s_addr = INADDR_ANY;   // Accept connections from any interface
    address.sin_port = htons(PORT);         // Port number, converted to network byte order

    // Bind the socket to the network address and port
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_fd, 3) < 0) {
        perror("listen");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    // Accept an incoming connection
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
        perror("accept");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    // Read data from the client
    int valread = read(new_socket, buffer, BUFFER_SIZE);
    printf("%s\n", buffer);

    // Send a response to the client
    send(new_socket, hello, strlen(hello), 0);
    printf("Hello message sent\n");

    // Close the socket
    close(new_socket);
    close(server_fd);

    return 0;
}
