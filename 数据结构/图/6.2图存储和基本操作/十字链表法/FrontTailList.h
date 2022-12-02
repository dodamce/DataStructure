#include <iostream>
#include <unordered_map>
#include <vector>
#include <assert.h>

struct Data
{
    int tailpos = -1; //弧尾在顺序表的位置下标
    int headpos = -1; //弧头在顺序表的位置下标
    Data *head_link = nullptr;
    Data *tail_link = nullptr;
    // head_lik指向下一个以当前顶点为弧头的弧结点；(指入这个节点)
    // tail_link 指向下一个以当前顶点为弧尾的弧结点；(指出这个节点)

    int weight; //保存弧权值
};

struct TableNode
{
    char val = 0; //图节点的值
    Data *in = nullptr;
    Data *out = nullptr;
    //指向以该顶点为弧头(指入这个节点)和弧尾(指出这个节点)的链表首个结点
};

class FrontTailList
{
private:
    std::vector<TableNode> _verPoint;        //顶点集合
    std::unordered_map<char, int> _indexMap; //顶点与下标的映射
    std::vector<std::vector<int>> _matrix;   //邻接矩阵

    bool flag = false; //标记这个图是有向还是无向,false默认无向
    bool isDel = false;

    int _getPosPoint(const char point)
    {
        if (_indexMap.find(point) != _indexMap.end())
        {
            return _indexMap[point];
        }
        else
        {
            std::cout << point << " not found" << std::endl;
            return -1;
        }
    }

public:
    FrontTailList(const std::vector<char> &src, bool flag)
    {
        this->flag = flag;
        _verPoint.resize(src.size());
        _matrix.resize(src.size());
        for (int i = 0; i < src.size(); i++)
        {
            _indexMap[src[i]] = i;
            _matrix[i].resize(src.size(), INT_MAX);
        }
    }

    void AddEdge(const char pointA, const char pointB, int weight)
    {
        int indexA = _getPosPoint(pointA);
        int indexB = _getPosPoint(pointB);
        assert(indexA >= 0 && indexB >= 0);
        _matrix[indexA][indexB] = weight;

        Data *link = new Data;
        link->headpos = indexB;
        link->tailpos = indexA;
        link->weight = weight;
        //采用头插法插入新的节点

        // indexB的入度节点就是pointA这个节点，这里选择头插法插入。
        link->head_link = _verPoint[indexB].in;
        link->tail_link = _verPoint[indexA].out;

        _verPoint[indexB].in = link;
        _verPoint[indexA].out = link;

        if (!flag && !isDel)
        {
            //无向图
            isDel = true; //记录这次的无向图，两条边已经处理过了。
            AddEdge(pointB, pointA, weight);
        }
        //退出条件后说明这条边添加完毕，为了下次添加边的时候还可以解决无向图问题，这里将isDel恢复原状
        isDel = false;
    }

    //打印邻接矩阵
    void PrintGraph()
    {
        //打印顶点对应的坐标
        typename std::unordered_map<char, int>::iterator pos = _indexMap.begin();
        while (pos != _indexMap.end())
        {
            std::cout << pos->first << ":" << pos->second << std::endl;
            pos++;
        }
        std::cout << std::endl;

        //打印边
        printf("  ");
        for (int i = 0; i < _verPoint.size(); i++)
        {
            std::cout << _verPoint[i].val << " ";
        }
        printf("\n");

        for (int i = 0; i < _matrix.size(); i++)
        {
            std::cout << _verPoint[i].val << " ";
            for (int j = 0; j < _matrix[i].size(); j++)
            {
                if (_matrix[i][j] == INT_MAX)
                {
                    //这条边不通
                    printf("∞ ");
                }
                else
                {
                    std::cout << _matrix[i][j] << " ";
                }
            }
            printf("\n");
        }
        printf("\n");
    }

    //计算某个点的出度和入度
    int InDegree(const char point)
    {
        int pos = _getPosPoint(point);
        if (pos < 0)
        {
            std::cout << "图中没有这个节点" << std::endl;
            return -1;
        }
        int ret = 0;
        Data *node = _verPoint[pos].in;
        while (node != nullptr)
        {
            ret += 1;
            node = node->head_link;
        }
        return ret;
    }

    int OutDegree(const char point)
    {
        int pos = _getPosPoint(point);
        if (pos < 0)
        {
            std::cout << "图中没有这个节点" << std::endl;
            return -1;
        }
        int ret = 0;

        Data *node = _verPoint[pos].out;
        while (node != nullptr)
        {
            ret += 1;
            node = node->tail_link;
        }
        return ret;
    }
};
