#include <UnitTest++/UnitTest++.h>
#include "/home/student/tlab2/z1/modAlphaCipher.h"
#include "/home/student/tlab2/z1/modAlphaCipher.cpp"
#include "/home/student/tlab2/z1/exception.h"


SUITE(kl_tst) 
{
    TEST(BOLSHIE_BUKV) {
        modAlphaCipher test(L"АААААААААААЫЫЫЫЫЫЫЫЫЫЫЫЫ");
        CHECK(true);
    }

    TEST(malehenkie_bukovki) {
        modAlphaCipher test(L"гляньтешозамелочь");
        CHECK(true);
    }

    TEST(littleBig) {
        modAlphaCipher test(L"МиКсУеМ");
        CHECK(true);
    }
    TEST(iscluch_mix_num) {
        CHECK_THROW(modAlphaCipher test(L"дев04кас0с04ка"),exc);
    }
     TEST(iscluch_mix_probel) {
        CHECK_THROW(modAlphaCipher test(L"х й"), exc);
    }
     TEST(iscluch_mix_special_simbol) {
        CHECK_THROW(modAlphaCipher test(L"(.)(.)айтиэротик"),exc);
    }
    TEST(iscluch_pustota) {
        CHECK_THROW(modAlphaCipher test(L""), exc);
    }
   

   
}

struct KeyAB_fixture { // Для тестов шифрования и расшифрования
    modAlphaCipher * pointer;
    KeyAB_fixture()
    {
        pointer = new modAlphaCipher(L"ХЕХ");
    }
    ~KeyAB_fixture()
    {
        delete pointer;
    }
};

SUITE(enshifr) 
{
    TEST_FIXTURE(KeyAB_fixture, BOLSHIE_BUKV ) {
        wstring open_text = L"ОПАНА";
        wstring result_correct = L"ДФХГЕ";
        CHECK_EQUAL(true, result_correct == pointer->encrypt(open_text));
    }
    TEST_FIXTURE(KeyAB_fixture, malehenkie_bukovki ) {
        wstring open_text = L"опана";
        wstring result_correct = L"ДФХГЕ";
        CHECK_EQUAL(true, result_correct == pointer->encrypt(open_text));
    }
    TEST_FIXTURE(KeyAB_fixture, littleBig ) {
        wstring open_text = L"ОпАнАшОмОгЕм";
        wstring result_correct = L"ДФХГЕНДСДШЙВ";
        CHECK_EQUAL(true, result_correct == pointer->encrypt(open_text));
    }
    TEST_FIXTURE(KeyAB_fixture, iscluch_pustota ) {
        wstring open_text = L"";
        CHECK_THROW(pointer->encrypt(open_text),exc);
    }
    TEST_FIXTURE(KeyAB_fixture,iscluch_mix_num) {
        wstring open_text = L"ЧИСЛОВОЙПРИКОЛ2";
        CHECK_THROW(pointer->encrypt(open_text),exc);
    }
    TEST_FIXTURE(KeyAB_fixture,iscluch_mix_special_simbol) {
        wstring open_text = L"АЕСЛИХ*Й";
        CHECK_THROW(pointer->encrypt(open_text),exc);
    }
    TEST_FIXTURE(KeyAB_fixture,iscluch_mix_probel) {
        wstring open_text = L"ИЗВИНИТЕ ШУТНИКА ТАМ ХОЙ";
        CHECK_THROW(pointer->encrypt(open_text),exc);
    }

}
SUITE(decshifr) 
{
    TEST_FIXTURE(KeyAB_fixture, BOLSHIE_BUKV) {
        wstring cipher_text = L"ДФХГЕ";
        wstring result_correct = L"ОПАНА";
        CHECK_EQUAL(true, result_correct == pointer->decrypt(cipher_text));
    }
    TEST_FIXTURE(KeyAB_fixture, malehenkie_bukovki) {
        wstring cipher_text = L"дфхге";
        wstring result_correct = L"ОПАНА";
        CHECK_EQUAL(true, result_correct == pointer->decrypt(cipher_text));
    }
    TEST_FIXTURE(KeyAB_fixture, littleBig) {
        wstring cipher_text = L"ДФХгЕнДсДШЙВ";
        wstring result_correct = L"ОПАНАШОМОГЕМ";
        CHECK_EQUAL(true, result_correct == pointer->decrypt(cipher_text));
    }

    TEST_FIXTURE(KeyAB_fixture, iscluch_pustota) {
        wstring cipher_text = L"";
        CHECK_THROW(pointer->decrypt(cipher_text),exc);
    }
    TEST_FIXTURE(KeyAB_fixture,iscluch_mix_num ) {
        wstring cipher_text = L"ЧИСЛОВОЙПРИКОЛ3";
        CHECK_THROW(pointer->decrypt(cipher_text),exc);
    }
    TEST_FIXTURE(KeyAB_fixture,iscluch_mix_special_simbol) {
        wstring cipher_text = L"АЕСЛИХ*Й";
        CHECK_THROW(pointer->decrypt(cipher_text),exc);
    }
    TEST_FIXTURE(KeyAB_fixture,iscluch_mix_probel) {
        wstring cipher_text = L"ИЗВИНИТЕ ШУТНИКА";
        CHECK_THROW(pointer->decrypt(cipher_text),exc);
    }
}
int main()
{
    return UnitTest::RunAllTests();
}
