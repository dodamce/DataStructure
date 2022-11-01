//首先定义优先级
#include <iostream>
#include <string>
#include <stack>

using namespace std;

int priority(const char ch)
{
    // */优先级相同最大
    int priority = 0;
    if (ch == '*' || ch == '/')
        priority = 2;
    else if (ch == '+' || ch == '-')
        priority = 1;
    else if (ch == '(')
        priority = 0;
    else
        //其他字符优先级错误
        priority = -1;
    return priority;
}

string turnPostfix(string &str)
{
    stack<char> st;
    string ret; //保存中缀转后缀的结果
    for (int i = 0; i < str.size(); i++)
    {
        // cout << str[i] << endl;

        //如果这个字符没有优先级，说明这个字符不是操作符
        if (priority(str[i]) == -1 && str[i] != ')')
        {
            //字符直接输出
            ret.push_back(str[i]);
        }
        else
        {
            if (st.empty())
            {
                st.push(str[i]);
            }
            else
            {
                //如果str[i]==）将栈输出，直到（
                if (str[i] == ')')
                {
                    while (st.top() != '(')
                    {
                        ret.push_back(st.top());
                        st.pop();
                    }
                    //将（弹出栈
                    st.pop();
                }
                else
                {
                    //如果是(直接入栈
                    if (str[i] == '(')
                    {
                        st.push(str[i]);
                    }
                    else
                    {
                        //将优先级大于这个操作符的字符出栈输出
                        cout << "INFO:" << st.top() << endl;
                        while (!st.empty() && priority(st.top()) >= priority(str[i]))
                        {
                            ret.push_back(st.top());
                            st.pop();
                        }
                        //将这个操作符号入栈
                        st.push(str[i]);
                    }
                }
            }
        }
    }
    //将栈剩下的元素全部出栈
    while (!st.empty())
    {
        ret.push_back(st.top());
        st.pop();
    }
    return ret;
}

int main()
{
    string input = "2+4*8+(8*8+1)/3";

    cout << turnPostfix(input) << endl;
    return 0;
}
