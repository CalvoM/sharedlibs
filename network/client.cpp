#include "netutils.h"
#include <iostream>
#include <string.h>

using std::cout;
using std::endl;
using std::memset;

TCPClient::TCPClient() {
    memset(&this->hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    this->sockfd = -1;
}

int TCPClient::Connect(string address, string port) {
    if (this->sockfd != -1) {
        cout << "Client is already connected" << endl;
        return EISCONN;
    }
    this->ret = getaddrinfo(address.c_str(), port.c_str(), &(this->hints),
                            &(this->res));
    if (this->ret != 0) {
        cout << gai_strerror(errno) << endl;
        return errno;
    }
    this->sockfd = socket(this->res->ai_family, this->res->ai_socktype,
                          this->res->ai_protocol);
    if (this->sockfd == -1) {
        cout << gai_strerror(errno) << endl;
        return errno;
    }
    this->ret =
        connect(this->sockfd, this->res->ai_addr, this->res->ai_addrlen);
    if (this->ret != 0) {
        cout << gai_strerror(errno) << endl;
        return errno;
    }
    cout << "successful connection to " << address << ":" << port << endl;
    return 0;
}

int TCPClient::SendString(string msg) {
    if (this->sockfd == -1) {
        cout << "client not connected" << endl;
        return -1;
    }
    this->ret = send(this->sockfd, msg.c_str(), msg.size(), 0);
    if (this->ret == -1) {
        cout << "send was not successful" << endl;
        return -1;
    }
    return this->ret;
}

int TCPClient::Send(char *msg) {
    if (this->sockfd == -1) {
        cout << "client not connected" << endl;
        return -1;
    }
    this->ret = send(this->sockfd, msg, strlen(msg), 0);
    if (this->ret == -1) {
        cout << "send was not successful" << endl;
        return -1;
    }
    return this->ret;
}

int TCPClient::Recv(char *const buffer, int buffer_size) {
    if (this->sockfd == -1) {
        cout << "client not connected" << endl;
        return -1;
    }
    this->ret = recv(this->sockfd, buffer, buffer_size, MSG_WAITALL);
    if (this->ret == -1) {
        cout << "did not receive" << endl;
        return -1;
    }
    return this->ret;
}

int TCPClient::Disconnect() {
    freeaddrinfo(this->res);
    return close(this->sockfd);
}

TCPClient::~TCPClient() {}