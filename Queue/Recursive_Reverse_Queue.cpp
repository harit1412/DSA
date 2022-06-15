#include <bits/stdc++.h>
using namespace std;


// Using Recursion
void reverse(queue<int> &q)
{
    if (q.empty())
    {
        return;
    }
    int x = q.front();
    q.pop();
    reverse(q);

    q.push(x);
}



void Print(queue<int> q)
{
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
}

int main()
{
    queue<int> q;
    q.push(10);
    q.push(5);
    q.push(15);
    q.push(20);
    cout << "Before : ";
    Print(q);

    cout << endl
         << "After : ";
    reverse(q);

    Print(q);

    return 0;
}