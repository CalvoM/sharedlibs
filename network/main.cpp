#include "netutils.h"

int main(){
    TCPClient tcp;
    tcp.Connect("localhost","3000");
    tcp.Disconnect();
}