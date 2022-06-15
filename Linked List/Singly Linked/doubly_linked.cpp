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

void PrintList(node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

void Printrev(node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->prev;
    }
}



int main(int argc, char const *argv[])
{

node* head = NULL;
node *priv;
for (int i = 1; i <= 5; i++)
{
    int d;
    cin >> d;
    node *temp = new node(d);
    if (head == NULL)
    {
        head = temp;
        temp->prev = NULL;
        temp->next = NULL;
        priv = temp;
    }
    else
    {
        temp->prev = priv;
        priv->next = temp;
        priv = temp;
    }


    }

    Printrev(priv);
    cout << "\n";
    PrintList(head);

    return 0;
}