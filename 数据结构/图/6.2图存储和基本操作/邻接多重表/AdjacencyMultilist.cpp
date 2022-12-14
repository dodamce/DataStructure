#include "./AdjacencyMultilist.h"

int main(int argc, char const *argv[])
{
    AdjacencyMultilist graph({'a', 'b', 'c', 'd'});

    graph.AddEdge('a', 'b', 10);
    graph.AddEdge('c', 'b', 1);
    graph.AddEdge('c', 'd', 5);
    graph.PrintGraph();

    // graph.DelEdge('c', 'b');
    // graph.PrintGraph();
    return 0;
}
