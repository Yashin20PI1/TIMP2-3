#include <iostream>
#include "modAlphaCipher.h"
#include "exception.h"
#include <codecvt>
using namespace std;
int main ()
{
    locale loc("ru_RU.UTF-8");
    locale::global(loc);
    bool isTrue = true;
    wstring rejim,wstr,wstr_kl;
    cout << "Здравствуйте! Время что-нибудь зашифровать/расшифровать!" << endl;
    cout << "Режимы работы программы:\nencode - режим шифрования русскоязычных сообщений методом Гронсвельда.\ndecode - режим расшифрования русскоязычных сообщений методом Гронсвельда.\nexit - режим завершения программы.\n" << endl;

    do {
        cout << "Укажите режим работы:";
        wcin >> rejim;
        if (rejim == L"encode") {
            cout << "Введите строку для шифрования:";
            wcin.get();getline(wcin,wstr);
            cout << "Введите ключ:";
            getline(wcin,wstr_kl);
            try {
                modAlphaCipher cipher(wstr_kl);
                wstring cipherText = cipher.encrypt(wstr);
                wstring_convert<codecvt_utf8<wchar_t>, wchar_t> codec;
                cout<<codec.to_bytes(cipherText)<<endl;
            } catch (exc & ex) {

                cout <<  ex.what() << endl;

            }
        }
        if (rejim == L"decode") {
            cout << "Введите строку для расшифрования:";
            wcin.get();getline(wcin,wstr);
            cout << "Введите ключ:"; getline(wcin,wstr_kl);
            try {
                modAlphaCipher cipher(wstr_kl);
                wstring OpenText = cipher.decrypt(wstr);
                wstring_convert<codecvt_utf8<wchar_t>, wchar_t> codec;
                cout<<codec.to_bytes(OpenText)<<endl;
            } catch (exc & ex) {

                cout <<ex.what() << endl;
            }
        }
        if (rejim == L"exit") {
            cout << "Программа завершила работу." << endl;
            isTrue = false;
            break;
        }
        
    } while (isTrue != false);
    return 0;

}
