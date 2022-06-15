#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n;i++) {
        cin >> arr[i];
    }
    cout << "\nbefore ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
cout << endl;    
    for (int i = 0, j = n - 1; i < n / 2; i++ , j--)
    {
        swap(arr[i],arr[j]);
    }
    cout << "\nafter ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}