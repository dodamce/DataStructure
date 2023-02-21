#include "BalanceTree.h"

using namespace std;

int main(int argc, char const *argv[])
{
    BalanceTree tree({3, 4, 2, 5, 6, 1, 7});
    tree.InorderDisplay();
    std::cout << tree.isAVLTree() << std::endl;
    tree.erase(4);
    tree.InorderDisplay();
    std::cout << tree.isAVLTree() << std::endl;
    tree.erase(5);
    tree.InorderDisplay();
    std::cout << tree.isAVLTree() << std::endl;
    return 0;
}
