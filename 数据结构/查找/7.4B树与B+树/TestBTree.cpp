#include "BTree.h"

using namespace std;

int main(int argc, char const *argv[])
{
    vector<int> ret = {2, 4, 1, 5, 7, 6, 0, 9, 3, 8};
    BTree<int, 5> tree(ret); // 5阶B树
    tree.disPlayInorder();
    // tree.erase(6);
    return 0;
}
