#include iostream
#include string
#include opensslaes.h

stdstring aes_sifrele(stdstring metin, const unsigned char anahtar, const unsigned char iv) {
    AES_KEY sifre;
    AES_set_encrypt_key(anahtar, 128, &sifre);

    int uzunluk = ((metin.length() + AES_BLOCK_SIZE)  AES_BLOCK_SIZE)  AES_BLOCK_SIZE;
    char sifreli_metin = new char[uzunluk];
    AES_cbc_encrypt((unsigned char)metin.c_str(), (unsigned char)sifreli_metin, metin.length(), &sifre, iv, AES_ENCRYPT);

    stdstring sifreli_metin_str(sifreli_metin, uzunluk);
    delete[] sifreli_metin;

    return sifreli_metin_str;
}

stdstring aes_cozer(stdstring sifreli_metin, const unsigned char anahtar, const unsigned char iv) {
    AES_KEY sifre;
    AES_set_decrypt_key(anahtar, 128, &sifre);

    int uzunluk = sifreli_metin.length();
    char cozulmus_metin = new char[uzunluk];
    AES_cbc_encrypt((unsigned char)sifreli_metin.c_str(), (unsigned char)cozulmus_metin, uzunluk, &sifre, iv, AES_DECRYPT);

    stdstring cozulmus_metin_str(cozulmus_metin, uzunluk);
    delete[] cozulmus_metin;

    return cozulmus_metin_str;
}

int main() {
    stdstring metin;
    stdstring anahtar = 0123456789abcdef;  128 bit anahtar
    stdstring iv = fedcba9876543210;  128 bit initialization vektörü

    stdcout  Metini girin ;
    stdgetline(stdcin, metin);

    stdstring sifreli_metin = aes_sifrele(metin, (const unsigned char)anahtar.c_str(), (const unsigned char)iv.c_str());
    stdcout  Sifreli metin   sifreli_metin  stdendl;

    stdstring cozulmus_metin = aes_cozer(sifreli_metin, (const unsigned char)anahtar.c_str(), (const unsigned char)iv.c_str());
    stdcout  Orijinal metin   cozulmus_metin  stdendl;

    return 0;
}
