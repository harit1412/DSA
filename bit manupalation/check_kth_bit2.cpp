#include<bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int n,k;
    cin >> n >> k;
    if (n & (1 << (k - 1)))
        cout << "SET";
    else
        cout << "NOT SET";
}