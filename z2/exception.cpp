#include "exception.h"
int exc::pr_kl ( const wstring &data,const string str_key )
{
    int kluch;
    if (str_key.empty())
        throw exc("Пустой ключ.Ключ должен быть натуральным числом,не превышающим размера строки.");
    if (str_key.find_first_not_of("-0123456789",0)!=string::npos) {
        throw exc("Недопустимый ключ, ведь ключ должен быть натуральным числом,не превышающим размера строки.");
    }
    kluch = stoi(str_key);
    const int dlinastroki = data.size();
    if (kluch > dlinastroki-1 || kluch <= 0) {
        throw exc("Некорректный ключ,ведь ключ должен быть натуральным числом,не превышающим размера строки.");
    }
    return 0;
}
int exc::pr_st( const string data )
{
    if (data.size()==0)
        throw exc ("Пустая строка, что нехорошо.");
    return 0;
}
