#include "UnionFindSet.h"
#include <iostream>
int main(int argc, char const *argv[])
{
    UnionFindSet set(9);

    for (int times = 0; times < 8; times++)
    {
        std::cout << set.GetTreeSize() << std::endl;
        set.PrintUfs();
        set.Union(times, times + 1);
    }

    std::cout << set.GetTreeSize() << std::endl;
    set.PrintUfs();

    return 0;
}
