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

void DeleteFirstNode(node *&head)
{
    head = head->next;
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
    head->next = new node(20);
    head->next->next = new node(30);
    PrintList(head);
    cout << endl << "----------------------------------------" << endl
         << endl;
    DeleteFirstNode(head);
    PrintList(head);

    return 0;
}