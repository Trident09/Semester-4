#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// Function to compute the inverse modulo of a number 'a' modulo 'm'
int inverse_modulo(int a, int m)
{
    int m0 = m, t, q;
    int x0 = 0, x1 = 1;

    if (m == 1)
        return 0;

    // Apply extended Euclid Algorithm
    while (a > 1)
    {
        q = a / m;
        t = m;

        // m is remainder now, process same as euclid's algo
        m = a % m;
        a = t;

        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }

    // Make x1 positive
    if (x1 < 0)
        x1 += m0;

    return x1;
}

// Function to encrypt the message
string encrypt(string message, string key, int b)
{
    // Convert message to uppercase
    transform(message.begin(), message.end(), message.begin(), ::toupper);

    // Encrypt message
    string encrypted_message = "";
    for (char c : message)
    {
        if (c >= 'A' && c <= 'Z')
        {
            int x = c - 'A';
            int y = (x * b) % 26;
            char encrypted_char = key[y];
            encrypted_message += encrypted_char;
        }
        else
        {
            encrypted_message += c;
        }
    }

    return encrypted_message;
}

// Function to decrypt the message
string decrypt(string encrypted_message, string key, int b)
{
    // Convert message to uppercase
    transform(encrypted_message.begin(), encrypted_message.end(), encrypted_message.begin(), ::toupper);

    // Decrypt message
    string decrypted_message = "";
    for (char c : encrypted_message)
    {
        if (c >= 'A' && c <= 'Z')
        {
            int y = key.find(c);
            int x = (y * inverse_modulo(b, 26)) % 26;
            char decrypted_char = x + 'A';
            decrypted_message += decrypted_char;
        }
        else
        {
            decrypted_message += c;
        }
    }

    return decrypted_message;
}

int main()
{
    string message;
    string key;
    int b;
    int choice;

    // Get message, key, and multiplier from user
    cout << "Enter message: ";
    getline(cin, message);
    cout << "Enter key: ";
    getline(cin, key);
    cout << "Enter multiplier: ";
    cin >> b;

    // Ensure key is 26 letters long and contains only uppercase letters
    if (key.length() != 26)
    {
        cout << "Error: key must be 26 letters" << endl;
        return 1;
    }

    if (!all_of(key.begin(), key.end(), ::isupper))
    {
        transform(key.begin(), key.end(), key.begin(), ::toupper);
    }

    // Compute inverse of multiplier modulo 26
    int inverse = inverse_modulo(b, 26);

    // Display menu
    cout << "1. Encrypt message" << endl;
    cout << "2. Decrypt message" << endl;
    cout << "Enter choice: ";
    cin >> choice;

    // Process choice
    if (choice == 1)
    {
        // Encrypt message
        string encrypted_message = encrypt(message, key, b);
        cout << "Encrypted message: " << encrypted_message << endl;
    }
    else if (choice == 2)
    {
        // Decrypt message
        string decrypted_message = decrypt(message, key, b);
        cout << "Decrypted message: " << decrypted_message << endl;
    }
    else
    {
        cout << "Error: invalid choice" << endl;
        return 1;
    }
    return 0;
}