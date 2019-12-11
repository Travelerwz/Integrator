#pragma once 
#include <iostream>
#include <mysql/mysql.h>
#include <string.h>
#include "Cjson.h"
using namespace std;

class CMysql
{
public:
    CMysql();
    ~CMysql();
    bool Connect(string host,string user,string passwd,string database);
    bool Del(string sql);
    bool Query(string sql);
    string Query(string sql,string id);
    string Query_json(string sql);
private:
    MYSQL mysql;
    Json::Value root;
    Json::Value emlue;
    Json::Value array;
    Json::FastWriter fast_wariter;
};