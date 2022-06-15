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

int SizeOftree(Node *root)
{
    if (root == NULL)
        return 0;
    else
        return 1 + SizeOftree(root->left) + SizeOftree(root->right);
}

int main(int argc, char const *argv[])
{
     Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(50);
    root->right->left = new Node(60);
    root->right->right = new Node(70);
    cout << SizeOftree(root);

    return 0;
}