#include <UnitTest++/UnitTest++.h>
#include "/home/student/tlab2/z2/Shifr.h"
#include "/home/student/tlab2/z2/Shifr.cpp"
#include "/home/student/tlab2/z2/exception.h"
#include "/home/student/tlab2/z2/exception.cpp"
SUITE(enshifr)
{
    const int key = 3;
    Shifr test(key);
    TEST(BOLSHIE_BUKV) {
        wstring open_text = L"НАРКОТ";
        wstring result_correct = L"НКАОРТ";
        CHECK_EQUAL(true, result_correct == test.enshifr(test,open_text));
    }
    TEST(mahonkie_bukovki) {
        wstring open_text = L"наркот";
        wstring result_correct = L"нкаорт";
        CHECK_EQUAL(true, result_correct == test.enshifr(test,open_text));
    }
    TEST(BIG_L) {
        wstring open_text = L"FISTINGISTHREEHUNDREDBUCKS";
        wstring result_correct = L"FTGTEURBKIIIHENEUSSNSRHDDC ";
        CHECK_EQUAL(true, result_correct == test.enshifr(test,open_text));
    }
    TEST(mini_l) {
        wstring open_text = L"fistingisthreehundredbucks";
        wstring result_correct = L"ftgteurbkiiiheneussnsrhddc ";
        CHECK_EQUAL(true, result_correct == test.enshifr(test,open_text));
    }
    TEST(mix_bukv_an_letters) {
        wstring open_text = L"мiкsуem";
        wstring result_correct = L"мsmiу кe";
        CHECK_EQUAL(true, result_correct == test.enshifr(test,open_text));
    }
    TEST(special) {
        wstring open_text = L"*&^%$#@";
        wstring result_correct = L"*%@&$ ^#";
        CHECK_EQUAL(true, result_correct == test.enshifr(test,open_text));
    }
    TEST(cifri) {
        wstring open_text = L"88005553535";
        wstring result_correct = L"80538535055 ";
        CHECK_EQUAL(true, result_correct == test.enshifr(test,open_text));
    }
    TEST(all_simbols) {
        wstring open_text = L"all приколы 777 *?%)(";
        wstring result_correct = L"a ил7 %lпкы7*)lро 7?(";
        CHECK_EQUAL(true, result_correct == test.enshifr(test,open_text));
    }
}
SUITE(decshifr)
{
    const int key = 3;
    Shifr test(key);
    TEST(BOLSHIE_BUKV) {
        wstring cipher_text = L"НКАОРТ";
        wstring result_correct = L"НАРКОТ";
        CHECK_EQUAL(true, result_correct == test.decshifr(test,cipher_text));
    }
    TEST(mahonkie_bukovki) {
        wstring cipher_text = L"нкаорт";
        wstring result_correct = L"наркот";
        CHECK_EQUAL(true, result_correct == test.decshifr(test,cipher_text));
    }
    TEST(BIG_L) {
        wstring cipher_text = L"FTGTEURBKIIIHENEUSSNSRHDDC";
        wstring result_correct = L"FISTINGISTHREEHUNDREDBUCKS";
        CHECK_EQUAL(true, result_correct == test.decshifr(test,cipher_text));
    }
    TEST(mini_l) {
        wstring cipher_text = L"ftgteurbkiiiheneussnsrhddc";
        wstring result_correct = L"fistingisthreehundredbucks";
        CHECK_EQUAL(true, result_correct == test.decshifr(test,cipher_text));
    }
    TEST(mix_bukv_an_letters) {
        wstring cipher_text = L"мsmiу кe";
        wstring result_correct = L"мiкsуem ";
        CHECK_EQUAL(true, result_correct == test.decshifr(test,cipher_text));
    }
    TEST(special) {
        wstring cipher_text = L"*%@&$ ^#";
        wstring result_correct = L"*&^%$#@ ";
        CHECK_EQUAL(true, result_correct == test.decshifr(test,cipher_text));
    }
    TEST(cifri) {
        wstring cipher_text = L"80538535055";
        wstring result_correct = L"88005553535";
        CHECK_EQUAL(true, result_correct == test.decshifr(test,cipher_text));
    }
    TEST(all_simbols) {
        wstring cipher_text = L"a ил7 %lпкы7*)lро 7?(";
        wstring result_correct = L"all приколы 777 *?%)(";
        CHECK_EQUAL(true, result_correct == test.decshifr(test,cipher_text));
    }
}
SUITE(excst)
{
   TEST(st_rus) {
        CHECK_EQUAL(0, exc::pr_st("самыйрусский"));
    }
    TEST(st_eng) {
        CHECK_EQUAL(0, exc::pr_st("pendoski"));
    }
    TEST(mix_st_rus_eng) {
        CHECK_EQUAL(0, exc::pr_st("zachem english если есть русский"));
    }
    TEST(all_simbols) {
        CHECK_EQUAL(0, exc::pr_st("opana-опана, мы /юби/и kab{}n{}67859403?"));
    }
    TEST(pustota) {
        CHECK_THROW(exc::pr_st(""),exc);
    }
}

SUITE(exckl)
{
    wstring test = L"kotiki";
    TEST(praviln_kl) {
        CHECK_EQUAL(0, exc::pr_kl(test,"3"));
    }
    TEST(non_nature_kl) {
        CHECK_THROW(exc::pr_kl(test,"-500"),exc);
    }
    TEST(mix_kl) {
        CHECK_THROW(exc::pr_kl(test,"(ya nevivozhu)666777"),exc);
    }
    TEST(pustota_kl) {
        CHECK_THROW(exc::pr_kl(test,""),exc);
    }
}
int main()
{
    return UnitTest::RunAllTests();
}
