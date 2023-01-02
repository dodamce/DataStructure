#include "Dijkstra.h"

using namespace std;

int main(int argc, char const *argv[])
{
    graph<char, int> g({'0', '1', '2', '3', '4', '5', '6'});
    g.AddEdge('0', '1', 2);
    g.AddEdge('0', '2', 6);
    g.AddEdge('1', '3', 5);
    g.AddEdge('2', '3', 8);
    g.AddEdge('3', '5', 15);
    g.AddEdge('3', '4', 10);
    g.AddEdge('4', '5', 6);
    g.AddEdge('4', '6', 2);
    g.AddEdge('6', '5', 6);
    g.PrintGraph();

    vector<int> dist;
    g.Dijkstra('0', dist);

    return 0;
}
