#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr[5];
    for (int i = 0; i < 5;i++)
    {
        cin >> arr[i];
    }
    int flag = 1;
    for (int i = 1; i < 5; i++)
    {
        if(arr[i] < arr[i-1]) 
        {
            flag = 0;
            break;
        }

    }
    if(flag)
        cout << "yes";
        else
        cout << "no";
}