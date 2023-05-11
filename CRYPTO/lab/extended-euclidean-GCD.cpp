#include <iostream>
#include "bits/stdc++.h"

using namespace std;
#define int long long
const int N = 1e5 + 5, MOD = 1e9 + 7;

struct triplet
{
    int x, y, gcd;
};

triplet extendedEuclid(int a, int b)
{
    if (b == 0)
    {
        triplet ans;
        ans.gcd = a;
        ans.x = 1;
        ans.y = 0;
        return ans;
    }

    triplet smallAns = extendedEuclid(b, a % b);
    triplet ans;
    ans.gcd = smallAns.gcd;
    ans.x = smallAns.y;
    ans.y = smallAns.x - (a / b) * smallAns.y;
    return ans;
}

int multiplicativeInverse(int a, int b)
{
    triplet temp = extendedEuclid(a, b);
    if (temp.gcd != 1)
    {
        return -1;
    }
    else
    {
        return temp.x;
    }
}

signed main()
{
    cout << "Extended Euclidean Algorithm to find modular inverse of two numbers" << endl;
    int a, b;
    cout << "Enter a and b: ";
    cin >> a >> b;

    int inv = multiplicativeInverse(a, b);
    if (inv == -1)
    {
        cout << "No inverse exists" << endl;
    }
    else
    {
        cout << "Multiplicative inverse of " << a << " modulo " << b << " is " << inv << endl;
    }

    triplet ans = extendedEuclid(a, b);
    cout << "gcd = " << ans.gcd << endl;
    cout << "s = " << ans.x << endl;
    cout << "t = " << ans.y << endl;
}