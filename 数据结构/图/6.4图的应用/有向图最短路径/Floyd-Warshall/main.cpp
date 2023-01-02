#include "Floyd-Warshall.h"

using namespace std;

int main(int argc, char const *argv[])
{
    graph<char, int, INT_MAX, true> g({'1', '2', '3', '4'});
    g.AddEdge('1', '2', 3);
    g.AddEdge('1', '4', 5);
    g.AddEdge('2', '1', 2);
    g.AddEdge('4', '3', 2);
    g.AddEdge('2', '4', 4);
    g.AddEdge('3', '2', 1);
    g.PrintGraph();

    vector<vector<int>> vDist;
    vector<vector<int>> vPath;
    g.FloydWarShall(vDist, vPath);
    g.PrintFloyd(vDist, vPath);
    return 0;
}
