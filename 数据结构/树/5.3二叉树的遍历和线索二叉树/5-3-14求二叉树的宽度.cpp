#include "GetTreeByVector.h"

#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

//将二叉树每层的节点放到一个队列中，最后看那个队列最长的就是二叉树的宽度

size_t GetWith(TreeNode *root)
{
    vector<int> with;
    queue<TreeNode *> curLevel;
    curLevel.push(root);
    while (!curLevel.empty())
    {
        int size = curLevel.size();
        with.push_back(size);
        for (int i = 0; i < size; i++)
        {
            TreeNode *node = curLevel.front();
            curLevel.pop();
            if (node->left)
                curLevel.push(node->left);
            if (node->right)
                curLevel.push(node->right);
        }
    }
    //返回数组最大的值
    return *max_element(with.begin(), with.end());
}

int main(int argc, char const *argv[])
{
    MyTree tree({1, 2, 3, 4, 5, 6, 7, 8});
    tree.Print();
    cout << GetWith(tree.root);
    return 0;
}
