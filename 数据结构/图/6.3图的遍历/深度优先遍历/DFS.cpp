#include "../广度优先遍历/matrix.h"

using namespace std;

template <class v, class w, w max = INT_MAX, bool flag = false>
void _DFS(graph<v, w> &graph, int beginPos, vector<bool> &visit)
{
    cout << beginPos << ":" << graph._verPoint[beginPos] << " ";
    visit[beginPos] = true;

    // 这个点周围的点进行遍历
    for (int i = 0; i < graph._verPoint.size(); i++)
    {
        if (visit[i] == false && graph._matrix[beginPos][i] != max)
        {
            _DFS(graph, i, visit);
        }
    }
}

template <class v, class w, w max = INT_MAX, bool flag = false>
void DFS(graph<v, w> &graph, const v begin)
{
    vector<bool> visit(graph._verPoint.size(), false);
    int beginPos = graph._getPosPoint(begin);
    _DFS(graph, beginPos, visit);
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
    DFS(graph, 'a');
    return 0;
}
