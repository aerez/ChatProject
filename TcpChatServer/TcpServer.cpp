//
// Created by aerez on 7/25/19.
//

#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string.h>
#include <string>

#include "TcpServer.h"


using namespace std;

void *get_in_addr(struct sockaddr *sa)
{
    if(sa->sa_family ==AF_INET){
        return &(((struct sockaddr_in*)sa)->sin_addr);
    }

    return &(((struct sockaddr_in6*)sa)->sin6_addr);
}

void TcpServer::sendClientMessage(char * buf,int nbytes, vector<TcpClient>::iterator sender) {
    int i,j;
    string msgfrom=sender->getName()+": ";
    string bufstr=string(buf,nbytes-1);
    cout<<bufstr<<endl;
    vector<TcpClient>::iterator p;


    if(bufstr[0]=='!'){

        cout<<bufstr;
        if(bufstr=="!clientlist"){
            j=0;
            string list="";
            for(p=clients.begin();p!=clients.end();p++){
                if(!(*(p)==*sender)) {
                    list.append(to_string((j++) + 1) + p->getName() + "\n");
                }
            }
            send(sender->getSocket(),list.c_str(),list.size()+1,0);
        }
        if(bufstr.substr(0,5)=="!name"){
            string newname= bufstr.substr(6);
            sender->setName(newname);
        }
        if(bufstr.substr(0,8)=="!unicast"){
            string target=bufstr.substr(9);
            int pos=target.find(" ");
            string msg=target.substr(pos+1);
            target=target.substr(0,pos);
            for(p=clients.begin();p->getName()!=target&&p!=clients.end();p++);


            string err="User not found!";
            if(p==clients.begin()){
                send(sender->getSocket(),err.c_str(),err.size()+1,0);
            } else{
                msgfrom.append(msg);
                send(p->getSocket(),msgfrom.c_str(),msgfrom.size()+1,0);
            }

        }

        if(bufstr.substr(0,10)=="!multicast"){
            int pos=bufstr.find("-m");
            string msg=bufstr.substr(pos+3);
            string targets=bufstr.substr(11,pos-10);
            int index=0;
            while(targets[index]!='-'){
                pos=targets.find(" ");
                string singletarget=targets.substr(0,pos);
                p=clients.begin();
                for(p=clients.begin();p->getName()!=singletarget&&p!=clients.end();p++);
                string err="couldnt find "+singletarget+"\n";
                if(p==clients.end()){
                    send(sender->getSocket(),err.c_str(),err.size()+1,0);
                } else{
                    msgfrom=sender->getName()+": ";
                    msgfrom.append(msg);
                    send(p->getSocket(),msgfrom.c_str(),msgfrom.size()+1,0);
                }
                targets=targets.substr(pos+1);
            }
        }
        if(bufstr=="!commands"){
            string cmd="!name [new name] to change name\n";
            cmd.append("!clientlist to view other clients\n");
            cmd.append("!unicast [client name] [message]\n");
            cmd.append("!multicast [client name][..] -m [message]\n");
            cmd.append("!shutdown closes server\n");
            send(sender->getSocket(),cmd.c_str(),cmd.size()+1,0);
        }
        if(bufstr=="!shutdown"){
            running= false;
        }
    }else{
        msgfrom.append(bufstr);
        for(p=clients.begin();p!=clients.end();p++) {
            if (!(*(p)==*sender)) {
                send(p->getSocket(), msgfrom.c_str(), msgfrom.size()+1, 0);
            }
        }
    }



}

TcpServer::TcpServer(std::string ipAddress, std::string port) {
    this->ipAddress=ipAddress;
    this->port=port;
    FD_ZERO(&(this->master));
    fdmax=0;
    running=true;

}



int TcpServer::Init() {
    createListener();
    if(listener==-1)
        return 0;
    return 1;
}

