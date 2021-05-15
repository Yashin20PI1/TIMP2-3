#include "Shifr.h"
Shifr::Shifr(int a)
{
    key=a;
}
wstring Shifr::enshifr(Shifr obj, wstring& data)
{
    int spis = 0;
    int dlina = data.size();
    const int lines= ((data.size()-1)/obj.key)+1;
    wchar_t array[lines][obj.key];
    for (int i = 0; i <lines; i++) {
        for (int j = 0; j < obj.key; j++ ) {
            if (spis < dlina) {
                array[i][j] = data[spis];
                spis++;
            } else {
                array[i][j] =' ';
              
            }
        }
    }
    data.clear();
    int check=0;
    for (int i = 0; i < obj.key; i++) {
        for (int j = 0; j < lines; j++ ) {
            if (check <= dlina) {
                data.push_back(array[j][i]);
                check++;
            }
        }
    }
    data[check] = '\0';
    return data;
}
wstring Shifr::decshifr(Shifr obj, wstring &data)
{
    int spis = 0;
    int dlina = data.size();
    const int lines= ((data.size()-1)/obj.key)+1;
    wchar_t array[lines][obj.key];
    for (int i = 0; i < obj.key; i++) {
        for (int j = 0; j < lines; j++ ) {
            if (spis < dlina) {
                array[j][i] = data[spis];
                spis++;
            } else {
                array[j][i] =' ';
                spis++;
            }
        }
    }
    data.clear();
    int check=0;
    for (int i = 0; i < lines; i++) {
        for (int j = 0; j < obj.key; j++ ) {
            if (check < dlina) {
                data.push_back(array[i][j]);
                check++;
            }
        }
    }
    data[check] = '\0';
    return data;
}
