#pragma once
#include <iostream>
#include <mutex>

class MutexLockGuard
{
public:
    explicit MutexLockGuard(std::mutex& Mutex):mutex_(Mutex)
    {
        mutex_.lock();
    }
    ~MutexLockGuard()
    {
        mutex_.unlock();
    }
private:
    std::mutex& mutex_;
};
