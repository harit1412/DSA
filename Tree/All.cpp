#include <bits/stdc++.h>
#define nl NULL
#define csp(x) cout << x << " "
#define c(x) cout << x

using namespace std;
struct tree
{
    tree *left;
    tree *right;
    int key;
    tree(int k)
    {
        key = k;
        left = right = nl;
    }
};

void PreOrder(tree *root)
{
    if (root == nl)
        return;
    csp(root->key);
    PreOrder(root->left);
    PreOrder(root->right);
}

void InOrder(tree *root)
{
    if (root == nl)
        return;
    InOrder(root->left);
    csp(root->key);
    InOrder(root->right);
}

void PostOrder(tree *root)
{
    if (root == nl)
        return;
    PostOrder(root->left);
    PostOrder(root->right);
    csp(root->key);
}

int Hieght(tree *root)
{
    if (root == nl)
        return 0;
    return 1 + max(Hieght(root->left), Hieght(root->right));
}

void PrintKthNodes(tree *root, int k)
{
    if (root == nl)
    {
        return;
    }
    if (k == 0)
    {
        csp(root->key);
        return;
    }
    PrintKthNodes(root->left, k - 1);
    PrintKthNodes(root->right, k - 1);
}

void LevelOrder(tree *root)
{
    queue<tree *> q;
    q.push(root);
    while (!q.empty())
    {
        tree *curr = q.front();
        csp(curr->key);
        q.pop();
        if (curr->left)
            q.push(curr->left);
        if (curr->right)
            q.push(curr->right);
    }
}

void LevelOrder2(tree *root)
{
    queue<tree *> q;
    q.push(root);
    q.push(nl);
    while (q.size() > 1)
    {
        tree *curr = q.front();
        q.pop();
        if (curr == nl)
        {
            q.push(nl);
            c("\n");
            continue;
        }
        csp(curr->key);
        if (curr->left)
            q.push(curr->left);
        if (curr->right)
            q.push(curr->right);
    }
}

int SizeOfTree(tree *root)
{
    if (root == nl)
    {
        return 0;
    }
    return 1 + SizeOfTree(root->left) + SizeOfTree(root->right);
}

int MaxInTree(tree *root)
{
    if (root == nl)
    {
        return INT_MIN;
    }
    return max(root->key, max(MaxInTree(root->left), MaxInTree(root->right)));
}

int main(int argc, char const *argv[])
{
    tree *root = new tree(1);
    root->left = new tree(2);
    root->right = new tree(3);
    root->left->left = new tree(4);
    root->left->right = new tree(5);
    root->left->left->left = new tree(8);
    root->left->left->right = new tree(9);

    root->right->left = new tree(6);
    root->right->right = new tree(7);

    // PreOrder(root);
    // InOrder(root);
    // PostOrder(root);
    // csp(Hieght(root));
    // PrintKthNodes(root, 3);
    // LevelOrder(root);
    // LevelOrder2(root);
    // c(SizeOfTree(root));
    c(MaxInTree(root));
    return 0;
}