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

int BalTree(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int lh = BalTree(root->left);
    if (lh == -1)
        return -1;
    int rh = BalTree(root->right);
    if (rh == -1)
        return -1;
    if (abs(lh - rh) > 1)
        return -1;
    else
        return max(lh, rh) + 1;
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

    cout << BalTree(root);

    return 0;
}