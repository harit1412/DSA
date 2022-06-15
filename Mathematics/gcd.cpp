#include<bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    // ṇ
    int a;
    int b;
    cin >> a >> b;
    int ans = 1;
    for(int i = 1; i <= min(a, b); i++)
    {
            if(a%i == 0 && b%i == 0)
            {
                ans *= i;
                a /= i; b/= i;
            }
            // cout << i << " ";
    }
cout << ans << endl;
    return 0;
}
