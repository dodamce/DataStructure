//顺序存储二叉树的每个节点，数组的值为父节点的下标

//这里练习使用双亲表示法构建层序二叉树

#include <vector>
#include <math.h>

template <class T>
struct Elem
{
    //每个树节点有两个数据，当前的值个父亲节点的位置
    T data;
    int parent;
    Elem(T data, int parent) : data(data), parent(parent) {}
};

template <class T>
class Tree
{
    typedef Elem<T> ElemNode;

public:
    Tree(const std::vector<T> &vet)
    {
        int parent = 0; //第一个父节点
        int times = 0;  //记录父节点有几个孩子
        int level = 0;  //记录这是二叉树的第几次
        int pos = 0;    //记录访问到数组的第几个位置
        while (pos < vet.size())
        {
            if (nodes.empty())
            {
                //第一个节点
                nodes.push_back(ElemNode(vet[pos++], -1));
            }
            else
            {
                //计算这层最多可以有几个节点
                for (int j = 0; j < pow(2, level - 1); j++)
                {
                    nodes.push_back(ElemNode(vet[pos++], parent));
                    times++;
                    if (times == 2)
                    {
                        //这里实现的二叉树，所以当这个节点有两个子节点后父亲节点+1
                        parent++;
                        times = 0;
                    }
                }
            }
            level++;
        }
    }
    std::vector<ElemNode> nodes;
};