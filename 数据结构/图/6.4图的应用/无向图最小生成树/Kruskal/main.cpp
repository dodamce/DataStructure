#include "matrix.h"

using namespace std;

int main(int argc, char const *argv[])
{
    vector<char> vet = {'a', 'b', 'c', 'd', 's', 't'};
    graph<char, int> Graph(vet);
    Graph.AddEdge('a', 'b', 6);
    Graph.AddEdge('b', 't', 5);
    Graph.AddEdge('t', 'd', 2);
    Graph.AddEdge('d', 'c', 3);
    Graph.AddEdge('c', 's', 8);
    Graph.AddEdge('s', 'a', 7);
    Graph.AddEdge('c', 'a', 3);
    Graph.AddEdge('c', 's', 8);
    Graph.AddEdge('b', 'd', 2);
    Graph.PrintGraph();

    graph<char, int> minGraph;
    cout << "最小生成树总权值：" << Graph.kruskal(minGraph) << endl;
    minGraph.PrintGraph();
    return 0;
}