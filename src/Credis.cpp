#include "Credis.h"

Credis::Credis()
{
    conn = redisConnect("127.0.0.1",6379);
    if(NULL != conn && conn->err)
    {
        perror("redisConnect");
        std::cout<<"Connect is error"<<std::endl;
    }
    perror("redisConnect");
}

Credis::~Credis()
{
    redisFree(conn);
}

bool Credis::Command_set(std::string str)
{
    if(str.empty())
    {
        std::cout<<"set command is error"<<std::endl;
        return false;
    }
    std::cout<<"str:"<<str<<std::endl;
    redisReply* replay = (redisReply*)redisCommand(conn,str.c_str());
    if(replay->type == REDIS_REPLY_ERROR)
    {
        std::cout<<replay->str<<std::endl;
        std::cout<<"redisCommand is error"<<std::endl;
        return false;
    }
    freeReplyObject(replay);
    return true;
}

bool Credis::Command_set(std::string key,std::string value)
{
    if(key.empty())
    {
        std::cout<<"key not NULL"<<std::endl;
        return false;
    }
    std::string cmd = "set ";
    cmd = cmd+key+" \'"+value+"\'";
    std::cout<<"cmd:"<<cmd<<std::endl;
    redisReply* replay = (redisReply*)redisCommand(conn,cmd.c_str());
    
    if(replay->type == REDIS_REPLY_ERROR)
    {
        std::cout<<replay->str<<std::endl;
        std::cout<<"redisCommand is error"<<std::endl;
        return false;
    }
    freeReplyObject(replay);
    return true;
}

std::string Credis::Command_get(std::string str)
{ 
    if(str.empty())
    {
        std::cout<<"set command is error"<<std::endl;
        return NULL;
    }
    redisReply* replay = (redisReply*)redisCommand(conn,str.c_str());
        if(replay->type == REDIS_REPLY_ERROR)
    {
        std::cout<<replay->str<<std::endl;
        std::cout<<"redisCommand is error"<<std::endl;
        return NULL;
    }
    std::string res = replay->str;
    freeReplyObject(replay);
    return res;
}

bool Credis::Command_del(std::string key)
{
    if(key.empty())
    {
        std::cout<<"key is NULL"<<std::endl;
        return false;
    }
    std::string cmd = "del";
    cmd = cmd + " " + key;
    redisReply* replay = (redisReply*)redisCommand(conn,cmd.c_str());
    freeReplyObject(replay);
    return true;
}

bool Credis::Command_jsonset(std::string json_string,std::string sql)
{
    if(json_string.empty())
    {
        std::cout<<"json_string is NULL"<<std::endl;
        return false;
    }
    std::string id_num,name;
    if(reader.parse(json_string,root))
    {
        for(unsigned int i=0;i<root[sql.c_str()].size();i++)
        {
            id_num = root[sql.c_str()][i]["id"].asString();
            name = root[sql.c_str()][i]["name"].asString();
            std::cout<<"id_num:"<<id_num<<std::endl;
            std::cout<<"name:"<<name<<std::endl;
        }
        
    }
    std::string res = bs.Base64_encode(sql);
    json_string = SubstrLast(json_string);
    bool result = Command_set(res,json_string);
    if(!result)
    {
        std::cout<<"Command_set is error"<<std::endl;
        return false;
    }
    return true;
}

std::string Credis::SubstrLast(std::string str)
{
    if(str.empty())
    {
        std::cout<<"str is empty"<<std::endl;
        return NULL;
    }
    str = str.substr(0,str.length()-1);
    return str;
}

