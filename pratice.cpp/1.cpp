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

int hieght(tree *root)
{
    if (root == NULL)
        return 0;
    else
        return (1 + max(hieght(root->right), hieght(root->left)));
}

int mx = 0;
int cunt = 0;
int diameter(tree *root)
{
    if (root == NULL)
        return 0;
    int op1 = diameter(root->left);
    int op2 = diameter(root->right);
    int op3 = hieght(root->left) + hieght(root->right);
    return max(op1, max(op2, op3));
}

void sumReplacement(tree *root)
{
    if (root == NULL)
        return;
    sumReplacement(root->left);
    sumReplacement(root->right);
    if (root->left)
        root->key += root->left->key;
    if (root->right)
        root->key += root->right->key;
}
void print(tree *root)
{
    if (root == NULL)
        return;
    print(root->left);
    cout << root->key << " ";
    print(root->right);
}
bool ans = true;
void isBal(tree *root)
{
    if (root == NULL)
        return;
    isBal(root->left);
    isBal(root->right);
    int a = abs(hieght(root->left) - hieght(root->right));
    if (a != 1 && a != 0)
        ans = false;
}
int mxlevel = 0;
void RightView(tree *root, int level)
{
    if (root == NULL)
        return;
    if (mxlevel < level)
    {
        cout << root->key << " ";
        mxlevel++;
    }
    RightView(root->right, level + 1);
    RightView(root->left, level + 1);
}
bool bc = false;
int wow = 0;
void minDistance(tree *root , int a , int b)
{
    if(root == NULL)
        return;

    minDistance(root->left, a, b);
    if(bc)
        wow++;
    if(root->key == a || root->key == b)
    {
        bc = true;
    }
    

    minDistance(root->right, a, b);
    
}


int main(int argc, char const *argv[])
{
    tree *root = new tree(1);
    root->left = new tree(2);
    root->right = new tree(3);
    root->left->left = new tree(4);
    root->left->right = new tree(5);
    root->right->left = new tree(6);
    root->right->right = new tree(7);
    RightView(root, 1);
    // cout << hieght(root);
    // diameter(root);
    // cout << mx;
    // sumReplacement(root);
    // print(root);
    // cout << ans << endl;
    return 0;
}
