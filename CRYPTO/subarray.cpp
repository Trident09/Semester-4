#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    int a[n];
    cout << "Enter the elements of the array: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter element " << i + 1 << " : ";
        cin >> a[i];
    }

    int arr[n];
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum = 0;
        for (int j = 0; j < i + 1; j++)
        {
            sum = sum + a[j];
        }
        arr[i] = sum;
    }
    cout << "The sum array is: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    int mod;
    cout << "Enter the modulus: ";
    cin >> mod;

    cout << "The sub array of sum modulus is: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] % mod << " ";
    }
    cout << endl;
    return 0;
}