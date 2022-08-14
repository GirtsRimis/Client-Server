CPP=g++
CC=gcc
CFLAGS=-I.

# main: main.o
# 	$(CPP) -o main main.o

# convert_dns: convert_dns.o
# 	$(CC) -o convert_dns convert_dns.o

# client_demo: client_demo.o
# 	$(CC) -o client_demo client_demo.o

# server_demo: server_demo.o
# 	$(CC) -o server_demo server_demo.o

server_demo_epoll: server_demo_epoll.o
	$(CC) -o server_demo_epoll server_demo_epoll.o