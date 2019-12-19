#include "Cqueue.h"

Intergrator::Cqueue::Cqueue()
{

}

Intergrator::Cqueue::~Cqueue()
{

}

Intergrator::Cqueue& Intergrator::Cqueue::Instance()
{
    static Cqueue cque;
    return cque;
}

void Intergrator::Cqueue::Add(MSG msg)
{
    MutexLockGuard Mutex(mutex_);
    mq.push(msg);
    
}

void Intergrator::Cqueue::Get(MSG* msg)
{
    MutexLockGuard Mutex(mutex_);
    *msg = mq.front();
    mq.pop();
    
}
