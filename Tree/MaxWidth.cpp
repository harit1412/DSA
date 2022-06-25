#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int key;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int k)
    {
        key = k;
        left = right = NULL;
    }
};

int widthTree(TreeNode *root)
{
    queue<TreeNode *> q;
    if (root == NULL)
        return 0;

    q.push(root);
    q.push(NULL);
    int mx = 0;
    int count = 0;
    while (q.size() > 1)
    {
        TreeNode *curr = q.front();

        q.pop();
        if (curr == NULL)
        {
            mx = max(mx, count);
            count = 0;
            q.push(curr);
            continue;
        }
        count++;
        if (curr->left != NULL)
            q.push(curr->left);
        if (curr->right != NULL)
            q.push(curr->right);
    }
    return count;
}

int main(int argc, char const *argv[])
{
    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(20);
    root->right = new TreeNode(30);
    root->left->left = new TreeNode(40);
    root->left->right = new TreeNode(50);
    root->right->left = new TreeNode(60);
    root->right->right = new TreeNode(60);

    cout << widthTree(root);

    // cout << BalTree(root);

    return 0;
}