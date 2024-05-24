/*
Chat GPT Tutorial
Need a client and a server
- needs to be able to accept and send back responses
- this is an introduction to network programming
- TCP/IP and socket programming development
- L3 of the OSI 7-Layer model
*/

#include "header.h"

void handle_client(int client_socket) {
    char buffer[BUFFER_SIZE];
    int bytes_read;

    bytes_read = read(client_socket, buffer, BUFFER_SIZE - 1);
    if (bytes_read < 1) {
        perror("read");
        close(client_socket);
        return;
    }

    buffer[bytes_read] = '\0';
    printf("Received request:\n%s\n", buffer);

    const char *response = 
        "HTTP/1.1 200 OK\r\n"
        "Content-Type: text/html\r\n"
        "Content-Length: 13\r\n"
        "\r\n"
        "Hello, world!";

    write(client_socket, response, strlen(response));

    close(client_socket);
}
    

int main() {
    int server_fd, client_socket;
    struct sockaddr_in server_addr, client_addr;
    return 0;
}