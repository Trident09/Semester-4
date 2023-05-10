/*
    (A * B) % M = 1
    A and M are coprime
*/

#include <iostream>
#include <bits/stdc++.h>
#define int long long
const int N = 1e5 + 2, MOD = 1e9 + 7;

using namespace std;

// ax + by = gcd(a, b)
// ax + 0 = gcd(a, 0) = a
// gcd(d, 0) = d
// y = 0

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

int multiplicativeInverse(int a, int m)
{
    triplet temp = extendedEuclid(a, m);
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
    int a, m;
    cout << "Enter a: ";
    cin >> a;
    cout << "Enter m: ";
    cin >> m;

    int inv = multiplicativeInverse(a, m);
    if (inv == -1)
    {
        cout << "No inverse exists" << endl;
    }
    else
    {
        cout << "Multiplicative inverse of " << a << " modulo " << m << " is " << inv << endl;
    }

    return 0;
}