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

int mxlevel = 0;

void LeftOrder(Node *root, int level)
{
    if (root == NULL)
        return;

    if (mxlevel < level)
    {
        cout << root->key << " ";
        mxlevel = level;
    }
    // -> For LeftView
    LeftOrder(root->left, level + 1);
    LeftOrder(root->right, level + 1);
    // -> For RightView
//     LeftOrder(root->right, level + 1);
//     LeftOrder(root->left, level + 1);
}

int main(int argc, char const *argv[])
{
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(50);
    root->left->right->right = new Node(0);

    root->right->left = new Node(60);
    root->right->right = new Node(70);

    LeftOrder(root, 1);

    return 0;
}