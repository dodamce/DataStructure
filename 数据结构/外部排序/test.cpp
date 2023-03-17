#include "defeatTree.h"

using namespace std;

int main()
{
    vector<leave> leaves;
    leave lev({ 10,15,31 });
    leave lev2({ 9,20 });
    leave lev3({ 1, 34, 37 });
    leaves.push_back(lev);
    leaves.push_back(lev2);
    leaves.push_back(lev3);
    defeatTree tree(leaves);
    return 0;
}
