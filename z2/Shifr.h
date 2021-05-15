#pragma once
#include <string>
#include <vector>
#include <iostream>
using namespace std;
class Shifr
{
private:
    int key;
public:
    Shifr() = delete;
    Shifr(int a);
    wstring enshifr(Shifr key, wstring &data);
    wstring decshifr (Shifr key, wstring &data);
};