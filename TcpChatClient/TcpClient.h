//
// Created by aerez on 7/28/19.
//

#include <string>

#ifndef TCPCHATCLIENT_TCPCLIENT_H
#define TCPCHATCLIENT_TCPCLIENT_H

#endif //TCPCHATCLIENT_TCPCLIENT_H

class TcpClient{
private:
    std::string ipAddress;
    std::string port;
    int sockfd;
    int fdmax;
    fd_set ioset;
    bool running;
public:
    TcpClient(std::string ipAddress,std::string port);
    ~TcpClient();
    int Init();
    void Run();
    void shutdownclient();
};