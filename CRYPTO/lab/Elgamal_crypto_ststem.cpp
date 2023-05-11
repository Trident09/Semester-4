#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
struct key
{
    long long e1, e2, p;
};
ll mod_exp(ll p, ll e, ll n)
{
    ll ans = 1;
    while (e)
    {
        if (e & 1)
            ans = ((ans * p) % n + n) % n;
        p = ((p * p) % n + n) % n;
        e = e >> 1;
    }
    return ans;
}

void findPrimefactors(unordered_set<ll> &s, int n)
{
    while (n % 2 == 0)
    {
        s.insert(2);
        n = n / 2;
    }
    for (ll i = 3; i <= sqrt(n); i = i + 2)
    {
        while (n % i == 0)
        {
            s.insert(i);
            n = n / i;
        }
    }
    if (n > 2)
        s.insert(n);
}

void findPrimitive(ll n)
{
    unordered_set<ll> s;
    ll phi = n - 1;
    findPrimefactors(s, phi);
    cout << "Primitive Elements: ";
    int count = 0;
    for (ll r = 2; r <= phi; r++)
    {
        bool flag = false;
        for (auto it = s.begin(); it != s.end(); it++)
        {
            if (mod_exp(r, phi / (*it), n) == 1)
            {
                flag = true;
                break;
            }
        }
        if (flag == false)
        {
            cout << r << " ";
            count++;
        }
        if (count == 10)
        {
            break;
        }
    }
}

pair<long long, long long> encrypt(int plain_text, key public_key)
{
    long long r;
    cout << "Enter a random integer, r: ";
    cin >> r;

    long long p = public_key.p;
    long long c1 = ((long long)pow(public_key.e1, r)) % p;
    long long c2 = (plain_text * ((long long)pow(public_key.e2, r)) % p) % p;
    pair<long long, long long> c;
    c.first = c1;
    c.second = c2;
    return c;
}

struct epair
{
    long long x, y;
};

epair gcdExtendedEuclid(long long a, long long b)
{
    if (b == 0)
    {
        epair ans;
        ans.x = 1;
        ans.y = 0;
        return ans;
    }
    epair small_ans = gcdExtendedEuclid(b, a % b);

    epair ans;
    ans.x = small_ans.y;
    ans.y = (small_ans.x - ((a / b) * (small_ans.y)));
    return ans;
}

long long mul_inv(long long e, long long n)
{
    epair ans = gcdExtendedEuclid(e, n);
    return ((ans.x % n) + n) % n;
}

int decrypt(pair<long long, long long> ciphers, long long d, long long p)
{
    long long c1_d = (long long)pow(ciphers.first, d);
    long long c1_d_inv = mul_inv(c1_d, p);
    int pt = (ciphers.second * c1_d_inv) % p;
    return pt;
}
int main()
{
    cout << "Key Generation: \n";
    long long p, d, e1;
    cout << "Enter a large prime number, p: ";
    cin >> p;
    cout << "Enter d such that 1<=d<=p-2: ";
    cin >> d;
    while (d < 1 || p - 2 < d)
    {
        cout << "Enter again: ";
        cin >> d;
    }
    findPrimitive(p);
    cout << "\nSelect primitive root for p, e1: ";
    cin >> e1;
    long long e2 = ((long long)pow(e1, d)) % p;
    cout << "e2= " << e2 << endl;
    key public_key;
    public_key.e1 = e1;
    public_key.e2 = e2;
    public_key.p = p;
    long long private_key = d;
    printf("Public Key: (%lli, %lli, %lli)\n", e1, e2, p);
    printf("Private Key: %lli\n", d);

    cout << "\nEncryption:\n";
    int plain_text;
    cout << "Enter plain text: ";
    cin >> plain_text;
    pair<long long, long long> ciphers = encrypt(plain_text, public_key);
    cout << "Ciphers: " << ciphers.first << " and " << ciphers.second << endl;

    cout << "\nDecryption:\n";
    int pt = decrypt(ciphers, private_key, public_key.p);
    cout << "Plain text: " << pt << endl;
}