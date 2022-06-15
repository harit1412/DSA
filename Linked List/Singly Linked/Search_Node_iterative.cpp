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

int Iter_Search(node *head, int target)
{
    int i = 1;
    while (head != NULL)
    {
        if (head->data == target)
            return i;
        head = head->next;
        i++;
    }
    return -1;
}

int main(int argc, char const *argv[])
{
    node *head = new node(1);
    head->next = new node(2);
    head->next->next = new node(0);
    head->next->next->next = new node(4);
    head->next->next->next->next = new node(5);

    int ans = Iter_Search(head, 1);
    cout << ans << endl;

    return 0;
}