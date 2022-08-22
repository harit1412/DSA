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

void deleteLeaf(tree *ploc, tree *loc)
{
    if (ploc->left == loc)
        ploc->left = NULL;
    else
        ploc->right = NULL;
}
void delete_with_one_child(tree *ploc, tree *loc)
{
    if (ploc->right == loc)
    {
        if (loc->right == NULL)
        {
            ploc->right = loc->left;
        }
        else
        {
            ploc->right = loc->right;
        }
    }
    if (ploc->left == loc)
    {
        if (loc->right == NULL)
        {
            ploc->left = loc->left;
        }
        else
        {
            ploc->left = loc->right;
        }
    }
}

void delete_with_two_child(tree *ploc, tree *loc)
{
    tree *psloc = NULL;
    tree *sloc = loc->right;
    while (sloc->left != NULL)
    {
        psloc = sloc;
        sloc = sloc->left;
    }
    loc->key = sloc->key;
    psloc->left = sloc->right;
}

void *Insert(tree *&root, int key)
{
    tree *newroot = new tree(key);
    // cout << key << endl;
    if (root == NULL)
    {
        root = newroot;
    }
    else
    {
        tree *prev = NULL;
        tree *cur = root;
        while (cur != NULL)
        {
            prev = cur;
            if (key > cur->key)
                cur = cur->right;
            else
                cur = cur->left;
        }
        if (key > prev->key)
            prev->right = newroot;
        if (key < prev->key)
            prev->left = newroot;
    }
}

tree *Search(tree *root, int key)
{
    while (root != NULL)
    {
        if (key < root->key)
            root = root->left;
        else if (key > root->key)
            root = root->right;
        else
            return root;
    }
    return root;
}

void Print(tree *root)
{
    if (root == NULL)
        return;
    Print(root->left);
    cout << root->key << " ";
    Print(root->right);
}

int main(int argc, char const *argv[])
{
    tree *root = NULL;
    Insert(root, 20);
    Insert(root, 10);
    Insert(root, 2);
    Insert(root, 40);
    Insert(root, 41);
    Insert(root, 2);
    Insert(root, 1);
    Insert(root, 23);
    Print(root);
    cout << "--------------------------------" << endl;
    // cout << root->key << " ";
    // deleteLeaf(root, Search(root, 1));
    Print(root);
    return 0;
}
