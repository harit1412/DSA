#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr[5];
    for (int i = 0; i < 5; i++)
    {
        cin >> arr[i];
    }

int larg = arr[0];
for (int i = 0; i < 5; i++)
{
    if(arr[i] > larg)larg = arr[i];
}
cout << larg << endl;

}