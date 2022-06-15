#include<bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int n,k;
    cin >> n >> k;
    k = pow(2, k - 1);
    if(k == (n&k))
        cout << "Yes set";
        else
        cout << "No set";
    return 0;
}
