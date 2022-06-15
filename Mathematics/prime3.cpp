#include<bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    int count = 0;
    for (int i = 2; i <= sqrt(n); i = i + 6)
    {
        if(n%2 == 0 && n != 2)
        {
            count++;
            break;
        }
        if(n%3 == 0 && n != 3)
{
    count++;
    break;
    
}
        if(n%i == 0 || n%(i+2) == 0)
        {
                count++;
                break;
        }
    }
    if(count)cout << "not prime" << endl;
    else cout << "prime" << endl;
        return 0;
}
