//首先定义优先级
#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

int priority(const char ch)
{
    // */优先级相同最大
    int priority = 0;
    if (ch == '*' || ch == '/')
        priority = 2;
    else if (ch == '+' || ch == '-')
        priority = 1;
    else if (ch == ')')
        priority = 0;
    else
        //其他字符优先级错误
        priority = -1;
    return priority;
}

string turnPrefix(const string &str)
{
    string ret;
    stack<char> st;
    for (int i = str.length() - 1; i >= 0; i--)
    {
        // cout << str[i] << " " << endl;
        if (priority(str[i]) == -1 && str[i] != '(')
        {
            //数字,直接输出到ret上即可
            ret.push_back(str[i]);
        }
        else
        {
            if (str[i] == '(')
            {
                //弹出栈，直到遇到)
                while (st.top() != ')')
                {
                    ret.push_back(st.top());
                    st.pop();
                }
                //将')'弹出栈
                st.pop();
            }
            else
            {
                if (st.empty())
                {
                    st.push(str[i]);
                }
                else
                {
                    if (str[i] == ')')
                    {
                        //右括号直接入栈
                        st.push(str[i]);
                    }
                    else
                    {
                        //栈优先级大的出栈
                        while (!st.empty() && priority(st.top()) > priority(str[i]))
                        {
                            ret.push_back(st.top());
                            st.pop();
                        }
                        //将这个操作符入栈
                        st.push(str[i]);
                    }
                }
            }
        }
    }
    while (!st.empty())
    {
        ret.push_back(st.top());
        st.pop();
    }

    std::reverse(ret.begin(), ret.end());
    return ret;
}

int main()
{
    string input = "1+((2+3)*4)-5";
    cout << turnPrefix(input) << endl;
    return 0;
}