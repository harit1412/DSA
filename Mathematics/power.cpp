#include<bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int x, n;
    cin >> x >> n;
    int ans = 1;
    for(int i = 0; i < n; i++)
    {
        ans *= x;
    }
    cout << ans;
    return 0;
}
