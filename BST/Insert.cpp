#include <bits/stdc++.h>
using namespace std;
struct tree
{
    int key;
    tree *left;
    tree *right;
    tree(int k)
    {
        key = k;
        left = NULL;
        right = NULL;
    }
};

void *Insert(tree *&root, int key)
{
    tree *temp = root;
    tree *prev = NULL;
    while (temp != NULL)
    {
        prev = temp;
        if (temp->key < key)
            temp = temp->right;
        else
            temp = temp->left;
    }
    tree *newroot = new tree(2);
    if (prev == NULL)
    {
        root = newroot;
    }
    else
    {
        if (prev->key < key)
            prev->right = newroot;
        else
            prev->left = newroot;
    }
}

int main(int argc, char const *argv[])
{
    tree *root = new tree(15);
    root->left = new tree(5);
    root->right = new tree(20);
    root->right->left = new tree(18);
    root->right->right = new tree(80);
    root->right->left->left = new tree(16);
    // cout << Search(root, 21);
    return 0;
}
