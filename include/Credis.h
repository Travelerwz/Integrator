#pragma once
#include <iostream>
#include <hiredis/hiredis.h>
#include "Cjson.h"
#include "Cmd5.h"
#include "CBase64.h"

namespace Intergrator{
class Credis
{
public:
    Credis();
    ~Credis();
    bool Command_set(std::string str);
    bool Command_set(std::string key,std::string value);
    bool Command_jsonset(std::string json_string,std::string sql);
    bool Command_jsonMap(std::string json_string,std::string sql);
    bool Command_del(std::string key);
    std::string Command_get(std::string str);
    std::string SubstrLast(std::string str);

private:
    redisContext *conn;
    Json::Value root;
    Json::Reader reader;
    CBase64 bs;
};
}