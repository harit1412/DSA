#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
    Node(int k)
    {
        key = k;
        left = right = NULL;
    }
};

Node *Convert(Node *root)
{
    if (root == NULL)
        return root;
    static Node *prev = NULL;
    Node *head = Convert(root->left);
    if (prev == NULL)
    {
        head = root;
    }
    else
    {
        root->left = prev;
        prev->right = root;
    }
    prev = root;
    Convert(root->right);
    return head;
}
void PrintList(Node *head)
{
    while (head != NULL)
    {
        cout << head->key << " ";
        head = head->right;
    }
}

int main(int argc, char const *argv[])
{
    Node *root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(30);
    root->right->left = new Node(15);
    root->right->right = new Node(20);
    root->right->right->right = new Node(30);
    root->right->right->right->right = new Node(40);
    Node *head = Convert(root);
    PrintList(head);

    return 0;
}