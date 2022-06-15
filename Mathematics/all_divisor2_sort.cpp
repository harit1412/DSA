#include<bits/stdc++.h>
using namespace std;

int main() {

int n;
cin >> n;
int i;
for ( i = 1; i * i <= n; i++)
{
    if( n%i == 0 )
    {
        cout << i << " ";
        }
}
for (; i >= 1; i--)
{
    if( n % i == 0 && i != n/i ) cout << n/i << " ";

}
}