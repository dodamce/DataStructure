// 图采用邻接表法进行储存
#include "../6.2图存储和基本操作/邻接表法/linkTable.h"
#include <vector>
#include <algorithm>

using namespace std;

/**
 * @brief 返回邻接表图中两个点之间的路径
 *
 * @tparam v 点类型模板
 * @tparam w 图边权值模板
 * @tparam flag flag==false无向图 flag==true有向图
 * @param table 邻接表储存的图
 * @param begin 起点
 * @param end 终点
 * @param buff 输入输出参数，输出两点的所有路径
 */
template <class v, class w, bool flag = false>
void PrintPath(linkTable<v, w, flag> &table, const v &begin, const v &end, vector<vector<v>> &buff)
{
    vector<bool> visit(table._points.size(), false);
    vector<v> path;
    visit[table._getPointPos(begin)] = true;
    DFS(table, visit, begin, end, path, buff);
}

template <class v, class w, bool flag = false>
void DFS(linkTable<v, w, flag> &table, vector<bool> &visit, const v &begin, const v &end, vector<v> path, vector<vector<v>> &buff)
{
    if (begin == end)
    {
        path.push_back(end);
        buff.push_back(path);
    }
    // 相邻边深度遍历
    Edge<w> *node = table._matrix[table._getPointPos(begin)];
    while (node != nullptr)
    {
        if (visit[node->dstPos] != true)
        {
            path.push_back(begin);
            visit[node->dstPos] = true;
            DFS(table, visit, table._points[node->dstPos], end, path, buff);
            visit[node->dstPos] = false;
            path.pop_back();
        }
        node = node->next;
    }
}

int main(int argc, char const *argv[])
{
    linkTable<char, int, false> graph({'a', 'b', 'c', 'd'});
    graph.AddEdge('a', 'd', 4);
    graph.AddEdge('c', 'd', 2);
    graph.AddEdge('c', 'b', 4);
    graph.AddEdge('a', 'c', 1);
    vector<vector<char>> buff;
    PrintPath(graph, 'a', 'c', buff);
    for (auto &item : buff)
    {
        for (auto &num : item)
        {
            cout << num << " ";
        }
        cout << "\n";
    }
    return 0;
}
