//邻接矩阵法存储图结构

#include <iostream>
#include <assert.h>
#include <map>
#include <vector>
#include <stdio.h>

// v:图顶点保存的值。w:边的权值 max:最大权值，代表无穷。flag=true代表有向图。否则就是无向图
template <class v, class w, w max = INT_MAX, bool flag = false>
class graph
{
private:
    std::vector<v> _verPoint;            //顶点集合
    std::map<v, int> _indexMap;          //顶点与下标的映射
    std::vector<std::vector<w>> _matrix; //邻接矩阵

    int _getPosPoint(const v &point)
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
    //根据数组来开辟邻接矩阵
    graph(const std::vector<v> &src)
    {
        _verPoint.resize(src.size());
        for (int i = 0; i < src.size(); i++)
        {
            _verPoint[i] = src[i];
            _indexMap[src[i]] = i;
        }

        //初始化邻接矩阵
        _matrix.resize(src.size());
        for (int i = 0; i < src.size(); i++)
        {
            _matrix[i].resize(src.size(), max);
        }
    }

    //添加边的关系,输入两个点，以及这两个点连线边的权值。
    void AddEdge(const v &pointA, const v &pointB, const w &weight)
    {
        //获取这个顶点在邻接矩阵中的下标
        int posA = _getPosPoint(pointA);
        int posB = _getPosPoint(pointB);
        _matrix[posA][posB] = weight;
        if (!flag)
        {
            //无向图,邻接矩阵对称
            _matrix[posB][posA] = weight;
        }
    }

    //打印邻接矩阵
    void PrintGraph()
    {
        //打印顶点对应的坐标
        typename std::map<v, int>::iterator pos = _indexMap.begin();
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
            std::cout << _verPoint[i] << " ";
        }
        printf("\n");

        for (int i = 0; i < _matrix.size(); i++)
        {
            std::cout << _verPoint[i] << " ";
            for (int j = 0; j < _matrix[i].size(); j++)
            {
                if (_matrix[i][j] == max)
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

    //判断图是否存在边<x,y>或(x,y)
    bool Adjacent(const v &x, const v &y)
    {
        return _matrix[_indexMap[x]][_indexMap[y]] != max;
    }

    //列出图中x相邻的边
    std::vector<v> GetNeighborsPoint(const v &x)
    {
        int index = _indexMap[x];
        assert(index >= 0);
        std::vector<v> result;
        for (int i = 0; i < _matrix[index].size(); i++)
        {
            if (_matrix[index][i] != max)
            {
                // std::cout << x << "->" << _verPoint[i] << std::endl;
                result.push_back(_verPoint[i]);
            }
        }
        return result;
    }

    // 在图中插入节点x
    void InsertVertex(const v &x)
    {
        _verPoint.push_back(x);
        _indexMap[x] = _verPoint.size() - 1;
        for (int i = 0; i < _matrix.size(); i++)
        {
            _matrix[i].push_back(max);
        }
        std::vector<w> newLine(_verPoint.size(), max);
        _matrix.push_back(newLine);
    }

    //在图中删除节点x
    void DeleteVertex(const v &x)
    {
        int pos = _indexMap[x];
        assert(pos >= 0);
        _verPoint.erase(_verPoint.begin() + pos);
        _indexMap.erase(x);
        _matrix.erase(_matrix.begin() + pos);
        for (int i = 0; i < _matrix.size(); i++)
        {
            _matrix[i].erase(_matrix[i].begin() + pos);
        }
    }

    //删除边<x，y>或(x，y)
    void RemoveEdge(const v &x, const v &y)
    {
        //假定x,y存在，减少代码量
        _matrix[_indexMap[x]][_indexMap[y]] = max;
        if (!flag)
        {
            //无向图
            _matrix[_indexMap[y]][_indexMap[x]] = max;
        }
    }

    //设置边的权值（添加边）
    void SetEdgeValue(const v &x, const v &y, const w &z)
    {
        //假定x,y存在，减少代码量
        _matrix[_indexMap[x]][_indexMap[y]] = z;
        if (!flag)
        {
            //无向图
            _matrix[_indexMap[y]][_indexMap[x]] = z;
        }
    }
};