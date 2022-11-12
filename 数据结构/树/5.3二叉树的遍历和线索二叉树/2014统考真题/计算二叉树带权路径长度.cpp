//二叉树储存结构 left weight right

//二叉树根节点到所有叶子节点的权值=根节点到叶子节点的weight的和

#include "../GetTreeByVector.h"
#include <vector>
#include <stack>

using namespace std;

//利用前序遍历，每次访问节点就+权值，每次递归返回就自动-权值了，直到遇到根节点，放到数组即可
void GetWeightTree(TreeNode *root, vector<int> &ret, int weight)
{
    if (root->left == nullptr && root->right == nullptr)
    {
        ret.push_back(weight + root->val);
        return;
    }
    weight += root->val;
    GetWeightTree(root->left, ret, weight);
    GetWeightTree(root->right, ret, weight);
}
void GetWeightTree(TreeNode *root, vector<int> &ret)
{
    GetWeightTree(root, ret, 0);
}

int main(int argc, char const *argv[])
{
    MyTree tree({1, 2, 3, 4, 5});
    tree.Print();
    vector<int> ret;
    GetWeightTree(tree.root, ret);
    for (auto &Elem : ret)
    {
        cout << Elem << " ";
    }
    return 0;
}
