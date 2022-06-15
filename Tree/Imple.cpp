#include <bits/stdc++.h>
using namespace std;
struct tree
{
    int val;
    tree *left;
    tree *right;
    tree(int k)
    {
        val = k;
        left = right = NULL;
    }
};
int main(int argc, char const *argv[])
{
    tree *root = new tree(1);
    root->left = new tree(2);
    root->right = new tree(3);
    root->left->right = new tree(4);
    root->right->left = new tree(5);
    root->left->left = new tree(6);
    root->right->right = new tree(7);

    return 0;
}