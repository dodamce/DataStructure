#include <iostream>
#include <string>
#include <stack>
#include <map>
#include <functional>
#include <pthread.h>

using namespace std;

//传入后缀表达式
int PostfixToNumber(const string &str)
{
    std::map<char, std::function<int(int, int)>> opMap ={
            {'+', [](int x, int y){ return x + y; }},
            {'-', [](int x, int y){ return x - y; }},
            {'*', [](int x, int y){ return x * y; }},
            {'/', [](int x, int y){ return x / y; }},
    };

    stack<int> st;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            st.push(str[i] - '0');
        }
        else
        {
            int right = st.top();
            st.pop();
            int left = st.top();
            st.pop();
            //实际上就是switch case 不同的运算符执行不同的运算，我这里使用C++11包装器
            st.push(opMap[str[i]](left,right));
        }
    }
    return st.top();
}

int main()
{
    //"2+4*8+(8*8+1)/3"
    cout<<PostfixToNumber("248*+88*1+3/+")<<endl;
}