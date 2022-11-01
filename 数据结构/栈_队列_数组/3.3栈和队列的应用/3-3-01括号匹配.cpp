#include <iostream>
#include <string>
#include <stack>

using namespace std;

//[({入栈    })]出栈 ,最后栈为空,说明匹配

bool BrackMatch(const string &str)
{
    stack<char> st;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '(' || str[i] == '{' || str[i] == '[')
        {
            st.push(str[i]);
        }
        else
        {
            if (str[i] == ')')
            {
                char ch = st.top();
                if (ch != '(')
                    return false;
                st.pop();
            }
            else if (str[i] == ']')
            {
                char ch = st.top();
                if (ch != '[')
                    return false;
                st.pop();
            }
            else if (str[i] == '}')
            {
                char ch = st.top();
                if (ch != '{')
                    return false;
                st.pop();
            }
        }
    }
    return st.empty();
}

int main()
{
    cout << BrackMatch("{}(){}[]{([])}") << endl;
    cout << BrackMatch("[1+(3-14)*14+(5-9)*2]") << endl;
    cout << BrackMatch("[()") << endl;
    return 0;
}