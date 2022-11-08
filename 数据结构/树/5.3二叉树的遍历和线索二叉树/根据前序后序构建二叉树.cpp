//首先根据前序和后序不能构建确定的二叉树，这里放在一起为了对比
// leetcode:https://leetcode.cn/problems/construct-binary-tree-from-preorder-and-postorder-traversal/

#include <unordered_map>
#include <vector>

using namespace std;

//   Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    unordered_map<int, int> hash;
    TreeNode *makeTree(vector<int> &preorder, vector<int> &postorder, int preBegin, int preEnd, int postBegin, int postEnd)
    {
        if (preBegin > preEnd)
        {
            return nullptr;
        }
        //根节点
        int rootval = preorder[preBegin];
        if (preBegin == preEnd)
        {
            //只有一个节点
            return new TreeNode(rootval);
        }
        //找根节点的左子树个数
        int leftval = preorder[preBegin + 1];
        int mid = hash[leftval];
        int leftSize = mid - postBegin + 1;

        TreeNode *root = new TreeNode(rootval);
        root->left = makeTree(preorder, postorder, preBegin + 1, preBegin + leftSize, postBegin, mid);
        root->right = makeTree(preorder, postorder, preBegin + leftSize + 1, preEnd, mid + 1, postEnd - 1);
        return root;
    }
    TreeNode *constructFromPrePost(vector<int> &preorder, vector<int> &postorder)
    {
        for (int i = 0; i < postorder.size(); i++)
        {
            hash.insert(make_pair(postorder[i], i));
        }
        return makeTree(preorder, postorder, 0, preorder.size() - 1, 0, postorder.size() - 1);
    }
};
