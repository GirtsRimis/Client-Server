### Server
server_demo.c
```
[girts@girts-81lb Client-Server]$ ./server_demo
Listening on file descriptor 3, port 1234
Waiting for connection...
Connection made: client_fd = 4
Read 16 chars
===
Hello World!
```

### Client
client_demo.c
```
[girts@girts-81lb Client-Server]$ ./client_demo 
SENDING: Hello World!

===
```
