#include<bits/stdc++.h>
using namespace std;

bool prime(int n)
{
    for (int i = 2; i*i <= n; i++)
    {
        if(n%i == 0)
            return false;
    }
    return true;
}

void sieve(int n)
{
    vector<bool> v(n, true);
    for(int i = 2; i*i <= n; i++)
    {

    }
}


int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    return 0;
}
