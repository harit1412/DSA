#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr[] = {45, 45, 45, 45, 45};
    int index = 0;
    int largest = arr[0];
    for (int i = 0; i < 5; i++)
    {
        if(largest < arr[i])
        { 
            largest = arr[i];
            index = i;
        }
    }
    int larg = -1;
    int in = -1;

    for (int i = 0; i < 5; i++)
    {
        
        
        if(larg < arr[i] && i != index) 
        {
            larg = arr[i];
            // cout << larg << " ";
            in = i;
        }
    }
    // cout << larg << endl;
    cout << in;
}