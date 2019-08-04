#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string.h>
#include <string>


#include "TcpServer.h"

//using namespace std;

#define PORT "49522"
#define LOOPBACK "127.0.0.1"
#define QUITCOMMAND "!quit"
#define MAXDATASIZE 100



int main() {
    TcpServer* s= new TcpServer("127.0.0.1","49522");
    if(s->Init()){
        s->Run();
    }
    return 0;
}