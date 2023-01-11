#include <bits/stdc++.h>
#define ll long long
using namespace std;
vector<ll> v(100000, -1);

ll climb1(ll n)
{
    if (n < 0)
    {
        return 0;
    }
    if (n == 0)
    {
        return 1;
    }
    if (v[n] != -1)
    {
        return v[n];
    }
    return v[n] = climb1(n - 1) + climb1(n - 2);
}

ll climb2(ll n)
{
    if (n == 0)
        return 1;
    if (n == 1)
        return 1;
    if (v[n] != -1)
        return v[n];
    return v[n] = climb2(n - 1) + climb2(n - 2);
}

ll climb3(ll n)
{
    ll a = 1;
    ll b = 1;
    for (int i = 3; i <= n; i++)
    {
        ll sum = a + b;
        a = b;
        b = sum;
    }
    return a + b;
}

int main()
{
    cout << climb3(100);
}