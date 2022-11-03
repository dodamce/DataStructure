/**
 * @file 3-3-03利用栈实现递归.cpp
 * @author your name (you@domain.com)
 * @brief
 * Pn(x)={
 *   1 (n==0)
 *   2*x (n==1)
 *   2xPn-1(x)-2(n-1)Pn-2(x) (x>1)
 * }
 * @version 0.1
 * @date 2022-11-01
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>
#include <vector>

using namespace std;

// 栈内的元素，包括下标n和fn(x)的值
struct Elem
{
    int n;
    int fx;
    Elem(int _n) : n(_n), fx(0) {}
};

int calculate(int x, int n)
{
    vector<Elem> st; //使用数组模拟栈
    // n==0和n==1的初值
    int first = 1;
    int second = 2 * x;
    int top = -1;
    for (int i = n; i >= 2; i--)
    {
        //入栈
        st.push_back(Elem(i));
        top += 1;
    }
    //出栈
    while (top >= 0)
    {
        st[top].fx = 2 * x * second - 2 * (st[top].n - 1) * first;
        first = second;
        second = st[top].fx;
        top--;
    }
    //最后栈顶元素就是所求值
    return second;
}

int main()
{
    cout << calculate(2, 3) << endl;
    return 0;
}