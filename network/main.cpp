#include "netutils.h"

int main(){
    TCPClient tcp;
    int conn = tcp.Connect("localhost","3000");
    if(conn ==0){
        while(true){
            tcp.Recv();
            tcp.Send("nambie");
        }
    tcp.Disconnect();
    }
}