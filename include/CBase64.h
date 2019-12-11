#pragma once

#include <iostream>
#include <openssl/bio.h>
#include <openssl/evp.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/pem.h>

class CBase64
{
public:
    CBase64();
    ~CBase64();
    std::string Base64_encode(std::string in);
    std::string Replace_All(std::string str);
    std::string SubstrLast(std::string str);
private:
    BIO *b64,*bio;
    BUF_MEM *bptr;
};

