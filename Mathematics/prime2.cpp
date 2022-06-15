#include<bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    int count = 0;
    for (int i = 2; i <= sqrt(n); i++)
    {
        if(n%i == 0)
        {
                count++;
                break;
        }
    }
    if(count)cout << "not prime" << endl;
    else cout << "prime" << endl;
        return 0;
}
