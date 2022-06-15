// two pointer approach ................

#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *next;
    node(int d)
    {
        data = d;
        next = NULL;
    }
};

// for
//     n = 2;

/*
1----2-----3-----4-----5----6
|          |
Sec      first
*/

node *EndNthNode(node *head, int n)
{
    node *f = head;
    for (int i = 0; i < n; i++)
    {
        if (f == NULL)
            return NULL;
        f = f->next;
    }
    node *s = head;
    while (f != NULL)
    {
        f = f->next;
        s = s->next;
    }
    return s;
}

int main(int argc, char const *argv[])
{

    node *head = new node(1);
    head->next = new node(2);
    head->next->next = new node(3);
    head->next->next->next = new node(4);
    head->next->next->next->next = new node(5);
    head->next->next->next->next->next = new node(6);
    
    cout << EndNthNode(head, 1)->data;
    return 0;
}