//
// Created by aerez on 7/25/19.
//

#include <string>

#include <vector>
#include "Client.h"
#ifndef TCPCHATSERVER_TCPSERVER_H
#define TCPCHATSERVER_TCPSERVER_H

#endif //TCPCHATSERVER_TCPSERVER_H


#define MAXCLIENTSNUM 30

class TcpServer{

private:
    std::string ipAddress;
    std::string port;
    fd_set master;
    int listener,fdmax;
    bool running;
    std::vector<TcpClient> clients;


public:
    TcpServer(std::string ipAddress, std::string port);
    //initialize
    int Init();
    //create listener
    void createListener();
    //wait for data loop
    void Run();
    //send msg
    void sendClientMessage(char * msg,int nbytes, std::vector<TcpClient>::iterator sender);


    //close server
    void closeServer();
};

