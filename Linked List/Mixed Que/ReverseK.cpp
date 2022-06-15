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
void ReverseIterative(node *&head, int k)
{
    node *temp = head;
    node *prev = NULL;
    node *next = NULL;
    node *first = NULL;
    while (temp != NULL)
    {
        int i = 0;
        while (temp != NULL && i % k != 0)
        {
            if (temp == head)
            {
                prev = temp;
                first = temp;
                next = temp->next;
            }
            else
            {
                next = temp->next;
                temp->next = prev;
                prev = temp;
            }
            frist->next = next;
            temp = next;
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
    ReverseIterative(head, 3);
    PrintList(head);
    return 0;
}