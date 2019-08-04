//
// Created by aerez on 7/28/19.
//

#include "Client.h"

using namespace std;

TcpClient::TcpClient(std::string name, int socket) {
    this->name=name;
    this->socket=socket;
}

TcpClient::TcpClient() {
    this->name="NULL";
    this->socket=NULL;
}

std::string TcpClient::getName() const {
    return name;
}

int TcpClient::getSocket() const {
    return socket;
}

void TcpClient::setName(std::string name) {
    this->name=name;
}

void TcpClient::setSocket(int socket) {
    this->socket=socket;
}

bool TcpClient::operator==(const TcpClient &other) const {
    if(this->getName()!=other.getName())
        return false;
    if(this->getSocket()!=other.getSocket())
        return false;
    return true;
}