#include <bits/stdc++.h>
using namespace std;
#define size 100
class dq
{
    int *arr;
    int front;
    int end;
    dq()
    {
        end = -1;
        front = -1;
        arr = new int[size];
    }
    void enqueue(int x)
    {
        if (end == -1)
            front++;

        arr[++end] = x;
    }
    void dequeue()
    {
        front++;
    }
    int getFront()
    {
        if (front > end)
            cout << "Underflow";
        else
            return arr[front];
    }
    int getRear()
    {
        if (end == -1)
            cout << "Empty";
        else  return arr[end];
    }
};
int main(int argc, char const *argv[])
{

    return 0;
}