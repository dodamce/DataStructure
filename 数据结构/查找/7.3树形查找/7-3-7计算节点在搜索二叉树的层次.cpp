#include "./搜索二叉树/SearchTree.h"
#include <vector>
#include <assert.h>

// 规定，树的根节点的层数为1

using namespace std;

size_t getNodeHigh(SearchTree &tree, int val)
{
    size_t cout = 1;
    TreeNode *root = tree.root;
    assert(root != nullptr);
    bool find = false;
    while (root != nullptr)
    {
        cout += 1;
        if (root->_val > val)
        {
            root = root->_left;
        }
        else if (root->_val < val)
        {

            root = root->_right;
        }
        else if (root->_val == val)
        {
            find = true;
            break;
        }
    }
    if (find == true)
        return cout;
    else
        return -1;
}

int main(int argc, char const *argv[])
{
    SearchTree tree({1, 2, 3, 4, 5});
    cout << getNodeHigh(tree, 3) << endl;
    cout << getNodeHigh(tree, 5) << endl;
    cout << getNodeHigh(tree, 6) << endl;
    return 0;
}
