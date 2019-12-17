#include "CBase64.h"

Intergrator::CBase64::CBase64()
{
    bptr = NULL;
}

Intergrator::CBase64::~CBase64()
{}

std::string Intergrator::CBase64::Base64_encode(std::string in)
{
    size_t size = 0;
    if(in.empty())
    {
        std::cout<<"in is empty"<<std::endl;
        return NULL;
    }
    b64 = BIO_new(BIO_f_base64());
    bio = BIO_new(BIO_s_mem());
    bio = BIO_push(b64,bio);
    BIO_write(bio,in.c_str(),in.length());
    BIO_flush(bio);
    BIO_get_mem_ptr(bio,&bptr);
    char* out = new char[2048];
    memset(out,0,strlen(out));
    memcpy(out,bptr->data,bptr->length);
    out[bptr->length] = '\0';
    std::string res = out;
    res = SubstrLast(res);
    delete out;
    return res;
}

std::string Intergrator::CBase64::Replace_All(std::string str)
{
    int b = 0;
    if(str.empty())
    {
        std::cout<<"str is empty"<< std::endl;
        return NULL;
    }
    while((b=str.find("\n"))!=-1)
    {
        str.replace(b,1,"*");
    }
    return str;
}
std::string Intergrator::CBase64::SubstrLast(std::string str)
{
    if(str.empty())
    {
        std::cout<<"str is empty"<<std::endl;
        return NULL;
    }
    str = str.substr(0,str.length()-1);
    return str;
}