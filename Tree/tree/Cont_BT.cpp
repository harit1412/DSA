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
int i = 0;

void Inorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    Inorder(root->left);
    cout << root->key << " ";
    Inorder(root->right);
}

Node *constr(int in[], int pre[], int is, int ie)
{
    if (is > ie)
        return NULL;
    Node *root = new Node(pre[i++]);
    int Index;
    for (int k = is; k <= ie; k++)
    {
        if (root->key == in[k])
        {
            Index = k;
            break;
        }
    }
    root->left = constr(in, pre, is, Index - 1);
    root->right = constr(in, pre, Index + 1, ie);
    return root;
}

int main()
{

    int in[] = {20, 10, 40, 30, 50};
    int pre[] = {10, 20, 30, 40, 50};
    int n = sizeof(in) / sizeof(in[0]);
    Inorder(constr(in, pre, 0, n-1));
}
