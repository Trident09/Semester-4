#include <iostream>
#include "bits/stdc++.h"

using namespace std;
#define int long long
const int N = 1e5 + 5, MOD = 1e9 + 7;
// ax + by = gcd(a, b)
//gcd(d, o) = d;

// ax + 0 = 0 -> x + 1
//y = 0
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

signed main()
{
    int a, b;
    cout << "Enter a and b: ";
    cin >> a >> b;

    triplet ans = extendedEuclid(a, b);
    cout << "gcd = " << ans.gcd << endl;
    cout << "x = " << ans.x << endl;
    cout << "y = " << ans.y << endl;
}