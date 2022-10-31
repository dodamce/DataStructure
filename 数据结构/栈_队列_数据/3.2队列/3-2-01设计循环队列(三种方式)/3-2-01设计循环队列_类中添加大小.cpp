//设计循环队列
//添加一个size来区分队列满和队列为空
//队列为空是size==0 满时size==queue.size();
#include <iostream>
#include <vector>

class RoundQueue
{
private:
    std::vector<int> queue;
    int front = 0;
    int back = 0;
    size_t size = 0;

public:
    RoundQueue(size_t size)
    {
        queue.resize(size);
    }

    bool isEmpty()
    {
        return size == 0;
    }

    bool isFull()
    {
        return size == queue.size();
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
        size++;
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
        size--;
        return ret;
    }

    void print()
    {
        int begin = back;
        int times = size;
        while (times > 0)
        {
            std::cout << queue[begin] << " ";
            begin = (begin + 1) % queue.size();
            times--;
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