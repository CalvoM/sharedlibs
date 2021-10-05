#ifndef NET_UTILS_H
#define NET_UTILS_H

#include <string>
#include <cstring>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <errno.h>
#include <unistd.h>

using std::string;

class TCPClient{
    public:
        TCPClient();
        int Connect(string address, string port);
        int SendString(string msg);
        int Send(char *msg); 
        int Recv();
        int Disconnect();
    private:
        int ret;
        int sockfd; //socket file descriptor
        struct addrinfo hints, *res;
};


#endif