#include <bits/stdc++.h>
using namespace std;

struct Node
{

    int d;
    Node *next;
    Node(int x)
    {
        d = x;
        next = NULL;
    }
};

int main(int argc, char const *argv[])
{

    int n;
    cin >> n;
    Node *head;
    Node *temp;
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            int x;
            cin >> x;
            head = new Node(x);
            
        }
        int y;
    }

    return 0;
}