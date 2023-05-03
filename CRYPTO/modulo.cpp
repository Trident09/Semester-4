#include <iostream>
using namespace std;

int main()
{
    int a, b, c;
    cout << "Enter two numbers: ";
    cin >> a >> b;

    int sum = a + b;
    cout << "Sum of the two numbers is: " << sum << endl;

    cout << "Enter modulo number: ";
    cin >> c;
    // finding remainder without using modulo operation
    int rem;
    // find a multiple of c which is smaller than sum
    int multiplier = sum / c;
    if (multiplier < 0)
    {
        multiplier = multiplier - 1;
    }
    int multiple = multiplier * c;
    rem = sum - multiple;
    if (multiplier < 0)
    {
        rem = 0 - rem;
    }
    cout << "Remainder is: " << rem << endl;
    return 0;
}