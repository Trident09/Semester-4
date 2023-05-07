#include <iostream>
#include <string>
#include <cryptopp/aes.h>
#include <cryptopp/modes.h>
#include <cryptopp/filters.h>

using namespace std;
using namespace CryptoPP;

int main()
{
    // Get the plaintext from the user
    string plaintext;
    cout << "Enter plaintext: ";
    getline(cin, plaintext);

    // Get the key from the user
    string key_str;
    cout << "Enter key: ";
    getline(cin, key_str);

    // Convert the key string to a byte array
    byte key[AES::DEFAULT_KEYLENGTH];
    memcpy(key, key_str.c_str(), AES::DEFAULT_KEYLENGTH);

    // Get the initialization vector from the user
    string iv_str;
    cout << "Enter initialization vector: ";
    getline(cin, iv_str);

    // Convert the initialization vector string to a byte array
    byte iv[AES::BLOCKSIZE];
    memcpy(iv, iv_str.c_str(), AES::BLOCKSIZE);

    // Create an AES encryption object with the key and IV
    CBC_Mode<AES>::Encryption encryption(key, sizeof(key), iv);

    // Encrypt the plaintext
    string ciphertext;
    StringSource(plaintext, true, new StreamTransformationFilter(encryption, new StringSink(ciphertext)));

    cout << "Ciphertext: " << ciphertext << endl;

    // Create an AES decryption object with the key and IV
    CBC_Mode<AES>::Decryption decryption(key, sizeof(key), iv);

    // Decrypt the ciphertext
    string decryptedtext;
    StringSource(ciphertext, true, new StreamTransformationFilter(decryption, new StringSink(decryptedtext)));

    cout << "Decryptedtext: " << decryptedtext << endl;

    return 0;
}
