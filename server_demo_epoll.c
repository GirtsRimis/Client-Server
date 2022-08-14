#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/epoll.h>

// https://suchprogramming.com/epoll-in-3-easy-steps/

int main(int argc, char **argv)
{
    int epoll_fd = epoll_create(1);

    struct epoll_event event; // file descriptor
    event.events = EPOLLOUT; // EPOLLIN==read, EPOLLOUT==write
    event.data.fd = 0;
    
    if (epoll_ctl(epoll_fd, EPOLL_CTL_ADD, 0, &event) != 0)
    {
        fprintf(stderr, "Couldnt add file descriptor\n");
        exit(1);
    }

    int num_read = epoll_wait(epoll_fd, &event, 1, 10000);
    if (num_read > 0)
    {
        printf("Ready to write on %d\n", event.data.fd);
    }

    // Read data from same file descriptor
    event.events = EPOLLIN;
    event.data.fd = 0;
    epoll_ctl(epoll_fd, EPOLL_CTL_MOD, 0, &event);

    // Clean up socket and close file descriptor
    epoll_ctl(epoll_fd, EPOLL_CTL_DEL, 0, NULL);
    close(epoll_fd);

    return 0;
}