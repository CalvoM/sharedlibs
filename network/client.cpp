#include "netutils.h"
#include <iostream>

using std::memset;
using std::cout;
using std::endl;


TCPClient::TCPClient(){
    memset(&this->hints,0,sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    this->sockfd = -1;
}

int TCPClient::Connect(std::string address, std::string port){
    if(this->sockfd != -1){
        cout<<"Client is already connected"<<endl;
        return EISCONN;
    }
    this->ret = getaddrinfo(address.c_str(),port.c_str(),&(this->hints),&(this->res));
    if(this->ret != 0){
        cout<<gai_strerror(errno)<<endl;
        return errno;
    }
    this->sockfd = socket(this->res->ai_family,this->res->ai_socktype,this->res->ai_protocol);
    if(this->sockfd == -1){
        cout<<gai_strerror(errno)<<endl;
        return errno;
    }
    this->ret = connect(this->sockfd,this->res->ai_addr,this->res->ai_addrlen);
    if(this->ret != 0){
        cout<<gai_strerror(errno)<<endl;
        return errno;
    }
    cout<<"succssful connection to "<<address<<":"<<port<<endl;
    return 0;
}

int TCPClient::Disconnect(){
    freeaddrinfo(this->res);
    return close(this->sockfd);
}