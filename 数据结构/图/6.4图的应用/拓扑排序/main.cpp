#include "topological.h"

int main(int argc, char const *argv[])
{
    linkTable<char, int, true> graph({'1', '2', '3', '4', '5'});
    graph.AddEdge('1', '4', 1);
    graph.AddEdge('1', '2', 1);
    graph.AddEdge('2', '4', 1);
    graph.AddEdge('2', '3', 1);
    graph.AddEdge('4', '3', 1);
    graph.AddEdge('4', '5', 1);
    graph.AddEdge('3', '5', 1);
    graph.PrintGraph();
    std::vector<char> buff;
    std::cout << graph.Topological(buff) << "\n";
    for (auto num : buff)
    {
        std::cout << num << " ";
    }
    return 0;
}
