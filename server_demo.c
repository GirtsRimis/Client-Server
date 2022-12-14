#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <arpa/inet.h>

int main(int argc, char **argv)
{
    int service;
    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);

    struct addrinfo hints, *result;
    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;

    service = getaddrinfo(NULL, "1234", &hints, &result);
    if (service != 0)
    {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(service));
        exit(1);
    }

    // int optval = 1;
    // setsockopt(sfd, SOL_SOCKET, SO_REUSEPORT, &optval, sizeof (optval));

    // bind(.... to reuse port

    if (bind(socket_fd, result->ai_addr, result->ai_addrlen) != 0)
    {
        perror("bind()");
        exit(1);
    }

    if (listen(socket_fd, 10) != 0)
    {
        perror("listen()");
        exit(1);
    }

    struct sockaddr_in *result_addr = (struct sockaddr_in*)result->ai_addr;
    printf("Listening on file descriptor %d, port %d\n", socket_fd, ntohs(result_addr->sin_port));

    printf("Waiting for connection...\n");
    int client_fd = accept(socket_fd, NULL, NULL);
    printf("Connection made: client_fd = %d\n", client_fd);

    char buffer[1000];
    int length = read(client_fd, buffer, sizeof(buffer) - 1);
    buffer[length] = '\0';

    printf("Read %d chars\n", length);
    printf("===\n");
    printf("%s\n", buffer);

    return 0;
}
