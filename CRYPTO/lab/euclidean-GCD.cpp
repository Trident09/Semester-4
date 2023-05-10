#include <iostream>
using namespace std;

int gcd(int a, int b)
{
    int r;
    while (b != 0)
    {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main()
{
    int num1, num2;
    cout << "Enter two numbers: ";
    cin >> num1 >> num2;
    int result = gcd(num1, num2);
    cout << "GCD of " << num1 << " and " << num2 << " is " << result << endl;
    return 0;
}