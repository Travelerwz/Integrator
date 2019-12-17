#include "Cjson.h"

Intergrator::Cjson::Cjson()
{

}
Intergrator::Cjson::~Cjson()
{

}

void Intergrator::Cjson::Output(Json::Value Root)
{
    std::cout<<"JSON:"<<fast_wariter.write(Root)<<std::endl;
    return ;
}

std::string Intergrator::Cjson::Combination(std::string key,std::string value)
{
    root[key.c_str()] = value.c_str();
    return fast_wariter.write(root);
}
