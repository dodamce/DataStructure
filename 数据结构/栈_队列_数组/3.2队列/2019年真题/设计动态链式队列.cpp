/**
【2019统考真题】请设计一个队列，要求满足:
①初始时队列为空;
②入队时，允许增加队列占用空间;  ----链式结构
③出队后，出队元素所占用的空间可重复使用，即整个队列所占用的空间只增不减; ---环形结构
④入队操作和出队操作的时间复杂度始终保持为O(1)

1）该队列是应选择链式存储结构,还是应选择顺序存储结构?
    需要增加队列长度,需要使用链式存储(不带头循环单向链表)

2）画出队列的初始状态，并给出判断队空和队满的条件.
    队列初始状态
    Node*front; //记录队头
    Node*back; //记录队尾
    struct Node{
        int val;
        Node* next=nullptr;
    };
    front=back=head;

    判空条件:
    front==back
    判满条件:(空出一个空间判满)
    back->next==front;

3）画出第一个元素入队后的队列状态。
    连续创建两个节点front back
    front->next=node;
    back->val=val;

    front->val=-1;
    back->next=front;
    back=back;

4）给出入队操作和出队操作的基本过程.
    出队操作front=front->next;
    入队操作back=back->next;
    入队时判断是否满,如果满了创建新节点连接到头上
    出队时判空,如果空不能继续出队
 */

#include <iostream>

struct Node
{
    int val;
    Node *next = nullptr;
    Node(int val) : val(val) {}
};

namespace nuc
{
    using namespace std;
    class queue
    {
    private:
        Node *front;
        Node *back;

    public:
        queue() : front(nullptr), back(nullptr) {}

        bool isEmpty()
        {
            return back == front;
        }

        bool isFull()
        {
            return back->next == front;
        }

        void push(int val)
        {
            if (isEmpty())
            {
                if (front == nullptr)
                {
                    //第一次插入节点
                    front = new Node(val);
                    back = new Node(-1);
                    front->next = back;
                    back->next = front;
                }
                else
                {
                    front->val = val;
                    back = back->next;
                }
            }
            else
            {
                if (isFull())
                {
                    cout << "扩容成功" << endl;
                    Node *node = new Node(-1);
                    node->next = back->next;
                    back->next = node;
                }
                back->val = val;
                back = back->next;
            }
        }

        int pop()
        {
            if (isEmpty())
            {
                cout << "队列为空,无法出队列" << endl;
                return -1;
            }
            int ret = front->val;
            front = front->next;
            return ret;
        }

        void print()
        {
            Node *node = front;
            while (node != back)
            {
                cout << node->val << " ";
                node = node->next;
            }
            cout << "\n";
        }

        ~queue()
        {
            while (!isEmpty())
            {
                Node *node = back->next;
                delete back;
                back = node;
            }
            delete back;
        }
    };
}

int main()
{
    nuc::queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.print();
    q.pop();
    q.print();
    q.pop();
    q.print();
    q.pop();
    q.print();
    q.pop();
    q.print();
    q.pop();
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.print();
    return 0;
}