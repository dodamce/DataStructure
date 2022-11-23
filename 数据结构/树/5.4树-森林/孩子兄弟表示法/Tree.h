/**
所谓孩子兄弟表示法，指的是用将整棵树用二叉链表存储起来.
具体实现方案是：从树的根节点开始，依次存储各个结点的孩子结点和兄弟结点。

在二叉链表中，各个结点包含三部分内容：
1. 节点的值；
2. 指向孩子结点的指针；
3. 指向兄弟结点的指针；

通过孩子兄弟表示法，任意一棵普通树都可以相应转化为一棵二叉树，它们是一一对应的。

*
*/

#include <iostream>
#include <vector>

struct TreeNode
{
    char val;
    TreeNode *child;
    TreeNode *brother;
    TreeNode(int _val) : val(_val), child(nullptr), brother(nullptr) {}
};

class Tree
{
public:
    TreeNode *root;
    Tree()
    {
        std::vector<TreeNode *> cur_roots; //保存这一层的节点
        std::cout << "请输入根节点的值" << std::endl;
        char val = 0;
        std::cin >> val;
        root = new TreeNode(val);
        cur_roots.push_back(root);
        while (cur_roots.size() != 0)
        {
            std::vector<TreeNode *> next_roots;
            for (int i = 0; i < cur_roots.size(); i++)
            {
                TreeNode *root = cur_roots[i];
                std::cout << "输入" << root->val << "孩子节点个数" << std::endl;
                int size = 0;
                std::cin >> size;
                TreeNode *tail = nullptr;
                for (int j = 0; j < size; j++)
                {
                    std::cout << "输入第" << j + 1 << "个孩子节点的值" << std::endl;
                    char data = 0;
                    std::cin >> data;
                    if (j == 0)
                    {
                        //第一个节点放到左链表上，代表孩子
                        root->child = new TreeNode(data);
                        tail = root->child;
                    }
                    else
                    {
                        tail->brother = new TreeNode(data);
                        tail = tail->brother;
                    }
                    next_roots.push_back(tail);
                }
            }
            cur_roots = next_roots;
        }
    }

    //最后构造完树后成二叉树，可以直接使用前序遍历
    void _PreDisplay(TreeNode *node)
    {
        if (node == nullptr)
            return;
        std::cout << node->val << " ";
        _PreDisplay(node->child);
        _PreDisplay(node->brother);
    }
    void PreDisplay()
    {
        _PreDisplay(root);
    }
};