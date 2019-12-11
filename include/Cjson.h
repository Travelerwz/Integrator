#pragma once
#include <json/json.h>
#include <iostream>

class Cjson
{
public:
    Cjson();
    ~Cjson();
    void Output(Json::Value Root);
    std::string Combination(std::string key,std::string value); 
private:
    Json::Value root;
    Json::Value element;
    Json::FastWriter fast_wariter;
};