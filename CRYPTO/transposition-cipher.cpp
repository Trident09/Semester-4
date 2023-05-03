#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string transpositionCipherEncrypt(string plaintext, int key) {
    // Add padding if necessary
    int padding = key - plaintext.length() % key;
    if (padding != key) {
        plaintext.append(padding, '_');
    }

    // Generate the transposition matrix
    int rows = plaintext.length() / key;
    char matrix[rows][key];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < key; j++) {
            matrix[i][j] = plaintext[i * key + j];
        }
    }

    // Read off the encrypted message by column
    string ciphertext = "";
    for (int j = 0; j < key; j++) {
        for (int i = 0; i < rows; i++) {
            ciphertext += matrix[i][j];
        }
    }

    return ciphertext;
}

string transpositionCipherDecrypt(string ciphertext, int key) {
    // Generate the transposition matrix
    int rows = ciphertext.length() / key;
    char matrix[rows][key];
    for (int j = 0; j < key; j++) {
        for (int i = 0; i < rows; i++) {
            matrix[i][j] = ciphertext[j * rows + i];
        }
    }

    // Read off the decrypted message by row
    string plaintext = "";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < key; j++) {
            plaintext += matrix[i][j];
        }
    }

    // Remove padding if necessary
    plaintext.erase(remove(plaintext.begin(), plaintext.end(), '_'), plaintext.end());

    return plaintext;
}

int main() {
    string message = "hello world";
    int key = 3;

    string ciphertext = transpositionCipherEncrypt(message, key);
    cout << "Ciphertext: " << ciphertext << endl;

    string plaintext = transpositionCipherDecrypt(ciphertext, key);
    cout << "Plaintext: " << plaintext << endl;

    return 0;
}