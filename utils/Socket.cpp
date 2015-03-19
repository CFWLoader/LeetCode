//
// Created by cfwloader on 3/18/15.
//

#include <iostream>
#include <string.h>
#include <unistd.h>
#include "Socket.h"

Socket::Socket(std::string address, int port) {
    sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if(sock_fd == -1){
        std::cerr << "Failed to create socket." << std::endl;
        return;
    }
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = inet_addr(address.c_str());
    bzero(&(addr.sin_zero), 8);
    /*
    int result = connect(sock_fd, (sockaddr*) &addr, sizeof(sockaddr));
    if(result == -1){
        std::cerr << "Failed to connect server." << std::endl;
        close(sock_fd);
        return;
    }
    */
}

Socket::Socket(int client_fd, sockaddr_in client) {
    /*
    sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if(sock_fd == -1){
        std::cerr << "Failed to create socket." << std::endl;
        return;
    }
    */
    sock_fd = client_fd;
    addr.sin_family = AF_INET;
    addr.sin_port = client.sin_port;
    addr.sin_addr = client.sin_addr;
    bzero(&(addr.sin_zero), 8);
    /*
    int result = connect(sock_fd, (sockaddr*) &addr, sizeof(sockaddr));
    if(result == -1){
        std::cerr << "Failed to connect server." << std::endl;
        shutdown(sock_fd, SHUT_RDWR);
        sock_fd = -1;
        return;
    }
    */
}

Socket::~Socket() {
    shutdown(sock_fd, SHUT_RDWR);
}

bool Socket::isInitialized() const {
    return -1 != sock_fd;
}

int Socket::connect() {
    int result = ::connect(sock_fd, (sockaddr*) &addr, sizeof(sockaddr));
    if(result == -1){
        std::cerr << "Failed to connect server." << std::endl;
        close(sock_fd);
    }
    return result;
}

short Socket::getPort() const {
    return addr.sin_port;
}

in_addr Socket::getAddress() const {
    return addr.sin_addr;
}

int Socket::getSocketHandler() const {
    return sock_fd;
}

int Socket::sendMessage(std::string& msg) {
    if(!this->isInitialized()){
        std::cerr << "The socket haven't been initialized." << std::endl;
        return -1;
    }
    int result = ::send(sock_fd, msg.c_str(), 1024, 0);
    if(result == -1){
        std::cerr << "Failed to send message." << std::endl;
    }
    return result;
}

std::string Socket::receiveMessage() {
    if(!this->isInitialized()){
        std::cerr << "The socket haven't been initialized." << std::endl;
        throw std::exception();
    }
    char inputBuffer[1024];
    int result = ::recv(sock_fd, inputBuffer, 1024, 0);
    if(result == -1){
        std::cerr << "Failed to receive message." << std::endl;
        throw std::exception();
    }
    std::string msg(inputBuffer);
    return msg;
}