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

void RecLeftView(tree *root, int level)
{
    static int mxLevel = 0;
    if (root == nl)
        return;
    if (mxLevel < level)
    {
        csp(root->key);
        mxLevel = level;
    }
    RecLeftView(root->left, level + 1);
    RecLeftView(root->right, level + 1);
}

void RecRightView(tree *root, int level)
{
    static int mxLevel = 0;
    if (root == nl)
        return;
    if (mxLevel < level)
    {
        csp(root->key);
        mxLevel = level;
    }
    RecRightView(root->right, level + 1);
    RecRightView(root->left, level + 1);
}

bool children_sum(tree *root)
{
    if (root == NULL)
        return true;
    queue<tree *> q;
    q.push(root);
    while (q.size() > 0)
    {
        tree *curr = q.front();
        q.pop();
        int sum = 0;
        if (curr->left)
        {
            q.push(curr->left);
            sum += curr->left->key;
        }
        if (curr->right)
        {
            q.push(curr->right);
            sum += curr->right->key;
        }
        if (sum != curr->key && sum != 0)
        {
            return false;
        }
    }
    return true;
}

// Using recursive
bool isCSum(tree *root)
{
    if (root == NULL)
        return true;
    if (root->left == NULL && root->right == NULL)
        return true;
    int sum = 0;
    if (root->left != NULL)
        sum += root->left->key;
    if (root->right != NULL)
        sum += root->right->key;

    return (root->key == sum && isCSum(root->left) && isCSum(root->right));
}
// O(n2)
bool isBalanced(tree *root)
{
    if (root == NULL)
    {
        return true;
    }

    return (abs(Hieght(root->left) - Hieght(root->right)) <= 1) && isBalanced(root->left) && isBalanced(root->right);
}

// O(n)
int isBalanced2(tree *root)
{
    if (root == NULL)
        return 0;
    int lh = isBalanced2(root->left);
    if (lh == -1)
        return -1;
    int rh = isBalanced2(root->right);
    if (rh == -1)
        return -1;
    if (abs(lh - rh) > 1)
        return -1;
    else
        return max(lh, rh) + 1;
}

int MaxWidth(tree *root)
{
    if (root == NULL)
        return 0;
    // if (root->left == NULL and root->right == NULL)
    //     return 1;
    queue<tree *> q;
    q.push(root);
    q.push(NULL);
    int mx = 0;
    int count = 0;
    while (q.size() > 1)
    {
        tree *curr = q.front();
        q.pop();
        if (curr == NULL)
        {
            q.push(NULL);
            mx = max(count, mx);
            count = 0;
        }
        else
        {
            count++;
            if (curr->left)
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);
        }
    }
    mx = max(count, mx);
    return mx;
}

// In better way
int MaxWidth2(tree *root)
{
    if (root == NULL)
        return 0;
    queue<tree *> q;
    q.push(root);
    int mx = 0;
    while (!q.empty())
    {
        int count = q.size();
        mx = max(mx, count);
        for (int i = 0; i < count; i++)
        {
            tree *curr = q.front();
            q.pop();
            if (curr->left)
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);
        }
    }
    return mx;
}




int main(int argc, char const *argv[])
{

    tree *root = new tree(1);
    root->left = new tree(2);
    root->left->right = new tree(2);
    root->right = new tree(3);
    root->right->left = new tree(3);
    root->right->right = new tree(3);

    cout << MaxWidth(root);
    // // root = NULL;
    // PreOrder(root);
    // InOrder(root);
    // PostOrder(root);
    // csp(Hieght(root));
    // PrintKthNodes(root, 3);
    // LevelOrder(root);
    // LevelOrder2(root);
    // c(SizeOfTree(root));
    // c(MaxInTree(root));
    // RecLeftView(root, 1);
    // RecRightView(root, 1);
    // if (children_sum(root))
    //     cout << "true";
    // else
    //     cout << "false";
    return 0;
}