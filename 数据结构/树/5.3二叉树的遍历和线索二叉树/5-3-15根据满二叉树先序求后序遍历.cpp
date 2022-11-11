//根据满二叉树的前序序列获取后序序列

//利用满二叉树左子树和右子树个数相同来求解,将大问题分成小问题，递归求解
//前序的第一个元素就是根节点，根节点-左子树-右子树  后序:左子树-右子树-根节点
//递归到最后元素(元素大小为3)后创建新的数据，将这三个元素按照后序遍历放到新创建数组上面返回即可
// eg：满二叉树 前序：245 后序 452

//我这里为了理解，写的比较啰嗦

#include "GetTreeByVector.h"
#include <vector>

using namespace std;

vector<int> dfs(const vector<int> &preDisplay, int left, int right)
{
    if (right - left + 1 == 3)
    {
        int mid = (left + right) / 2;
        vector<int> ret = {preDisplay[mid], preDisplay[right], preDisplay[left]};
        return ret;
    }
    int size = (right - left + 1) / 2;
    vector<int> leftTree = dfs(preDisplay, left + 1, left + size);
    vector<int> rightTree = dfs(preDisplay, left + size + 1, right);
    vector<int> ret(leftTree.begin(), leftTree.end());
    for (int i = 0; i < rightTree.size(); i++)
    {
        ret.push_back(rightTree[i]);
    }
    ret.push_back(preDisplay[left]);
    return ret;
}

vector<int> GetPostorderDisPlay(const vector<int> &preDisplay)
{
    return dfs(preDisplay, 0, preDisplay.size() - 1);
}

int main(int argc, char const *argv[])
{
    MyTree tree({1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15});
    tree.Print(); //打印完全二叉树对应比较  前序[1,2,4,8,9,5,10,11,3,6,12,13,7,14,15]
    vector<int> preDisplay = {1, 2, 4, 8, 9, 5, 10, 11, 3, 6, 12, 13, 7, 14, 15};
    //后序[8 9 4 10 11 5 2 12 13 6 14 15 7 3 1]
    vector<int> ret = GetPostorderDisPlay(preDisplay);
    for (auto &Elem : ret)
    {
        cout << Elem << " ";
    }
    return 0;
}
