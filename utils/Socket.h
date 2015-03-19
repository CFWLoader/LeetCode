//
// Created by cfwloader on 3/18/15.
//

#ifndef _CHATROOM_SOCKET_H_
#define _CHATROOM_SOCKET_H_

#include <string>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>                          //64bit operating system requires

class Socket {
public:
    Socket(std::string, int);
    Socket(int, sockaddr_in);
    virtual ~Socket();
    bool isInitialized() const;
    short getPort() const;
    in_addr getAddress() const;
    int getSocketHandler() const;
    int connect();
    int sendMessage(std::string&);
private:
    int sock_fd;
    sockaddr_in addr;
};


#endif //_CHATROOM_SOCKET_H_
