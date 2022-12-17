#include "matrix.h"
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

template <class v, class w, w max = INT_MAX, bool flag = false>
int BFS_FindShortest(graph<v, w> &graph, const v begin, const v end)
{
    int beginPos = graph._getPosPoint(begin);
    int endPos = graph._getPosPoint(end);
    vector<int> ret(graph._verPoint.size(), max); // ret[i]为begin到i的最短路径,最后函数返回值应为ret[endPos],ret[i]=max代表begin到i不通，不是连通图
    queue<int> q;
    vector<bool> visit(graph._verPoint.size(), false);
    ret[beginPos] = 0;
    q.push(beginPos);
    int levelSize = 1;
    visit[beginPos] = true;
    int level = 1;
    while (!q.empty())
    {
        for (int i = 0; i < levelSize; i++)
        {
            int font = q.front();
            q.pop();
            for (int j = 0; j < graph._verPoint.size(); j++)
            {
                if (visit[j] == false && graph._matrix[font][j] != max)
                {
                    ret[j] = level;
                    q.push(j);
                    visit[j] = true;
                }
            }
        }
        levelSize = q.size();
        level += 1;
    }
    // 打印最短路径
    for (int i = 0; i < ret.size(); i++)
    {
        cout << graph._verPoint[beginPos] << "到" << graph._verPoint[i] << "的最短路径为" << ret[i] << std::endl;
    }
    return ret[endPos];
}

int main(int argc, char const *argv[])
{
    vector<char> vet = {'a', 'b', 'c', 'd'};
    graph<char, int> graph(vet);
    graph.AddEdge('a', 'd', 1);
    graph.AddEdge('c', 'b', 1);
    graph.AddEdge('c', 'd', 1);
    graph.AddEdge('a', 'c', 1);
    graph.PrintGraph();
    cout<<BFS_FindShortest(graph, 'a', 'd');
    return 0;
}
