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

void ReverseIterative(node *&head)
{
    node *temp = head;
    node *prev = NULL;
    node *next = NULL;

    while (temp != NULL)
    {
        if (temp == head)
        {
            prev = temp;
            next = temp->next;
            temp->next = NULL;
        }
        else
        {
            next = temp->next;
            temp->next = prev;
            prev = temp;
        }
        temp = next;
    }
    head = prev;
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
    node *head = new node(1);
    head->next = new node(2);
    head->next->next = new node(3);
    head->next->next->next = new node(4);
    head->next->next->next->next = new node(5);
    head->next->next->next->next->next = new node(6);
    ReverseIterative(head);
    PrintList(head);

    return 0;
}