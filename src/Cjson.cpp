#include "Cjson.h"

Cjson::Cjson()
{

}
Cjson::~Cjson()
{

}

void Cjson::Output(Json::Value Root)
{
    std::cout<<"JSON:"<<fast_wariter.write(Root)<<std::endl;
    return ;
}

std::string Cjson::Combination(std::string key,std::string value)
{
    root[key.c_str()] = value.c_str();
    return fast_wariter.write(root);
}
