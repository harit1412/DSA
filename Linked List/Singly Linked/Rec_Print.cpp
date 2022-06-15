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

void PrintRec(node *head)
{
    if (head == NULL)
        return;
    cout << head->data << endl;
    PrintRec(head->next);
}

int main(int argc, char const *argv[])
{
    node *head = new node(1);
    head->next = new node(2);
    head->next->next = new node(3);
    head->next->next->next = new node(4);
    head->next->next->next->next = new node(5);
    PrintRec(head);
    return 0;
}