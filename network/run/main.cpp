#include "../netutils.h"

int main(){
    TCPClient tcp;
    int conn = tcp.Connect("localhost","3000");
    char name[4] = {0x41,0x42,0x43};
    if(conn ==0){
        while(true){
            tcp.Recv();
            tcp.Send(name);
            tcp.SendString("Kituoni");
        }
    tcp.Disconnect();
    }
}