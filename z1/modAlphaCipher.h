#pragma once
#include <vector>
#include <string>
#include <map>
#include <locale>
#include <cctype>
#include "exception.h"
using namespace std;
class modAlphaCipher
{
private:
    wstring numAlpha = L"АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";//алфавит по порядку
    map <char,int> alphaNum; //ассоциативный массив "номер по символу"
    vector <int> key; //ключ
    vector<int> convert(const wstring& s); //преобразование строка-вектор
    wstring convert(const vector<int>& v); //преобразование вектор-строка
    wstring get_val_kl(const wstring & s);
    wstring get_val_txt(const wstring & s);

public:
    modAlphaCipher()=delete; //запретим конструктор без параметров
    modAlphaCipher(wstring skey); //конструктор для установки ключа
    wstring encrypt(const wstring& open_text); //зашифрование
    wstring decrypt(const wstring& cipher_text);//расшифрование
};
