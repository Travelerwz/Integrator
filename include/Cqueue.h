#pragma once
#include <iostream>
#include <queue>
#include "MutexLockGuard.h"

struct MSG
{
    int id ;
    char message[1024];
};

namespace Intergrator{

class Cqueue
{
public:
    static Cqueue& Instance();
    void Add(MSG msg);
    void Get(MSG* msg);
private:
    Cqueue();
    ~Cqueue();
    std::queue<MSG> mq;
    std::mutex mutex_;
};

}

#define QUEUE Intergrator::Cqueue::Instance()