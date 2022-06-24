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
bool ans = true;
void levelorder(Node *root)
{
    int sum;
    if (root == NULL)
        return;
    if (root->left && root->right)
    {
        sum = root->left->key + root->right->key;
        if (sum != root->key)
        {
            ans = false;
        }
    }
    if (root->left != NULL && root->right == NULL)
    {
        if (root->left->key != root->key)
        {
            ans = false;
        }
    }
    if (root->right != NULL && root->left == NULL)
    {
        if (root->right->key != root->key)
        {
            ans = false;
        }
    }
    levelorder(root->left);
    levelorder(root->right);
}

int main(int argc, char const *argv[])
{
    Node *root = new Node(20);
    root->left = new Node(8);
    root->right = new Node(12);
    root->right->left = new Node(3);
    root->right->right = new Node(9);

    levelorder(root);
    cout << ans;

    // cout << cont;
    return 0;
}