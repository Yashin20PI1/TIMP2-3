#include "Shifr.h"
#include <iostream>
#include "exception.h"
#include <locale>
#include <codecvt>
int main()
{
    bool isTrue = true;
    string rejim,str,str_kl;
    cout << "Здравствуйте! Время что-нибудь зашифровать/расшифровать c помощью шифра табличной маршрутной перестановки." << endl;
    cout << "Режимы работы программы:\nencode - режим шифрования.\ndecode - режим расшифрования.\nexit - режим завершения программы.\n" << endl;

    do {
        locale loc("ru_RU.UTF-8");
        locale::global(loc);
        cout << "Укажите режим работы:";
        getline(cin,rejim);
        if (rejim == "encode") {
            cout << "Введите строку для шифрования:";
            getline(cin, str);
            try {
                exc::pr_st(str);
                cout << "Введите ключ:";
                getline(cin, str_kl);
                wstring_convert<codecvt_utf8<wchar_t>, wchar_t> codec;
                wstring wstren = codec.from_bytes(str);
                exc::pr_kl(wstren, str_kl);
                int key = stoi(str_kl);
                Shifr encode(key);
                cout<<codec.to_bytes(encode.enshifr(encode,wstren))<<endl;

            } catch(exc & ex) {
                cout<<ex.what()<<endl;
            }
        }
        if (rejim == "decode") {
            cout << "Введите строку для расшифрования:";
            getline(cin, str);
            try {
                exc::pr_st(str);
                cout << "Введите ключ:";
                getline(cin, str_kl);
                wstring_convert<codecvt_utf8<wchar_t>, wchar_t> codec;
                wstring wstren = codec.from_bytes(str);
                exc::pr_kl(wstren, str_kl);
                int key = stoi(str_kl);
                Shifr dec(key);
                cout<<codec.to_bytes(dec.decshifr(dec,wstren))<<endl;

            } catch(exc & ex) {
                cout<<ex.what()<<endl;
            }
        }
        if (rejim == "exit") {
            cout << "Программа завершила работу." << endl;
            isTrue = false;
            break;
        }
    } while (isTrue != false);
    return 0;
}
