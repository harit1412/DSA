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
    node *h1 = head;
    // cout << head;

    head->next = new node(20);

    head->next->next = new node(30);
    node *loc = head->next;
    head->next->next->next = new node(40);
    head->next->next->next->next = new node(50);

    node *temp = new node(0);
    node *fut = loc->next;
    loc->next = temp;
    temp->next = fut;

    // PrintList(head);

    // PrintList(head);
    // cout << endl;
    // node *prev;
    // node *h = head;
    // for (int i = 1; i < 3; i++)
    // {
    //     prev = head;
    //     head = head->next;
    // }

    // prev->next = head->next;

    // node *h1 = h;
    // node *head1 = h1;

    // while (h != NULL)
    // {
    //     cout << h->data << endl;
    //     h = h->next;
    // }

    // //---;
    // // Insert At End ....
    // for (; h1 != NULL;)
    // {
    //     prev = h1;
    //     h1 = h1->next;
    // }

    // cout << "--------" << endl;
    // node *temp = new node(60);
    // temp->next = h1;
    // prev->next = temp;
    // PrintList(head1);

    // Search and Insert...

    while (head->data != 0)
    {
        head = head->next;
    }

    // fut = head->next;
    node *tem = new node(1);
    tem->next = head->next;
    head->next = tem;

    PrintList(h1);

    return 0;
}