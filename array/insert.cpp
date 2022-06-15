#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr[5] ;
    arr[0] = 1, arr[1] = 2, arr[2] = 3;
    int temp;
    cin >> temp;
    int k;
    cin >> k;



    for (int i = k-1; i < 5; i++)
    {
        swap(temp , arr[i]);
    }
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
    
    
}