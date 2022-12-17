#include "matrix.h"
#include <queue>
#include <vector>

using namespace std;

template <class v, class w, w max = INT_MAX, bool flag = false>
void BFS(graph<v, w> &graph, const v begin)
{
    int beginPos = graph._getPosPoint(begin);
    queue<int> q;
    q.push(beginPos);
    // 标记数组
    vector<bool> visit(graph._matrix.size(), false);
    visit[beginPos] = true;
    int levelSize = 1;
    while (!q.empty())
    {
        for (int i = 0; i < levelSize; i++)
        {
            int font = q.front();
            cout << font << ":" << graph._verPoint[font];
            q.pop();

            // 这个节点的周围节点入队列
            for (int j = 0; j < graph._verPoint.size(); j++)
            {
                if (graph._matrix[font][j] != max)
                {
                    if (visit[j] == false)
                    {
                        q.push(j);
                        visit[j] = true;
                    }
                }
            }
        }
        levelSize = q.size();
        cout << "\n";
    }
    cout << "\n";
}

int main(int argc, char const *argv[])
{
    vector<char> vet = {'a', 'b', 'c', 'd'};
    graph<char, int> graph(vet);
    graph.AddEdge('a', 'd', 1);
    graph.AddEdge('c', 'b', 1);
    graph.AddEdge('c', 'd', 1);
    graph.PrintGraph();
    BFS(graph, 'b');
    return 0;
}
