#include <iostream>
#include <string>

using namespace std;

string encrypt(string message) {
    string cipherText = "";
    int length = message.length();
    for (int i = 0; i < length; i++) {
        char c = message[i];
        if (isalpha(c)) {
            if (isupper(c)) {
                cipherText += char((c - 'A' + 3) % 26 + 'A'); // shift 3 positions to the right
            }
            else {
                cipherText += char((c - 'a' + 3) % 26 + 'a'); // shift 3 positions to the right
            }
        }
        else {
            cipherText += c;
        }
    }
    return cipherText;
}

string decrypt(string cipherText) {
    string message = "";
    int length = cipherText.length();
    for (int i = 0; i < length; i++) {
        char c = cipherText[i];
        if (isalpha(c)) {
            if (isupper(c)) {
                message += char((c - 'A' + 23) % 26 + 'A'); // shift 3 positions to the left
            }
            else {
                message += char((c - 'a' + 23) % 26 + 'a'); // shift 3 positions to the left
            }
        }
        else {
            message += c;
        }
    }
    return message;
}

int main() {
    string message = "This is a message to be encrypted.";
    string cipherText = encrypt(message);
    cout << "Cipher text: " << cipherText << endl;
    cout << "Decrypted message: " << decrypt(cipherText) << endl;
    return 0;
}
