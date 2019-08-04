
using namespace std;


#define PORT "49522"
#define LOOPBACK "127.0.0.1"

#include "TcpClient.h"


int main() {
    TcpClient* client= new TcpClient("127.0.0.1","49522");
    if(!client->Init()){
        client->Run();
    }
    return 0;
}