#include<bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    int count = 0;
    for(int i = 2; i < n; i++)
    {
        if(n%2 == 0)
        {
            count++;
            break;
        }
    }

    if(count)cout << "not prime" << endl;
    else cout << "prime" << endl;
    return 0;
}
