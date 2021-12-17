#ifndef NET_UTILS_H
#define NET_UTILS_H

#include <arpa/inet.h>
#include <cstring>
#include <errno.h>
#include <netdb.h>
#include <netinet/in.h>
#include <string>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

using std::string;

class TCPClient {
  public:
    TCPClient();
    int Connect(string address, string port);
    int SendString(string msg);
    int Send(char *msg);
    int Recv(char *const, int);
    int Disconnect();
    ~TCPClient();

  private:
    int ret;
    int sockfd; // socket file descriptor
    struct addrinfo hints, *res;
};

#endif