#include <iostream>
#include <cryptopp/aes.h>
#include <cryptopp/modes.h>
#include <cryptopp/filters.h>

using namespace CryptoPP;

int main()
{
    byte key[AES::DEFAULT_KEYLENGTH] = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f};
    byte iv[AES::BLOCKSIZE] = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f};
    std::string plaintext = "Hello, world!";
    std::string ciphertext;

    // Encryption
    CBC_Mode<AES>::Encryption encryption(key, sizeof(key), iv);
    StringSource(plaintext, true, new StreamTransformationFilter(encryption, new StringSink(ciphertext)));
    std::cout << "Plaintext: " << plaintext << std::endl;
    std::cout << "Ciphertext: " << ciphertext << std::endl;

    // Decryption
    std::string decryptedtext;
    CBC_Mode<AES>::Decryption decryption(key, sizeof(key), iv);
    StringSource(ciphertext, true, new StreamTransformationFilter(decryption, new StringSink(decryptedtext)));
    std::cout << "Decrypted text: " << decryptedtext << std::endl;

    return 0;
}
