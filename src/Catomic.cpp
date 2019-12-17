#include "Catomic.h"

Intergrator::MyLock::MyLock()
{
    m_flag.clear();
}

Intergrator::MyLock::~MyLock()
{

}

void Intergrator::MyLock::lock()
{
    while(m_flag.test_and_set());
}

void Intergrator::MyLock::unlock()
{
    m_flag.clear();
}