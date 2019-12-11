#include "Cmd5.h"

std::string CMD5::Make_Md5(std::string str)
{
    if(str.empty())
    {
        return NULL;
    }
    std::string res ;
    unsigned char*dst = new unsigned char[1024];
    MD5((const unsigned char*)str.c_str(),str.length(),dst);
    res = (char*)dst;
    delete[] dst;
    return res;
}
