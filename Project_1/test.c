/*
test.c
hdelibc
*/

#include <stdio.h>
#include <string.h>
#include "server.h"
#include <unistd.h>

void launch(struct Server *server) {
    char buffer[30000];
    printf("========= WAITING FOR CONNECTION =========");
    int address_length = sizeof(server->address);
    int new_socket = accept(server->socket, (struct sockaddr *)&server->address,
    (struct socklen_t *)&address_length);
    read(new_socket, buffer, 30000);
    printf("%s\n", buffer);
    char *hello = "";

    write(new_socket, hello, strlen(hello));
    close(new_socket);
    
}

int main() 
{
    struct Server server = server_constructor(AF_INET, 
        SOCK_STREAM, 0, INADDR_ANY, 80, 10, launch);

    server.launch(&server);

}