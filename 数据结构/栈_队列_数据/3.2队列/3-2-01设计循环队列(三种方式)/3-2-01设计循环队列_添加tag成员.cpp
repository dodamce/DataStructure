//成员变量中添加tag变量
//进队时tag设置1,出队tag设置0
//当front==back && tag==1时说明队列满了 front==back && tag==0说明队列空
//因为只有入队才可能导致队列满,front==back && tag==1说明入队导致了front==back,队列已满

#include <iostream>
#include <vector>

class RoundQueue
{
private:
    std::vector<int> queue;
    int front = 0;
    int back = 0;
    int tag = 0;

public:
    RoundQueue(size_t size)
    {
        queue.resize(size);
    }

    bool isEmpty()
    {
        return front == back && tag == 0;
    }

    bool isFull()
    {
        return front == back && tag == 1;
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
        tag = 1;
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
        tag == 0;
        return ret;
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
    queue.push(5);
    std::cout << queue.pop() << std::endl;
    queue.push(5);
    std::cout << queue.pop() << std::endl;
    std::cout << queue.pop() << std::endl;
    std::cout << queue.pop() << std::endl;
    std::cout << queue.pop() << std::endl;
    return 0;
}