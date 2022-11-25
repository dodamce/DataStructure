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
    std::cout << graph.Adjacent('a', 'd') << " " << graph.Adjacent('a', 'b') << endl;
    vector<char> ret = graph.GetNeighborsPoint('c');
    for (int i = 0; i < ret.size(); i++)
    {
        std::cout << 'c' << "->" << ret[i] << std::endl;
    }
    graph.InsertVertex('e');
    graph.PrintGraph();

    // graph.DeleteVertex('a');
    // graph.PrintGraph();
    graph.RemoveEdge('a', 'd');
    graph.PrintGraph();
    return 0;
}
