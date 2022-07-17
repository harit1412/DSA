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
int main(int argc, char const *argv[])
{

    return 0;
}
