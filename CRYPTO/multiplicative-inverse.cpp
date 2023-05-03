#include <iostream>

using namespace std;

int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}

int modularMultiplicativeInverse(int a, int m)
{
    int g = gcd(a, m);
    if (g != 1)
    {
        return -1; // inverse does not exist
    }
    int m0 = m, t, q;
    int x0 = 0, x1 = 1;
    if (m == 1)
    {
        return 0;
    }
    while (a > 1)
    {
        q = a / m;
        t = m;
        m = a % m;
        a = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }
    if (x1 < 0)
    {
        x1 += m0;
    }
    return x1;
}

int main()
{
    int a, m;
    cout << "Enter the value of a: ";
    cin >> a;
    cout << "Enter the value of m: ";
    cin >> m;
    int inverse = modularMultiplicativeInverse(a, m);
    if (inverse == -1)
    {
        cout << "The modular multiplicative inverse of " << a << " modulo " << m << " does not exist." << endl;
    }
    else
    {
        cout << "The modular multiplicative inverse of " << a << " modulo " << m << " is " << inverse << endl;
    }
    return 0;
}
