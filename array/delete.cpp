#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr[5] = {0, 1, 2, 3 ,4};
    int k = 1;

    int index;
    for (int i = 0; i < 5; i++)
    {
      if(arr[i] == k)
      {
          index = i;
          break;
      }
    }
    for (int i = index; i < 4; i++)
    {
        swap(arr[i], arr[i + 1]);
    }
    for (int i = 0; i < 5; i++)
    {
        /* code */ cout << arr[i] << " ";
    }
    
    
}