#include <bits/stdc++.h>
using namespace std;

struct node
{

    int data;
    node *next;

    // node(int d)
    // {
    //     data = d;
    //     next = NULL;
    // }
};

void InsertBegin(int d, node *&head)
{
    if (head == NULL)
    {
        node *n = new node();
        head = n;
        head->data = d;
        head->next = NULL;
    }
    else
    {
        node *n = new node();
        node *temp = head;
        head = n;
        head->data = d;
        head->next = temp;
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

// node *insertBegin(node *head,int x){
//     node *temp=new node();
//     node* temp->data = x;
//     temp->next=head;
//     return temp;

// }

int main(int argc, char const *argv[])
{
    node *head = NULL;
    // head = NULL;
    InsertBegin(6, head);
    InsertBegin(5, head);
    InsertBegin(4, head);
    InsertBegin(3, head);
    InsertBegin(2, head);
    InsertBegin(1, head);

    PrintList(head);

    return 0;
}