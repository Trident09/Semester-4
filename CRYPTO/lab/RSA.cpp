#include <iostream>
#include <math.h>
#include <string>

using namespace std;

int gcd(int a, int h)
{
    int temp;
    while (1)
    {
        temp = a % h;
        if (temp == 0)
            return h;
        a = h;
        h = temp;
    }
}

int main()
{
    int p, q, n;
    cout << "Enter 2 prime numbers or their products :" << endl;
    cout << "1. Enter p & q " << endl;
    cout << "2. Enter n" << endl;
    int choice;
    cin >> choice;
    if (choice == 1)
    {
        cout << "Enter p & q : ";
        cin >> p >> q;

        // check if the numbers are prime
        if (gcd(p, q) != 1)
        {
            cout << "p & q are not prime" << endl;
            return 0;
        }
        n = p * q;
        cout << "n = " << n << endl;
    }
    else if (choice == 2)
    {
        cout << "Enter n : ";
        cin >> n;
        for (int i = 2; i < n; i++)
        {
            if (n % i == 0)
            {
                p = i;
                q = n / i;
                break;
            }
        }
        cout << "p = " << p << endl;
        cout << "q = " << q << endl;
    }
    else
    {
        cout << "Invalid choice" << endl;
        return 0;
    }

    int phi = (p - 1) * (q - 1);

    cout << "phi = " << phi << endl;

    int e;
    cout << "Enter a number e such that gcd(phi,e) = 1 & 1 < e < phi : ";
    cin >> e;

    while (e < phi)
    {
        if (gcd(e, phi) == 1)
            break;
        else
            e++;
    }

    int k = 2;
    double d = (1 + (k * phi)) / e;

    cout << "d = " << d << endl;

    int message;
    cout << "Enter the message : ";
    cin >> message;

    double cipher = pow(message, e);
    cipher = fmod(cipher, n);
    cout << "Cipher text : " << cipher << endl;

    double decrypted = pow(cipher, d);
    decrypted = fmod(decrypted, n);
    cout << "Decrypted text : " << decrypted << endl;

    return 0;
}