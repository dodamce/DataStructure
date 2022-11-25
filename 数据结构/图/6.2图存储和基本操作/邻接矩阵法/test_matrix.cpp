#include "matrix.h"

using namespace std;

int main(int argc, char const *argv[])
{
    vector<char> vet = {'a', 'b', 'c', 'd'};
    graph<char, int> graph(vet);
    graph.AddEdge('a', 'd', 1);
    graph.AddEdge('c', 'b', 1);
    graph.AddEdge('c', 'd', 1);
    graph.PrintGraph();
    return 0;
}
