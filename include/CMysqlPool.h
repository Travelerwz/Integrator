#include <iostream>
#include <map>
#include "Cmysql.h"
#include "Catomic.h"

namespace Intergrator{
class CMysqlPool
{
public:
    struct Conn
    {
        CMysql* mysql;
        bool bUsed;
    };
    CMysqlPool(int num);
    ~CMysqlPool();
    bool CreatePool(std::string host,std::string name,std::string passwd,std::string database);
    bool DestroyPool();
    CMysql* getConnect();
    bool FreeConnect(CMysql* mysql);
    

private:
    bool bused;
    MYSQL mysql;
    std::map<int,Conn*>Pool;
    std::string sname;
    std::string spasswd;
    std::string sdatabase;
    std::string shost;
    int m_poolnum;
    MyLock Lock;
};
}