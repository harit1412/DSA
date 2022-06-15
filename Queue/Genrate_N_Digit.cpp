#include <bits/stdc++.h>
#include <queue>
using namespace std;

void printFirstN(int n)
{
    queue<string> q;

    q.push("5");
    q.push("6");
    q.push("7");

    for (int i = 0; i < n; i++)
    {
        string curr = q.front();

        cout << curr << " ";

        q.pop();

        q.push(curr + "5");
        q.push(curr + "6");
        q.push(curr + "7");
    }
}

int main()
{
    int n = 20;

    printFirstN(n);
}
