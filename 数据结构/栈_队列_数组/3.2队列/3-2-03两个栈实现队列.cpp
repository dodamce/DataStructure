//通过两个栈实现队列,这个队列的功能(push pop empty),只能使用栈的(push pop empty)

//一个栈用来实现push 当pop时，先把一个栈内容全部放入另一个栈上,在输出
#include <iostream>
#include <stack>

namespace nuc
{
    using namespace std;

    class queue
    {
    private:
        stack<int> input;
        stack<int> output;

    public:
        void push(int val)
        {
            input.push(val);
        }

        int pop()
        {
            if (isEmpty())
            {
                //说明队列为空
                cout << "队列为空,无法出队" << endl;
                return -1;
            }

            if (output.empty())
            {
                while (!input.empty())
                {
                    output.push(input.top());
                    input.pop();
                }
            }
            int ret = output.top();
            output.pop();
            return ret;
        }

        bool isEmpty()
        {
            return input.empty() && output.empty();
        }
    };
}; // namespace nuc

void Print(nuc::queue q)
{
    while (!q.isEmpty())
    {
        std::cout << q.pop() << " ";
    }
    std::cout << "\n";
}

int main()
{
    nuc::queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    Print(q);
    q.pop();
    Print(q);
    q.pop();
    Print(q);
    q.pop();
    Print(q);
    q.pop();
    Print(q);
    q.pop();
    Print(q);
    q.pop();
    Print(q);
    q.pop();
    Print(q);
    return 0;
}