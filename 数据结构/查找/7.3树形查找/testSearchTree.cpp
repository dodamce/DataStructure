#include "SearchTree.h"
#include <time.h>

using namespace std;

#define TIMES 10

int main(int argc, char const *argv[])
{
    srand((unsigned int)time(0));
    // vector<int> ret = {1, 2, 3};
    vector<int> ret;
    for (int i = 0; i < TIMES; i++)
    {
        ret.push_back(rand() % 100);
    }
    SearchTree tree(ret);
    tree.inorder();
    tree.insert(40);
    tree.inorder();
    cout << tree.isSearchTree() << endl;
    tree.insert(1);
    tree.erase(40);
    tree.inorder();
    cout << tree.isSearchTree() << endl;
    return 0;
}
