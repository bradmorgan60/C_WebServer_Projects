/*
Chat GPT Tutorial
Need a client and a server
- needs to be able to accept and send back responses
- this is an introduction to network programming
- TCP/IP and socket programming development
- L3 of the OSI 7-Layer model
*/

#include "header.h"

// This is the function we will use when we write our content to the server
void handle_client(int client_socket) {
    char buffer[BUFFER_SIZE];
    int bytes_read;

    bytes_read = read(client_socket, buffer, BUFFER_SIZE - 1);
    if (bytes_read < 0) {
        perror("read");
        close(client_socket);
        return;
    }

    buffer[bytes_read] = '\0';
    printf("Received request:\n%s\n", buffer);

    const char *response = 
        "HTTP/1.1 200 OK\r\n"
        "Content-Type: text/html\r\n"
        "Content-Length: 200\r\n"
        "\r\n"
        "Discipline is the difference between who wants it and who gets it";
        
    write(client_socket, response, strlen(response));
    close(client_socket);
}
    
int main() {
    int server_fd, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_len = sizeof(client_addr);
    
    // create a socket
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1) {
        // if this fails, the endpoint is not created which means no bidirectional traffic can occur
        perror("Failed to create socket...\n");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Once we have a socket, I need to associate that socket with a port on my local machine
    if(bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Failed to bind socket to port...\n");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    // This will listen for incoming connections
    if (listen(server_fd, 10) < 0) {
        perror("Failed to begin listening...\n");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    printf("Server is listening on port %d\n", PORT);
    printf("Server: %d\n", server_fd);

    // Need a loop to accept and handle client connections
    while(1) {
        client_socket = accept(server_fd, (struct sockaddr *)&client_addr, &client_addr_len);
        if (client_socket < 0) {
            perror("Connection accepted...\n");
            close(server_fd);
            exit(EXIT_FAILURE);
        }

        handle_client(client_socket);
    }

    close(server_fd);

    return 0;
}