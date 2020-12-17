// Server side C program to demonstrate HTTP Server programming
#include <cstdio>
#include <sys/socket.h>
#include <unistd.h>
#include <cstdlib>
#include <netinet/in.h>
#include <cstring>
#include "TCP_Server.h"

#define PORT 8080


TCP_Server::TCP_Server() {
    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("In socket");
        exit(EXIT_FAILURE);
    }

    linger lin;
    lin.l_onoff = 0;
    lin.l_linger = 0;
    setsockopt(server_fd, SOL_SOCKET, SO_LINGER, (const char *) &lin, sizeof(int));


    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    memset(address.sin_zero, '\0', sizeof address.sin_zero);


    addrlen = sizeof(address);

    if (bind(server_fd, (struct sockaddr *) &address, sizeof(address)) < 0) {
        perror("In bind");
        exit(EXIT_FAILURE);
    }
    if (listen(server_fd, 10) < 0) {
        perror("In listen");
        exit(EXIT_FAILURE);
    }
}

int TCP_Server::connect() {
    printf("\n+++++++ Waiting for new connection ++++++++\n\n");
    if ((new_socket = accept(server_fd, (struct sockaddr *) &address, (socklen_t *) &addrlen)) < 0) {
        perror("In accept");
        exit(EXIT_FAILURE);
    }

    char buffer[30000] = {0};
    valread = read(new_socket, buffer, 30000);
    printf("%s\n", buffer);

    return new_socket;
}

void TCP_Server::respond(const char *data, int size) {
    write(new_socket, data, size);
}

bool TCP_Server::disconnect() {
    close(new_socket);

    return true;
}


