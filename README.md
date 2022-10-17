# BlueIvory
A simple repository containing C source code used to demonstrate the basic capabilities/functionalities of client-to-server communication using TCP/UDP sockets.

## Build OPTS:
```
git clone https://github.com/PlatinumVoyager/BlueIvory.git
cd BlueIvory ; mkdir build
gcc -std=c11 dgram_serv.c -o build/dgram_serv && gcc -std=c11 dgram_client.c -o build/dgram_client
gcc -std=c11 stream_serv.c -o build/stream_serv && gcc -std=c11 stream_client.c -o build/stream_client
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
./build/dgram_serv 
./build/dgram_client server_address message
```

Executing the binary after it has been built with GCC (TCP):
```
./build/stream_serv message
./build/stream_client server_address
```

> server_address -> IPv4 address of target server (can specify Fully Qualified Domain Name if OPTs supported on remote server)

> message -> character string containing information to send to server/client

*NOTE: For the server 'message' it needs to follow 1-2 criteria in which is specified as the following: the server 'message' must be enclosed within single/double quotes as to encapsulate the entirety of the message being directed to the client/server or each individual ' ' (space) that is used to separate words within the message must be escaped via* '\ ' *(backslash)*


