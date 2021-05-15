#pragma once
#include <stdexcept>
#include <string>
using namespace std;
class exc : public invalid_argument
{
public:
  exc(const string & error) : invalid_argument(error){};
   
};
