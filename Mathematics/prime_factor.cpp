#include<bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int n; cin >> n;
// int ans = 1;
int max = sqrt(n);
	for(int i = 2 ; i <= max ; i++)
	{
		while(n%i == 0)
		{
			cout << i << " ";
			n/=i;
		}
	}
if(n > 1)cout << n;
}