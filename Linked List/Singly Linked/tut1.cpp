#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

void print(Node *h)
{
    while (h != NULL)
    {
        cout << h->data << " ";
        h = h->next;
    }
}

int main(int argc, char const *argv[])
{

    Node *s = new Node(10);
    Node *n = new Node(20);
    Node *p = new Node(30);

    Node *head = s;
    s->next = n;
    n->next = p;
    p->next = NULL;
    print(head);

    return 0;
}