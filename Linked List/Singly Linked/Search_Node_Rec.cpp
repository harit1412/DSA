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

int Rec_Search(node *head, int target, int i)
{
    if (head->data == target)
        return i;
    if (head->next == NULL)
        return -1;
    Rec_Search(head->next, target, i + 1);
    // return;
}

int main(int argc, char const *argv[])
{
    node *head = new node(1);
    head->next = new node(2);
    head->next->next = new node(0);
    head->next->next->next = new node(4);
    head->next->next->next->next = new node(5);
    cout << Rec_Search(head, 1, 1);

    return 0;
}