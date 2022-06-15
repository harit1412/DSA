#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr[] = {5, 20, 12, 20, 8};
    int largest = max(arr[0], arr[1]);
    int larg = min(arr[0], arr[1]);

    for(int i = 2; i < 5; i++)
    {
            if(arr[i] > largest)
            {
                swap(larg, largest);
                largest = arr[i];
                continue;
            }
           if(arr[i] > larg)
           {
              if(arr[i] != largest) larg = arr[i];
               continue;
           }
    }
    cout << larg;
}