//函数通过string的方式(也可以使用vector道理类似)传入一个入栈顺序和一个待判断出栈序列

//判断这个出栈顺序是否合法,如果合法则返回true,如果不合法则返回false

#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool isLegalStack(const string &in, const string &out)
{
    if (in.size() != out.size())
    {
        return false;
    }
    //使用辅助栈
    stack<int> st;
    int pos = 0;
    for (int i = 0; i < in.size(); i++)
    {
        st.push(in[i]);
        while (!st.empty() && st.top() == out[pos])
        {
            st.pop();
            pos++;
        }
    }

    return pos == out.size();
}

int main()
{
    cout << isLegalStack("abcdef", "cabdef");
    return 0;
}