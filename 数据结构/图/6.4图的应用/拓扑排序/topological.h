#include <iostream>
#include <vector>
#include <assert.h>
#include <unordered_map>
#include <stack>

template <class w>
struct Edge
{
    int srcPos = -1;
    w weight; // 权值
    Edge<w> *next;
    Edge(int _srcPos, const w &_weight) : srcPos(_srcPos), weight(_weight), next(nullptr) {}
};

// v:节点的值，w节点的权值 flag==false为无向图
template <class v, class w, bool flag = false>
class linkTable
{
    typedef Edge<w> Edge;

private:
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

    // 添加边的关系，储存入度边
    void AddEdge(const v &src, const v &dst, const w &weight)
    {
        int posSrc = _getPointPos(src);
        int posDst = _getPointPos(dst);
        assert(posSrc >= 0 && posSrc >= 0);

        // 构建Edge，头插到数组上
        Edge *edge = new Edge(posSrc, weight);
        edge->next = _matrix[posDst];
        _matrix[posDst] = edge;

        if (!flag)
        {
            // 无向图,两条边都要构建
            edge = new Edge(posSrc, weight);
            edge->next = _matrix[posSrc];
            _matrix[posSrc] = edge;
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
                std::cout << _points[i] << "<-";
                std::cout << _points[edge->srcPos] << "权值:" << edge->weight << std::endl;
                edge = edge->next;
            }
            std::cout << "--------------------------------" << std::endl;
        }
    }

    //---------------------------拓扑排序-----------------
    /**
     * @brief 返回图的拓扑排序是否完成
     *
     * @param buff 有向无环图的拓扑排序结果数组
     * @return true 这个图是完成了拓扑排序
     * @return false 这个图带环，没有拓扑排序
     */
    bool Topological(std::vector<v> &buff)
    {
        std::stack<v> st;
        std::vector<bool> visit(_points.size(), false); // 判断这个节点是否被访问过
        // 储存入度为0节点
        for (size_t i = 0; i < _matrix.size(); ++i)
        {
            if (_matrix[i] == nullptr)
            {
                st.push(i);
                visit[i] = true;
            }
        }

        int count = 0;
        while (!st.empty())
        {
            int top = st.top();
            buff.push_back(_points[top]);
            st.pop();
            count++;

            // 将所有top指向的顶点度-1，如果度为0继续入栈
            for (size_t i = 0; i < _matrix.size(); i++)
            {
                if (_matrix[i] != nullptr)
                {
                    Edge *node = _matrix[i];
                    Edge *prev = nullptr;
                    while (node != nullptr)
                    {
                        if (node->srcPos == top)
                        {
                            if (prev == nullptr)
                            {
                                // 头删
                                _matrix[i] = node->next;
                                delete node;
                                node = _matrix[i];
                            }
                            else
                            {
                                prev->next = node->next;
                                delete node;
                                node = prev->next;
                            }
                        }
                        else
                        {
                            prev = node;
                            node = node->next;
                        }
                    }
                }
            }
            // 储存入度为0节点
            for (size_t i = 0; i < _matrix.size(); ++i)
            {
                if (_matrix[i] == nullptr && visit[i] == false)
                {
                    st.push(i);
                    visit[i] = true;
                }
            }
        }
        return _points.size() == count;
    }
};