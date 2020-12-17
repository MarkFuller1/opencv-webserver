#ifndef TCP_SERVER_H
#define TCP_SERVER_H

#include <string>
#include <netinet/in.h>

class TCP_Server {
public:
    int server_fd, new_socket;
    struct sockaddr_in address;
    long valread;
    long addrlen;

    //char * hello = "HTTP/1.1 200 OK\nContent-Type: text/plain\nContent-Length: 12\n\n Hello world!";

    TCP_Server();

    int connect();

    void respond(const char *data, int size);

    bool disconnect();

};

#endif
