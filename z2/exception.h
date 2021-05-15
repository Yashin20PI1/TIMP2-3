#pragma once
#include <stdexcept>
#include <string>

using namespace std;
class exc : public invalid_argument
{

public:
    exc (const string & error):invalid_argument(error) {};
        static int pr_kl ( const wstring &data,const string str_key );
        static int pr_st ( const string data );
    };
