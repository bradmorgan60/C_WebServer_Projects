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
    socklen_t client_addr_len = sizeof(client_addr);
    
    // create a socket
    socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if(bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    return 0;
}