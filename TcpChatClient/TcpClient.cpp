//
// Created by aerez on 7/28/19.
//
#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string.h>
#include <string>

#include "TcpClient.h"
#define MAXBUFFERSIZE 100

using namespace std;

void *get_in_addr(struct sockaddr *sa)
{
    if(sa->sa_family == AF_INET6){
        return &(((struct sockaddr_in*) sa)->sin_addr);
    }
    return &(((struct sockaddr_in*) sa)->sin_addr);
}

TcpClient::TcpClient(std::string ipAddress, std::string port) {
    this->ipAddress=ipAddress;
    this->port=port;
    fdmax=0;
    FD_ZERO(&(this->ioset));
    running=true;
}

int TcpClient::Init() {

    char buf[MAXBUFFERSIZE];
    struct addrinfo hints, *servinfo,*p;
    int rv;
    char s[INET6_ADDRSTRLEN];

    memset(&hints,0,sizeof hints);
    hints.ai_family=AF_UNSPEC;
    hints.ai_socktype=SOCK_STREAM;

    if((rv=getaddrinfo(ipAddress.c_str(),port.c_str(),&hints,&servinfo))!=0){
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
        return 1;
    }

    for(p=servinfo;p!=NULL;p=p->ai_next){
        if((sockfd =socket(p->ai_family,p->ai_socktype, p->ai_protocol))==-1){
            perror("client: socket");
            continue;
        }
        if(connect(sockfd, p->ai_addr, p->ai_addrlen)==-1){
            close(sockfd);
            perror("client: connect");
            continue;
        }
        break;
    }

    if(p==NULL){
        fprintf(stderr,"client: failed to connect\n");
        return 2;
    }

    inet_ntop(p->ai_family, get_in_addr((struct sockaddr *)p->ai_addr),s,sizeof s);
    cout<< "client: connected to "<<s<<endl;

    freeaddrinfo(servinfo);


    FD_SET(STDIN_FILENO,&ioset);
    FD_SET(sockfd, &ioset);
    fdmax = max(STDIN_FILENO, sockfd);

    return 0;

}

void TcpClient::Run() {
    int nbytes;
    string input;
    int i;
    char buf[MAXBUFFERSIZE];
    fd_set read_fds;
    FD_ZERO(&read_fds);




    while(running){
        read_fds= ioset;
        if(select(fdmax+1,&read_fds,NULL,NULL,NULL)==-1){
            perror("select");
            exit(4);
        }
        for(i=0;i<=fdmax;i++){

            if(FD_ISSET(i,&read_fds)){

                if(i==sockfd){
                    //handle new message
                    if((nbytes= recv(sockfd,buf,sizeof buf,0))<=0){
                        if(nbytes==0){
                            cout<<"server hung up"<<endl;
                            running= false;
                        }else{
                            perror("recv");
                        }
                        close(i);
                        FD_CLR(i,&ioset);
                    }else{

                        cout<<"\r"<<string(buf,0,nbytes+1)<<endl;


                    }
                }else {

                    getline(cin, input);

                    if(send(sockfd, input.c_str(), input.size() + 1, 0)==-1){
                        perror("send");
                    }





                }
            }
        }
    }

    shutdownclient();

}

void TcpClient::shutdownclient() {
    close(sockfd);
    cout<<"Goodbye";
}