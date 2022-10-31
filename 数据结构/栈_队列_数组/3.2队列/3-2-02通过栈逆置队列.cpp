#include <iostream>
#include <queue>
#include <stack>

using namespace std;

//通过栈逆置队列
template <class Elem>
void reverse(queue<Elem> &queue)
{
    if (queue.size() == 0 || queue.size() == 1)
    {
        return;
    }
    stack<Elem> st;
    while (!queue.empty())
    {
        st.push(queue.front());
        queue.pop();
    }

    while (!st.empty())
    {
        queue.push(st.top());
        st.pop();
    }
}
template <class Elem>
void Print(queue<Elem> q)
{
    while (!q.empty())
    {
        std::cout << q.front() << " ";
        q.pop();
    }
    std::cout << "\n";
}

int main()
{
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    Print(q);
    reverse(q);
    Print(q);
    return 0;
}
