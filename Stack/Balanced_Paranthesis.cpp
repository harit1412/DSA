#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    stack<int> st;
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++)
    {
        if (s.at(i) == '}')
        {
            if (st.empty()) // For First character is } then it will give segmation fault if we do not write this
            {
                st.push(-1);
                break;
            }
            if (st.top() == '{')
            {
                st.pop();
            }
            else
                break;
        }
        else if (s.at(i) == ')')
        {

            if (st.empty())
            {
                st.push(-1);
                break;
            }
            if (st.top() == '(')
            {
                st.pop();
            }
            else
                break;
        }
        else if (s.at(i) == ']')
        {
            if (st.empty())
            {
                st.push(-1);
                break;
            }
            if (st.top() == '[')
            {
                st.pop();
            }
            else
                break;
        }
        else
        {
            st.push(s.at(i));
        }
    }
    // cout << st.size() << endl;;

    if (st.empty())
        cout << "YES";
    else
        cout << "NO";

    return 0;
}