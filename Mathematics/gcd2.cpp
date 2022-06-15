#include<bits/stdc++.h>
using namespace std;
int gccd(int a, int b)
{
    if(b == 0)
        return a;
else
return gccd(b, a%b);
}
int main(int argc, char const *argv[])
{
    int a, b;
    cin >> a >> b;
   int ans = gccd(a,b);
   cout << ans << endl;

    return 0;
}
