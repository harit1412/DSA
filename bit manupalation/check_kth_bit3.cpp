#include<bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int n, k;
    cin >> n >> k;
    if((n >> (k-1))&1 == 1)
        cout << "yes";
    else
    cout<< "no";
    return 0;
}
