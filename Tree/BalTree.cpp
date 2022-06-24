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

int hieght(Node *root)
{
    if (root == NULL)
        return 0;

    return 1 + max(hieght(root->left), hieght(root->right));
}
bool ans = true;
bool BalTree(Node *root)
{

    if (root == NULL)
        return true;

    return (abs(hieght(root->left) - hieght(root->right)) <= 1 && BalTree(root->left) && BalTree(root->right));
}

int main(int argc, char const *argv[])
{
   Node *root=new Node(10);
	root->left=new Node(5);
	root->right=new Node(30);
	root->right->left=new Node(15);
	root->right->right=new Node(20);
    cout << BalTree(root);

    return 0;
}