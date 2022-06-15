#include<bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int n, x;
    cin >> x >> n;
    int res = 1;
    while(n>0)
    {
        if(n%2 != 0)
            res *= x;
        x = x * x;
        n /= 2;
    }
    cout << res << endl;
    return 0;
}
