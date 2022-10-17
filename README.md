# BlueIvory
A simple repository containing C source code used to demonstrate the basic capabilities/functionalities of client-to-server communication using TCP/UDP sockets.

## Build OPTS:
```
gcc -std=c11 dgram_serv.c -o dgram_serv && gcc -std=c11 dgram_client.c -o dgram_client
```
### Setting the server port to bind to the TCP/UDP socket:

* Within `dgram_serv.c`
```C
#define MYPORT "4950"
```

* Within `stream_serv.c`
```C
#define PORT "3490"
```

Executing the binary after it has been built with GCC (UDP):
```
./dgram_serv 
./dgram_client server_address message
```

Executing the binary after it has been built with GCC (TCP):
```
./stream_serv message
./stream_client server_address
```

> server_address -> IPv4 address of target server (can specify Fully Qualified Domain Name if OPTs supported on remote server)

> message -> character string containing information to send to server/client

