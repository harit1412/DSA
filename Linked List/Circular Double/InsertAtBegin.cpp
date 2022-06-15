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
void InsertAtBegin(node *&head, int d)
{
    if (head == NULL)
    {
        node* temp = new node(d);
        head = temp;
        head->next = head;
        head->prev = head;
    }
    else
    {
        node *temp = new node(d);
        node *x = head;
        temp->next = head;
        head->prev = temp;

        head = temp;
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

    node *head = NULL;


    return 0;
}