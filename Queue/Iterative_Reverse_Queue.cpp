#include <bits/stdc++.h>
using namespace std;
void reverse(queue<int> &q)
{
    stack<int> s;
    while (!q.empty())
    {
        s.push(q.front());
        q.pop();
    }
    while (!s.empty())
    {
        q.push(s.top());
        s.pop();
    }
}
void Print(queue<int> q)
{
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
}
int main(int argc, char const *argv[])
{
    queue<int> q;
    q.push(10);
    q.push(5);
    q.push(15);
    q.push(20);
    cout << "before : ";
    Print(q);

    reverse(q);
    cout << endl
         << "After : ";
    Print(q);
    return 0;
}