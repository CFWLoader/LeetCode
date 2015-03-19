//
// Created by cfwloader on 3/18/15.
//

#ifndef _CHATROOM_SERVERSOCKET_H_
#define _CHATROOM_SERVERSOCKET_H_

#include <string>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <errno.h>
#include <arpa/inet.h>                          //64bit operating system requires

#include "Socket.h"

#define MAX_CONNECTION_LIMIT 100

class ServerSocket {
public:
    ServerSocket(int);
    ServerSocket(std::string, int);
    virtual ~ServerSocket();
    bool isInitialized();
    Socket* accept();
    int sendMessage(const Socket&, std::string&);
    std::string receiveMessage(const Socket&);
private:
    int sock_fd;
    sockaddr_in addr;
};


#endif //_CHATROOM_SERVERSOCKET_H_