void TcpServer::createListener() {

    struct addrinfo hints, *ai, *p;
    int rv, yes = 1;
    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;//ipv4 or ipv6
    hints.ai_socktype = SOCK_STREAM;// tcp socket

    if ((rv = getaddrinfo(ipAddress.c_str(), port.c_str(), &hints, &ai)) != 0) {
        fprintf(stderr, "select server: %s\n", gai_strerror(rv));
        exit(1);
    }


    for (p = ai; p != NULL; p = p->ai_next) {
        listener = socket(p->ai_family, p->ai_socktype, p->ai_protocol);
        if (listener < 0) {
            continue;
        }
        //avoid "address already in use msg" error
        setsockopt(listener, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int));

        if (bind(listener, p->ai_addr, p->ai_addrlen) < 0) {
            close(listener);
            continue;
        }

        break;
    }

    if (p == NULL) {
        fprintf(stderr, "select server: failed to bind\n");
        exit(2);
    }

    freeaddrinfo(ai);

    FD_SET(listener, &master);
    fdmax = listener;

    if(listen(listener,10)==-1){
        perror("listen");
        exit(3);
    }
    cout << "listener is READY!" << endl;


}


void TcpServer::Run() {
    int newfd;


    fd_set read_fds;
    int i,j,nbytes;
    struct sockaddr_storage remoteaddr;//client address;
    socklen_t addrlen;
    char buf[256];// buffer for client
    char remoteIP[INET6_ADDRSTRLEN];
    FD_ZERO(&read_fds);

    while(running){
        read_fds= master;//copy the master because select() changes the set;
        if(select(fdmax+1, &read_fds,NULL,NULL,NULL)==-1){
            perror("select");
            exit(4);
        }

        //run through the set if there is any data to read
        for(i=0;i<=fdmax;i++){
            if(FD_ISSET(i,&read_fds)){// new connection
                if(i==listener){
                    //handle new connection
                    addrlen= sizeof remoteaddr;
                    newfd= accept(listener,(struct sockaddr *)&remoteaddr,&addrlen);

                    if(newfd== -1){
                        perror("accept");
                    }else{
                        FD_SET(newfd,&master);
                        if(newfd>fdmax){
                            fdmax=newfd;
                        }
                        clients.push_back(*(new TcpClient("User#"+to_string(newfd-3),newfd)));
                        cout<<"selectserver: new connection from "<<
                        inet_ntop(remoteaddr.ss_family,get_in_addr((struct sockaddr*)&remoteaddr),
                                remoteIP,INET6_ADDRSTRLEN)<<"on socket "<<newfd<<endl;
                        string wlc = "Welcome to the Server!\nusername: User#"+to_string(newfd-3)
                                +"\n!commands for info";
                        cout<< wlc;
                        send(newfd,wlc.c_str(),wlc.size()+1,0);
                    }

                }else{
                    //handle data from client
                    vector<TcpClient>::iterator x;
                    if((nbytes=recv(i,buf,sizeof buf,0))<=0){
                        if(nbytes==0){
                            cout<<"selectserver: socket "<<i<<"hung up "<<endl;
                            for(x=clients.begin();x->getSocket()!=i&&x!=clients.end();x++);
                            clients.erase(x);
                        }else{
                            perror("recv");
                        }
                        close(i);
                        FD_CLR(i,&master);
                    }else{
                        //actual data
                        for(x=clients.begin();x->getSocket()!=i&&x!=clients.end();x++);
                        sendClientMessage(buf, nbytes, x);

                    }
                }
            }
        }
    }
    FD_ZERO(&read_fds);
    closeServer();
}

void TcpServer::closeServer() {
    string byemsg="Server is shutting down!...";

    for(vector<TcpClient>::iterator p=clients.begin();p!=clients.end();p++){
        send(p->getSocket(),byemsg.c_str(),byemsg.size()+1,0);
        close(p->getSocket());
    }
    close(listener);
    FD_ZERO(&master);
    clients.clear();
}




