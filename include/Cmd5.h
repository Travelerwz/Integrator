#pragma once 
#include <openssl/md5.h>
#include <iostream>
namespace Intergrator{
class CMD5
{
public:
    std::string Make_Md5(std::string str);

};
}