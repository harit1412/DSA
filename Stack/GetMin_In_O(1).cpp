#include <bits/stdc++.h>
using namespace std;
class St
{
    stack<int> s;
    stack<int> temp;
    void push(int x)
    {
        if (temp.empty())
        {
            temp.push(x);
        }
        else
        {
            if (x < temp.top())
            {

                temp.push(x);
            }
        }
        s.push(x);
    }
    void pop()
    {
        if (s.top() == temp.top())
        {
            temp.pop();
        }
        s.pop();
    }
    bool isEmpty()
    {
        return s.empty();
    }
    int GetMin()
    {
        return temp.top();
    }
};
int main(int argc, char const *argv[])
{

    return 0;
}