#include <bits/stdc++.h>

using namespace std;

struct node
{
    int data;
    node *next;
    node *prev;
    node(int d)
    {
        data = d;
        next = NULL;
        prev = NULL;
    }
};

void ReverseList(node *&head)
{
    while (head->next != NULL)
    {
        head = head->next;
    }

    node *x = head;
    while (x != NULL)
    {
        swap(x->next, x->prev);
        x = x->next;
    }
}

void PrintList(node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

int main(int argc, char const *argv[])
{

    node *head = new node(10);
    node *temp1 = new node(20);
    node *temp2 = new node(30);
    head->next = temp1;
    temp1->prev = head;
    temp1->next = temp2;
    temp2->prev = temp1;

    ReverseList(head);
    PrintList(head);

    return 0;
}