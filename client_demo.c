#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    int service;
    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);

    struct addrinfo hints, *result;
    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;

    service = getaddrinfo("localhost", "1234", &hints, &result);
    if (service != 0)
    {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(service));
        exit(1);
    }

    if (connect(socket_fd, result->ai_addr, result->ai_addrlen) == -1)
    {
        perror("connect");
        exit(2);
    }

    char *buffer = "GET / HTTP/1.0\r\n\r\n";
    printf("SENDING: %s", buffer);
    printf("===\n");

    write(socket_fd, buffer, strlen(buffer)); // write in one go

    char response[1000];
    int lenght = read(socket_fd, response, 999);
    response[lenght] = '\0';
    printf("%s\n", response);

    return 0;
}