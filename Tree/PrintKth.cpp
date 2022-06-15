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

void PrintKth(Node *root, int k)
{
    if (root == NULL)
        return;
    if (k == 0)
    {
        cout << root->key << " ";
    }
    PrintKth(root->left, k - 1);
    PrintKth(root->right, k - 1);
}

int main(int argc, char const *argv[])
{
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(50);
    root->right->right = new Node(70);
    root->right->right->right = new Node(80);
    PrintKth(root, 2);
    return 0;
}