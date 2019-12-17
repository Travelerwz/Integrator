#pragma once 
#include <iostream>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/epoll.h>

#define PORT 7777
#define LISTENQ 20
namespace Intergrator{
class CEpoll
{
public:
    void SetNoblocking(int socketd);
    void BindSocket();
    
private:
    int listenfd;
};
}
