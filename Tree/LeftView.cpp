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
int maxLevel = 0;
void LeftView(Node *root, int level)
{

    if (root == NULL)
        return;
    // if (maxLevel < level)
    // {
        cout << root->key << " ";
        // maxLevel = level;
    // }
    LeftView(root->left, level + 1);
    LeftView(root->right, level + 1);
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
    LeftView(root, 1);

    return 0;
}