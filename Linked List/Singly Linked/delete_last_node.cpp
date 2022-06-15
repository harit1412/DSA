#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *next;
    node(int x)
    {
        data = x;
        next = NULL;
    }
};

void PrintList(node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

void deleteLastNode(node *head)
{
    node *prev;
    while (head->next != NULL)
    {
        prev = head;
        head = head->next;
    }

    prev->next = NULL;
}

int main(int argc, char const *argv[])
{

    node *head = new node(10);
    // node *first = new node(20);
    // node *sec = new node(30);
    head->next = new node(20);
    head->next->next = new node(30);
    // head->next = first;
    // first->next = sec;

    PrintList(head);
    deleteLastNode(head);
    cout << "\n";
    PrintList(head);

    return 0;
}