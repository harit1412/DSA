#include <bits/stdc++.h>
using namespace std;

struct node
{

    int data;
    node *next;
};

void func(node *loc, node *locp, node *&free)
{
    node *n = new node();
    locp->next = loc->next;

    //

    loc->next = free;
    free = loc;
}

node *InsertEnd(int d, node *&head, node *&tail)
{
    if (head == NULL)
    {
        node *temp = new node();
        temp->data = d;
        head = temp;
        temp->next = NULL;
        return temp;
    }
    else
    {
        node *temp = new node();
        temp->data = d;
        tail->next = temp;
        temp->next = NULL;
        return temp;
    }
}

// a-3
//  Node *insertEnd(Node *head,int x){
//      Node *temp=new Node(x);
//      if(head==NULL)return temp;

//     Node *curr=head;
//     while(curr->next!=NULL){
//         curr=curr->next;
//     }
//     curr->next=temp;
//     return head;

// }

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

    node *head = NULL;
    node *tail = NULL;

    tail = InsertEnd(1, head, tail);
    tail = InsertEnd(2, head, tail);
    tail = InsertEnd(3, head, tail);
    tail = InsertEnd(4, head, tail);
    tail = InsertEnd(4, head, tail);

    tail = InsertEnd(4, head, tail);

    PrintList(head);

    return 0;
}