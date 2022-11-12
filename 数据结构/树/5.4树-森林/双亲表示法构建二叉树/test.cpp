#include "Tree.h"
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    Tree<int> tree({1, 2, 3, 4, 5, 6, 7, 8, 9});
    cout << tree.getParent(9).data;
    return 0;
}
