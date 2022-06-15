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

void LevelOrder(Node *root)
{
    queue<Node *> q;
    q.push(root);
    // vector<int> v;
    while (q.empty() == false)
    {
        Node *curr = q.front();
        // v.push_back(curr->key);
        cout << curr->key << " ";
        q.pop();
        if (curr->left != NULL)
        {
            q.push(curr->left);
        }
        if (curr->right != NULL)
        {
            q.push(curr->right);
        }
    }
    // for (int i = v.size() - 1; i >= 0; i--)
    // {
    //     cout << v[i] << " ";
    // }
}

int main(int argc, char const *argv[])
{
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->right->left = new Node(40);
    root->right->right = new Node(50);
    LevelOrder(root);
    return 0;
}