#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

struct addrinfo hints, *infoptr; // no memset variables

int main()
{
    hints.ai_family = AF_INET; // IPv4 only

    int result = getaddrinfo("www.google.com", NULL, &hints, &infoptr);
    if (result)
    {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(result));
        exit(1);
    }

    struct addrinfo *p;
    char host[256];

    for (p = infoptr; p != NULL; p = p->ai_next)
    {
        getnameinfo(p->ai_addr, p->ai_addrlen, host, sizeof(host), NULL, 0, NI_NUMERICHOST);
        puts(host); // output
    }

    freeaddrinfo(infoptr);

    return 0;
}