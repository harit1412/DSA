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

void ReverseRec(node *&head, node *&tail)
{

    
    node *next = head->next;

    head->next = tail;
    if(next == NULL)
        return;
    tail = head;

    head = next;

    ReverseRec(head, tail);
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
    node *tail = NULL;

    node *head = new node(1);
    head->next = new node(2);
    head->next->next = new node(3);
    head->next->next->next = new node(4);
    head->next->next->next->next = new node(5);
    head->next->next->next->next->next = new node(6);
    PrintList(head);
    cout << endl
         << "__________________________" << endl;

    ReverseRec(head, tail);
    
    PrintList(head);
    return 0;
}