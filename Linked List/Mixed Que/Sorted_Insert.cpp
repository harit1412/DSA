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


void InsertSort(node* &head , int d)
{
    if(head == NULL)
    {
        node *temp = new node(d);
        head = temp;
    }
    else
    {
        node *prev = NULL;
        node* x = head;
        while(x != NULL)
        {
            if(x->data >=d )
            {
                break;
            }
            prev = x;
            x = x->next;
        
        }

        if(prev == NULL)
        {
            node* temp = new node(d);
            temp->next = head;
            head = temp;
            return;
        }
      
        node *temp = new node(d);
        prev->next = temp;
        temp->next = x;
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
    node* head = NULL;
    InsertSort(head , 1);
    InsertSort(head , 5);
    InsertSort(head , 6);
    InsertSort(head , 2);
    InsertSort(head , 3);
    InsertSort(head , 0);
    InsertSort(head , 2);
    InsertSort(head , 0);

    PrintList(head);

    return 0;
}