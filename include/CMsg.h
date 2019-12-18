#pragma once

#include <iostream>
#include <sys/msg.h>
#include <string.h>
#include <unistd.h>

//id
#define ERRPR 0
#define INFO 1
#define WARN 2
#define DEBUG 3
#define FATAl 4

//msgid
int const KEYID = 7777;

struct MSGBUF
{
    int id ;
    char message[1024];
};

namespace Intergrator{


class CMsg
{
public:
    CMsg();
    ~CMsg();
    //bool Init();
    bool SendMsg(MSGBUF sbuf);
    bool RecvMsg(MSGBUF rbuf);
    
private:
    key_t key ;
    int id;
};

}