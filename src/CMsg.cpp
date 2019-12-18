#include "CMsg.h"

Intergrator::CMsg::CMsg()
{
    key = ftok("/CMSG",66);
    id = msgget(key,0666|IPC_CREAT);
    if(id == -1)
    {
        printf("open msg error \n");
    }
}

Intergrator::CMsg::~CMsg()
{
    msgctl(id,IPC_RMID,NULL);
}

// bool Intergrator::CMsg::Init()
// {

// }

bool Intergrator::CMsg::SendMsg(MSGBUF sbuf)
{
    int res = msgsnd(id,(void*)&sbuf,sizeof(msgbuf),0);
    if(res <0)
    {
        return false;
    }
    return true;
}

bool Intergrator::CMsg::RecvMsg(MSGBUF rbuf)
{
    memset(&rbuf,0,sizeof(rbuf));
    int res = msgrcv(id,(void*)&rbuf,sizeof(rbuf),1,0);
    if(res <0)
    {
        perror("msgrcv");
        return false;
    }
    printf("id:%d\n",rbuf.id);
    printf("data:%s\n",rbuf.message);
    return true;
}