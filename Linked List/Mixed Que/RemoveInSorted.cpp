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

void Remove(node *loc, node *&head)
{
    if (loc == head)
    {
        head = loc->next;
    }
    else
    {
        loc->next = loc->next->next;
    }
}

void DeleteSimilar(node *&head)
{
    if(head == NULL)return;
    node *temp = head;
    while (temp->next != NULL)
    {
        if (temp->data == temp->next->data)
        {
            Remove(temp, head);
        }
        else
        {
            temp = temp->next;
        }
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
    // node* head = NULL;
    node *head = new node(1);
    head->next = new node(2);
    head->next->next = new node(2);
    head->next->next->next = new node(3);
    head->next->next->next->next = new node(3);
    head->next->next->next->next->next = new node(3);
    PrintList(head);
    cout << endl
         << "-------------------" << endl;
         DeleteSimilar(head);
    PrintList(head);
    return 0;
}