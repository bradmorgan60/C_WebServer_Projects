// Server side for a socket

#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define PORT 8080

int main(int argc, char const* argv[]) { // what are these arguments for?
    int server_fd, new_socket;
    ssize_t valread; // what does this mean? size of the socket / address? Do we need to account for address memory?
    struct sockaddr_in address; // what is contained in this struct? Which IP address is being used?
    int opt = 1; // why?
    socklen_t addrlen = sizeof(address);
    char buffer[1024] = { 0 };
    char* hello = "Hello from server";  // why a pointer?

    // create a socket file descriptor....what is a file descriptor?
    if((server_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE); // where is EXIT_FAILURE defined?
    }

    // forcefully attaching socket to the port 8080
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR , &opt, sizeof(opt))){
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    //  if (setsockopt(server_fd, SOL_SOCKET,
    //                SO_REUSEADDR | SO_REUSEPORT, &opt,
    //                sizeof(opt))) {
    //     perror("setsockopt");
    //     exit(EXIT_FAILURE);
    // }


    address.sin_family = AF_INET; // address family - internet
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);


    // bind, listen, accept methods
    // forcefully attaching socket to the port 8080
    if (bind(server_fd, (struct sockaddr*)&address, sizeof(address)) < 0 ) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    if((new_socket = accept(server_fd, (struct sockaddr*)&address, &addrlen)) < 0) {
        perror("accept");
        exit(EXIT_FAILURE);
    }

    valread = read(new_socket, buffer, 1024 - 1);
    printf("%s\n", buffer);
    send(new_socket, hello, strlen(hello), 0);
    printf("Hello message sent\n");

    close(new_socket);
    close(server_fd);

    return 0;
}