#include <iostream>
#include <string>
#include <stack>
#include <map>
#include <functional>

using namespace std;

//传入前缀表达式
int PrefixToNumber(const string &str)
{
    std::map<char, std::function<int(int, int)>> opMap ={
            {'+', [](int x, int y){ return x + y; }},
            {'-', [](int x, int y){ return x - y; }},
            {'*', [](int x, int y){ return x * y; }},
            {'/', [](int x, int y){ return x / y; }},
    };
    stack<int> st;
    for (int i = str.length() - 1; i >= 0; i--)
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            st.push(str[i] - '0');
        }
        else
        {
            int left = st.top();
            st.pop();
            int right = st.top();
            st.pop();
            st.push(opMap[str[i]](left,right));
        }
    }
    return st.top();
}

int main()
{
    //1+((2+3)*4)-5 
    cout<<PrefixToNumber("-+1*+2345")<<endl;
    return 0;
}