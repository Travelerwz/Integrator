#include "Catomic.h"

MyLock::MyLock()
{
    m_flag.clear();
}

MyLock::~MyLock()
{

}

void MyLock::lock()
{
    while(m_flag.test_and_set());
}

void MyLock::unlock()
{
    m_flag.clear();
}