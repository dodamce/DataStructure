#include "FrontTailList.h"

using namespace std;

int main(int argc, char const *argv[])
{
    FrontTailList graph({'a', 'b', 'c', 'd'}, false);
    graph.AddEdge('a', 'd', 1);
    graph.AddEdge('c', 'd', 2);
    graph.AddEdge('c', 'b', 3);

    graph.PrintGraph();
    cout << graph.InDegree('d') << endl;
    cout << graph.OutDegree('d') << endl;

    FrontTailList graph2({'a', 'b', 'c', 'd'}, true);
    graph2.AddEdge('a', 'd', 1);
    graph2.AddEdge('c', 'd', 2);
    graph2.AddEdge('c', 'b', 3);

    graph2.PrintGraph();

    cout << graph2.InDegree('d') << endl;
    cout << graph2.OutDegree('d') << endl;

    return 0;
}
