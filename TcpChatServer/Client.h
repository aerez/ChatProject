//
// Created by aerez on 7/28/19.
//

#include <string>

#ifndef TCPCHATSERVER_CLIENT_H
#define TCPCHATSERVER_CLIENT_H

#endif //TCPCHATSERVER_CLIENT_H

class TcpClient{
private:
    std::string name;
    int socket;
public:
    TcpClient();
    TcpClient(std::string name, int socket);
    int getSocket()const ;
    std::string getName()const ;
    void setSocket(int socket);
    void setName(std::string name);
    bool operator==(const TcpClient& other) const ;

};