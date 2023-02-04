// 有向图采用邻接表的方法储存

#include "../6.2图存储和基本操作/邻接表法/linkTable.h"
#include <vector>

#include <queue>

using namespace std;

template <class v, class w, bool flag = true>
void DFS(linkTable<v, w, flag> &table, vector<bool> &visit, const v &begin, const v &end, bool &ret)
{
    visit[table._getPointPos(begin)] = true;
    if (begin == end)
    {
        ret = true;
    }
    else
    {
        Edge<w> *node = table._matrix[table._getPointPos(begin)];
        while (node != nullptr)
        {
            if (visit[node->dstPos] != true)
            {
                DFS(table, visit, table._points[node->dstPos], end, ret);
            }
            node = node->next;
        }
    }
}

// flag==true代表有向图
template <class v, class w, bool flag = true>
bool HavePathByDFS(linkTable<v, w, flag> &table, const v &begin, const v &end)
{
    vector<bool> visit(table._points.size(), false);
    bool ret = false; // 记录是否找到路径
    DFS(table, visit, begin, end, ret);
    return ret;
}

template <class v, class w, bool flag = true>
void BFS(linkTable<v, w, flag> &table, vector<bool> &visit, const v &begin, const v &end, bool &ret)
{
    queue<v> q;
    q.push(begin);
    while (!q.empty())
    {
        v point = q.front();
        if (point == end)
        {
            ret = true;
            break;
        }
        q.pop();
        visit[table._getPointPos(point)] = true;
        Edge<w> *node = table._matrix[table._getPointPos(point)];
        while (node != nullptr)
        {
            q.push(table._points[node->dstPos]);
            node = node->next;
        }
    }
}

// flag==true代表有向图
template <class v, class w, bool flag = true>
bool HavePathByBFS(linkTable<v, w, flag> &table, const v &begin, const v &end)
{
    vector<bool> visit(table._points.size(), false);
    bool ret = false; // 记录是否找到路径
    BFS(table, visit, begin, end, ret);
    return ret;
}

int main(int argc, char const *argv[])
{
    linkTable<char, int, true> graph({'a', 'b', 'c', 'd'});
    graph.AddEdge('a', 'd', 4);
    graph.AddEdge('c', 'd', 2);
    graph.AddEdge('c', 'b', 4);
    // graph.AddEdge('d', 'c', 1);
    // graph.PrintGraph();
    // cout << HavePathByDFS(graph, 'a', 'c') << endl;
    cout << HavePathByBFS(graph, 'a', 'c') << endl;
    return 0;
}
