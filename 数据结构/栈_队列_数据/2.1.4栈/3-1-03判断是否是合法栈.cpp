//根据题目的操作，使用C++的stack STL类即可,比较简单

#include <stack>
#include <iostream>
#include <string>

using namespace std;

//判断是否是合法栈:合法栈(出栈入栈最后栈为空)I入栈 O出栈
bool isLegal(const string &op)
{
    stack<char> st;
    // op保存对栈的操作
    for (int i = 0; i < op.size(); i++)
    {
        if (op[i] == 'I')
        {
            st.push('I');
        }
        else if (op[i] == 'O')
        {
            if (st.empty())
            {
                return false;
            }
            st.pop();
        }
    }
    return st.empty();
}

int main()
{
    // cout << isLegal("IOIIOIOO") << endl;
    // cout << isLegal("IOOIOIIO") << endl;
    // cout << isLegal("IIIOIOIO") << endl;
    // cout << isLegal("IIIOOIOO") << endl;
    return 0;
}