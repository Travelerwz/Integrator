#include "CMysqlPool.h"

Intergrator::CMysqlPool::CMysqlPool(int num)
{
    m_poolnum = num;
}

Intergrator::CMysqlPool::~CMysqlPool()
{
    bool res = DestroyPool();
    if(!res)
    {
        //»’÷æ
    }
}

bool Intergrator::CMysqlPool::CreatePool(std::string host,std::string name,std::string passwd,std::string database)
{
    //º”À¯
    Lock.lock();
    sname = name;
    spasswd = passwd;
    sdatabase = database;
    shost = host;
    for(int i=0;i<m_poolnum;i++)
    {
        Conn* con = new Conn(); 
        con->mysql = new CMysql();
        con->bUsed = false;
        if(con->mysql->Connect(shost,sname,spasswd,sdatabase))
        {
            Pool.insert(pair<int, Conn*>(i,con));
        }
        else
        {
            delete con->mysql;
            delete con;
        }
        
    }
    Lock.unlock();
    return true;
}


bool Intergrator::CMysqlPool::DestroyPool()
{
    return true;
}

Intergrator::CMysql* Intergrator::CMysqlPool::getConnect()
{
    auto iter = Pool.begin();
    for(;iter != Pool.end();iter++)
    {
        if(iter->second->bUsed == false)
        {
            iter->second->bUsed = true;
            cout<<"num:"<<iter->first<<endl;
            return iter->second->mysql;
            
        }
    }
    return NULL;
}

bool Intergrator::CMysqlPool::FreeConnect(CMysql* mysql)
{
    if(mysql == NULL)
    {
        return false;
    }
    auto iter = Pool.begin();
    for(;iter != Pool.end();iter++)
    {
        Conn* csql = iter->second;
        if(csql->mysql == mysql)
        {
            csql->bUsed = false;
            break;
        }

    }
    return true;
}