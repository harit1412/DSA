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

void InOrder(Node *root)
{
    if (root == NULL)
        return;
    // if (root != NULL)
    // {
    InOrder(root->left);
    cout << root->key << " ";
    InOrder(root->right);
    // }
}

int main(int argc, char const *argv[])
{
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->right->left = new Node(40);
    root->right->right = new Node(50);
    InOrder(root);

    return 0;
}