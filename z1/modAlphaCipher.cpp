#include "modAlphaCipher.h"
modAlphaCipher::modAlphaCipher(wstring skey)
{
    for (unsigned i=0; i<numAlpha.size(); i++) {
        alphaNum[numAlpha[i]]=i;
    }
    key = convert(get_val_kl(skey));
}
wstring modAlphaCipher::encrypt(const wstring& open_text)
{
    vector<int> work = convert(get_val_txt(open_text));
    for(unsigned i=0; i < work.size(); i++) {
        work[i] = (work[i] + key[i % key.size()]) % alphaNum.size();
    }
    return convert(work);
}
wstring modAlphaCipher::decrypt(const wstring& cipher_text)
{
    vector<int> work = convert(get_val_txt(cipher_text));
    for(unsigned i=0; i < work.size(); i++) {
        work[i] = (work[i] + alphaNum.size() - key[i % key.size()]) % alphaNum.size();
    }
    return convert(work);
}
inline vector<int> modAlphaCipher::convert(const wstring& s)
{
    vector<int> result;
    for(auto c:s) {
        result.push_back(alphaNum[c]);
    }
    return result;
}
inline wstring modAlphaCipher::convert(const vector<int>& v)
{
    wstring result;
    for(auto i:v) {
        result.push_back(numAlpha[i]);
    }
    return result;
}
inline wstring modAlphaCipher::get_val_kl(const wstring & s)
{ 
    locale loc("ru_RU.UTF-8");
    locale::global(loc);
    if (s.empty())
        throw exc(string("вы ввели пустой ключ."));
    wstring wst = s;
    for (auto & el : wst) {
        if (iswalpha(el)==0) {
            throw exc(string("в вашем ключе присутствуют недопустимые символы."));
            break;
        }
        if (iswlower(el)) {
        el = towupper(el);
        }
    }
    return wst;
}

inline wstring modAlphaCipher::get_val_txt(const wstring & s)
{
    locale loc("ru_RU.UTF-8");
    locale::global(loc);
    if (s.empty())
        throw exc(string("Был введен пустой текст."));
    wstring wst = s;
    for (auto & el : wst) {
        if (iswalpha(el)==0) {
            throw exc (string("Текст должен состоять только из строки русских букв."));
            break;
        }
        if (iswlower(el)) {
        el = towupper(el);
        }
    }
    return wst;
}
