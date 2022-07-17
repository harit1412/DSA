#include <bits/stdc++.h>
using namespace std;
struct tree
{
    int key;
    tree *left, *right;
    tree(int k)
    {
        key = k;
        left = NULL;
        right = NULL;
    }
};

bool Search(tree *root, int key)
{
    while (root != NULL)
    {
        if (key < root->key)
            root = root->left;
        else if (key > root->key)
            root = root->right;
        else
            return true;
    }
    return false;
}

int main(int argc, char const *argv[])
{
    tree *root = new tree(15);
    root->left = new tree(5);
    root->right = new tree(20);
    root->right->left = new tree(18);
    root->right->right = new tree(80);
    root->right->left->left = new tree(16);
    cout << Search(root, 21);
    return 0;
}
