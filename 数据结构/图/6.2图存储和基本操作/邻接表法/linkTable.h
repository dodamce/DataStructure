#include <iostream>
#include <vector>
#include <assert.h>
#include <unordered_map>

template <class w>
struct Edge
{
    int dstPos = -1;
    w weight; // 权值
    Edge<w> *next;
    Edge(int _dstPos, const w &_weight) : dstPos(_dstPos), weight(_weight), next(nullptr) {}
};

// v:节点的值，w节点的权值 flag==false为无向图
template <class v, class w, bool flag = false>
class linkTable
{
    typedef Edge<w> Edge;

public:
    std::vector<Edge *> _matrix;          // 邻接表
    std::unordered_map<v, int> _indexMap; // 保存图节点对应邻接表数组的下标
    std::vector<v> _points;               // 顶点集合

    int _getPointPos(const v &point)
    {
        typename std::unordered_map<v, int>::iterator pos = _indexMap.find(point);
        if (pos == _indexMap.end())
            return -1; // 没找到
        return pos->second;
    }

public:
    linkTable(const std::vector<v> &src)
    {
        int size = src.size();
        assert(size > 0);
        _points.resize(size);
        for (int i = 0; i < size; i++)
        {
            _points[i] = src[i];
            _indexMap[src[i]] = i;
        }
        _matrix.resize(size, nullptr);
    }

    // 添加边的关系
    void AddEdge(const v &src, const v &dst, const w &weight)
    {
        int posSrc = _getPointPos(src);
        int posDst = _getPointPos(dst);
        assert(posSrc >= 0 && posSrc >= 0);

        // 构建Edge，头插到数组上
        Edge *edge = new Edge(posDst, weight);
        edge->next = _matrix[posSrc];
        _matrix[posSrc] = edge;

        if (!flag)
        {
            // 无向图,两条边都要构建
            edge = new Edge(posSrc, weight);
            edge->next = _matrix[posDst];
            _matrix[posDst] = edge;
        }
    }

    // 打印邻接表信息
    void PrintGraph()
    {
        for (int i = 0; i < _matrix.size(); i++)
        {
            Edge *edge = _matrix[i];
            while (edge != nullptr)
            {
                std::cout << _points[i] << "->";
                std::cout << _points[edge->dstPos] << "权值:" << edge->weight << std::endl;
                edge = edge->next;
            }
            std::cout << "--------------------------------" << std::endl;
        }
    }
};