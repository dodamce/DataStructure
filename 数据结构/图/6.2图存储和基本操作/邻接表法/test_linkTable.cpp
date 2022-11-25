#include "linkTable.h"

int main(int argc, char const *argv[])
{
    std::cout << "无向图" << std::endl;
    linkTable<char, int> graph({'a', 'b', 'c', 'd'});
    graph.AddEdge('a', 'd', 4);
    graph.AddEdge('c', 'd', 2);
    graph.AddEdge('c', 'b', 4);
    graph.PrintGraph();

    std::cout << "+++++++++++++++++++++++++++++++++" << std::endl;
    std::cout << "有向图" << std::endl;
    linkTable<char, int, true> graph2({'a', 'b', 'c', 'd'});
    graph2.AddEdge('a', 'd', 4);
    graph2.AddEdge('c', 'd', 2);
    graph2.AddEdge('c', 'b', 4);
    graph2.PrintGraph();
    return 0;
}
