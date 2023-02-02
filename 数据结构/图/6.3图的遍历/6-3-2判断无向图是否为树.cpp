/**

深度遍历这个无向图，统计访问的顶点数和边数，如果顶点个数为n,边为n-1条，则这个无向图是树状
 *
 */

#include "./广度优先遍历/matrix.h"
#include <vector>

void DFS(graph<char, int> &g, std::vector<bool> &visit, int beginPos, int &point, int &weight)
{
    visit[beginPos] = true;
    point++;
    for (int i = 0; i < g._verPoint.size(); i++)
    {
        if (g._matrix[beginPos][i] != INT_MAX)
        {
            weight++;
            if (visit[i] != true)
            {
                DFS(g, visit, i, point, weight);
            }
        }
    }
}
/**
 * @brief 判断无向图是否是树状
 *
 * @param g 储存无向图的数据结构
 * @return true 是树状
 * @return false 不是树状
 */
bool isTree(graph<char, int> &g)
{
    std::vector<bool> visit(g._verPoint.size(), false);
    int beginPos = g._getPosPoint(g._verPoint[0]);
    int point = 0;
    int weight = 0;
    DFS(g, visit, beginPos, point, weight);
    return point == g._verPoint.size() && weight / 2 == point - 1;
}

int main(int argc, char const *argv[])
{
    std::vector<char> vet = {'a', 'b', 'c', 'd'};
    graph<char, int> graph(vet);
    graph.AddEdge('a', 'b', 1);
    graph.AddEdge('a', 'c', 1);
    graph.AddEdge('b', 'd', 1);
    // graph.AddEdge('d', 'c', 1);
    graph.PrintGraph();
    std::cout << isTree(graph) << std::endl;
    return 0;
}
