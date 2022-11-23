#include "hufftree.h"

int main(int argc, char const *argv[])
{
    HuffTree tree("abandon");
    tree.PrintCode();

    std::cout << "010解码:" << tree.DeCode("010") << std::endl;
    return 0;
}
