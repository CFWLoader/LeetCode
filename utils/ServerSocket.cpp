//
// Created by cfwloader on 3/18/15.
//

#include <iostream>
#include <string.h>
#include <unistd.h>
#include "ServerSocket.h"

ServerSocket::ServerSocket(std::string address, int port) {
    sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if(sock_fd == -1){
        std::cerr << "Failed to create socket." << std::endl;
        return;
    }
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = inet_addr(address.c_str());
    bzero(&(addr.sin_zero), 8);
    int result = bind(sock_fd, (sockaddr*) &addr, sizeof(sockaddr));
    if(result == -1){
        std::cerr << "Failed to bind address." << std::endl;
        shutdown(sock_fd, SHUT_RDWR);
        sock_fd = -1;
        return;
    }
    result = listen(sock_fd, MAX_CONNECTION_LIMIT);
    if(result == -1){
        std::cerr << "Failed to listen." << std::endl;
        shutdown(sock_fd, SHUT_RDWR);
        sock_fd = -1;
        return;
    }
}

ServerSocket::ServerSocket(int port){
    sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if(sock_fd == -1){
        std::cerr << "Failed to create socket." << std::endl;
        return;
    }
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    bzero(&(addr.sin_zero), 8);
    int result = bind(sock_fd, (sockaddr*) &addr, sizeof(sockaddr));
    if(result == -1){
        std::cerr << "Failed to bind address." << std::endl;
        close(sock_fd);
        return;
    }
    result = listen(sock_fd, MAX_CONNECTION_LIMIT);
    if(result == -1){
        std::cerr << "Failed to listen." << std::endl;
        close(sock_fd);
        return;
    }
}

ServerSocket::~ServerSocket() {
    close(sock_fd);
}

bool ServerSocket::isInitialized() {
    return -1 != sock_fd;
}

Socket* ServerSocket::accept() {
    sockaddr_in client_addr;
    int sin_size = sizeof(sockaddr_in);
    int client_fd = ::accept(sock_fd, (sockaddr*)&client_addr, (socklen_t*)&sin_size);
    Socket* client = new Socket(client_fd, client_addr);
    return client;
}

int ServerSocket::sendMessage(const Socket& target, std::string& msg){
    int result = ::send(target.getSocketHandler(), msg.c_str(), 1024, 0);
    if(result == -1){
        std::cerr << "Server failed to send message to client." << std::endl;
    }
    return result;
}