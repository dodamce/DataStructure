//设计循环队列
//空出一个位置来区分队列满和队列为空
//队列为空是front和back指针相同 满时(front+1) % queue.size()==back;
#include <iostream>
#include <vector>

class RoundQueue
{
private:
    std::vector<int> queue;
    int front = 0;
    int back = 0;

public:
    RoundQueue(size_t size)
    {
        //多开一个空间
        queue.resize(size + 1);
    }

    bool isEmpty()
    {
        return front == back;
    }

    bool isFull()
    {
        return (front + 1) % queue.size() == back;
    }

    void push(int val)
    {
        if (isFull())
        {
            std::cout << "循环队列已满无法入队" << std::endl;
            return;
        }
        queue[front] = val;
        front = (front + 1) % queue.size();
    }

    int pop()
    {
        if (isEmpty())
        {
            std::cout << "循环队列为空,无法出队" << std::endl;
            return -1;
        }
        int ret = queue[back];
        back = (back + 1) % queue.size();
        return ret;
    }

    void print()
    {
        int begin = back;
        while (begin != front)
        {
            std::cout << queue[begin] << " ";
            begin = (begin + 1) % queue.size();
        }
        std::cout << std::endl;
    }
};

int main()
{
    RoundQueue queue(4);
    queue.pop();
    queue.push(1);
    queue.push(2);
    queue.push(3);
    queue.push(4);
    queue.print();
    queue.push(5);
    queue.print();
    std::cout << queue.pop() << std::endl;
    queue.print();
    queue.push(5);
    queue.print();
    queue.pop();
    queue.print();
    queue.pop();
    queue.print();
    queue.pop();
    queue.print();
    queue.pop();
    queue.print();
    return 0;
}