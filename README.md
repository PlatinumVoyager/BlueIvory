# BlueIvory
A simple repository containing C source code used to demonstrate the basic capabilities/functionalities of client-to-server communication using TCP/UDP sockets.

## Build OPTS:
```
gcc -std=c11 dgram_serv.c -o dgram_serv && gcc -std=c11 dgram_client.c -o dgram_client
```
### Setting the server port to bind to the UDP socket:
```C
#define MYPORT "4950"
```

Executing the binary after it has been built with GCC:
1. ./dgram_serv 
2. ./dgram_client server_address message

server_address -> IPv4 address of target server
message -> character string containing information to send to server

