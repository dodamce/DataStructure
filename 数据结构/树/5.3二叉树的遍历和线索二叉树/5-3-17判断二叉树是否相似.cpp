//二叉树相似的定义：两棵二叉树结构相似即可

#include "GetTreeByVector.h"

using namespace std;

bool IsSimilarTree(TreeNode *first, TreeNode *second)
{
    if (first == nullptr && second == nullptr)
        return true;
    if (first == nullptr || second == nullptr)
        return false;
    return IsSimilarTree(first->left, second->left) && IsSimilarTree(first->right, second->right);
}

int main(int argc, char const *argv[])
{
    MyTree tree({1, 2, 3, 4, 5});
    MyTree myTree({5, 6, 7, 8, 9});
    MyTree myTree2({1, 2, 3});
    tree.Print();
    myTree.Print();
    myTree2.Print();
    cout << IsSimilarTree(tree.root, myTree.root) << endl;
    cout << IsSimilarTree(tree.root, myTree2.root) << endl;
    return 0;
}
