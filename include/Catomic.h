#pragma once

#include <iostream>
#include <atomic>

namespace Intergrator{
class MyLock
{
public:
    MyLock();
    ~MyLock();
    
    void lock();
    void unlock();
private:
    std::atomic_flag m_flag;
};
}