#include <iostream>

#include <vector>

// true向左栈插入，false向右栈插入
class ShareStack
{
private:
    std::vector<int> share_stack;
    int leftBottom;
    int leftTop;
    int rightBotton;
    int rightTop;

public:
    ShareStack(size_t size)
    {
        share_stack.resize(size);
        leftBottom = -1;
        leftTop = -1;
        rightBotton = share_stack.size();
        rightTop = rightBotton;
    }

    bool isFull()
    {
        // return (leftTop - leftBottom) + (rightButton - rightTop) == share_stack.size();
        return rightTop - leftTop == 1;
    }
    bool leftEmpty()
    {
        return leftBottom == leftTop;
    }
    bool rightEmpty()
    {
        return rightBotton == rightTop;
    }

    bool push(bool choice, int val)
    {
        if (isFull())
        {
            std::cout << "共享栈满了无法插入" << std::endl;
            return false;
        }
        if (choice == true)
        {
            share_stack[++leftTop] = val;
        }
        else
        {
            share_stack[--rightTop] = val;
        }
        return true;
    }

    int pop(bool choice)
    {
        if (choice == true)
        {
            if (leftEmpty())
            {
                std::cout << "左栈为空,无法出栈" << std::endl;
            }
            return share_stack[leftTop--];
        }
        else
        {
            if (rightEmpty())
            {
                std::cout << "右栈为空,无法出栈" << std::endl;
            }
            return share_stack[rightTop++];
        }
    }

    void print()
    {
        std::cout << "左栈底 ";
        for (int i = 0; i <= leftTop; i++)
        {
            std::cout << share_stack[i] << " ";
        }
        std::cout << "左栈顶 ";

        std::cout << "右栈顶 ";
        for (int i = rightTop; i < rightBotton; i++)
        {
            std::cout << share_stack[i] << " ";
        }
        std::cout << "右栈底" << std::endl;
    }
};

int main()
{
    ShareStack stack(4);
    stack.push(true, 1);
    stack.push(false, 2);
    stack.push(true, 3);
    stack.push(false, 4);
    stack.print();
    stack.push(true, 5);
    stack.print();
    std::cout << stack.pop(false) << std::endl;
    stack.push(true, 5);
    stack.print();
    std::cout << stack.pop(true) << std::endl;
    stack.print();
    return 0;
}
