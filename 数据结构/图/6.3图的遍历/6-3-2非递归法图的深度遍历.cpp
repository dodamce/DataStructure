// 图的储存形式采用邻接表的形式
#include "../6.2图存储和基本操作/邻接表法/linkTable.h"
#include <stack>
#include <vector>
using namespace std;

// v:节点的值，w节点的权值 flag==false为无向图
template <class v, class w, bool flag = false>
void DFS(linkTable<v, w, flag> &table)
{
    vector<bool> visit(table._points.size(), false);
    // 默认从图的第一个顶点开始深度优先遍历
    stack<v> s;
    s.push(table._points[0]);
    visit[table._getPointPos(table._points[0])] = true;
    while (!s.empty())
    {
        v p = s.top();
        cout << p << " ";
        s.pop();
        // p点相连的点入栈
        Edge<w> *node = table._matrix[table._getPointPos(p)];
        while (node != nullptr)
        {
            if (visit[node->dstPos] != true)
            {
                // 没有访问过，进栈
                s.push(table._points[node->dstPos]);
                visit[node->dstPos] = true;
            }
            node = node->next;
        }
    }
}

int main(int argc, char const *argv[])
{
    std::cout << "无向图" << std::endl;
    linkTable<char, int> graph({'a', 'b', 'c', 'd'});
    graph.AddEdge('a', 'd', 4);
    graph.AddEdge('c', 'd', 2);
    graph.AddEdge('c', 'b', 4);
    // graph.PrintGraph();
    DFS(graph);
    return 0;
}
