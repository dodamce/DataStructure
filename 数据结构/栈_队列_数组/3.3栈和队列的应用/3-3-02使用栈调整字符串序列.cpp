//按照题目的意思,使用栈,让字符串的S在前,H在后
#include <iostream>
#include <string>
#include <stack>

using namespace std;

void adjust(string &str)
{
    //记录下标
    stack<char> st;
    int node = 0;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == 'H')
        {
            st.push('H');
        }
        else
        {
            //将S放到前面
            str[node++] = str[i];
        }
    }
    //将栈内的元素插入到str后面
    while (!st.empty())
    {
        str[node++] = st.top();
        st.pop();
    }
}

int main()
{
    string str = "HSHHSSHHSSSHS";
    cout << str.length() << endl;
    adjust(str);
    cout << str.length() << endl;
    cout << str << endl;
    return 0;
}