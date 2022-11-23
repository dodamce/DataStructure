#include <iostream>

#include <unordered_map>

#include <string>

#include <vector>

#include <assert.h>
//传入一串字符，使用哈夫曼树对其进行编码，字符串中每个字符出现的次数就是作为哈夫曼树的权值

struct TreeNode
{
    char val;   //节点保存的值
    int weight; //权值
    TreeNode *left;
    TreeNode *right;
    TreeNode(int _weight) : val(0), weight(_weight), left(nullptr), right(nullptr) {}
    TreeNode(char _val, int _weight) : val(_val), weight(_weight), left(nullptr), right(nullptr) {}
};

class HuffTree
{
private:
    void _InitTimes(const std::string &src)
    {
        for (int i = 0; i < src.size(); i++)
        {
            times[src[i]] += 1;
        }
    }

    void _PreDisplay(TreeNode *node, std::string &str)
    {
        if (node->left == nullptr && node->right == nullptr)
        {
            //叶子节点
            // std::cout << str << std::endl;
            code[node->val] = str;
            return;
        }
        if (node->left != nullptr)
        {
            str.push_back('0');
            _PreDisplay(node->left, str);
            str.pop_back(); //出递归后，刚刚递归进去给字符串插入的字符也要弹出
        }
        if (node->right != nullptr)
        {
            str.push_back('1');
            _PreDisplay(node->right, str);
            str.pop_back();
        }
    }

    void _PreDisplay(TreeNode *node)
    {
        std::string retBuff;
        _PreDisplay(node, retBuff);
    }

public:
    TreeNode *root;                             //构造的哈夫曼树
    std::unordered_map<char, std::string> code; //保存字符进行编码的结果
    std::unordered_map<char, int> times;        //保存传入的字符串中每个字符出现的次数

    HuffTree(const std::string &src)
    {
        //统计每个字符出现的次数
        _InitTimes(src);

        std::vector<TreeNode *> ArrayNode;
        //先给所有节点开辟空间
        std::unordered_map<char, int>::iterator pos = times.begin();
        while (pos != times.end())
        {
            ArrayNode.push_back(new TreeNode(pos->first, pos->second));
            pos++;
        }

        //循环创建哈夫曼树节点
        //如果只有一个节点
        if (ArrayNode.size() == 0)
        {
            root = ArrayNode[0];
        }
        else
        {
            for (int time = 0; time < ArrayNode.size() - 1; time++)
            {
                //找权值最小的和第二小的节点
                int minIndex = 0;
                int minSecIndex = 0;
                // ArrayNode[minIndex] == nullptr证明这个节点已经建立过哈夫曼树了，需要跳过
                while (ArrayNode[minIndex] == nullptr)
                {
                    minIndex++;
                }
                for (int i = 0; i < ArrayNode.size(); i++)
                {
                    if (ArrayNode[i] != nullptr && ArrayNode[i]->weight < ArrayNode[minIndex]->weight)
                    {
                        minIndex = i;
                    }
                }

                //找次小值
                while (ArrayNode[minSecIndex] == nullptr || minIndex == minSecIndex)
                {
                    minSecIndex++;
                }
                for (int i = 0; i < ArrayNode.size(); i++)
                {
                    if (i != minIndex)
                    {
                        if (ArrayNode[i] != nullptr && ArrayNode[i]->weight < ArrayNode[minSecIndex]->weight)
                        {
                            minSecIndex = i;
                        }
                    }
                }

                // printf("出现次数最小的字符是%c,出现次数%d\n", ArrayNode[minIndex]->val, ArrayNode[minIndex]->weight);
                // printf("出现次数次少的字符是%c,出现次数为%d\n", ArrayNode[minSecIndex]->val, ArrayNode[minSecIndex]->weight);
                // printf("============\n");

                //创建新节点，将这个节点插入到最小字符位置，次少节点位置处理过了置空.并将树结构构造好
                root = new TreeNode(ArrayNode[minIndex]->weight + ArrayNode[minSecIndex]->weight);

                root->left = ArrayNode[minIndex];
                root->right = ArrayNode[minSecIndex];

                ArrayNode[minIndex] = root;
                ArrayNode[minSecIndex] = nullptr;
            }
        }
    }

    //打印编码
    void PrintCode()
    {
        //遍历树，直到遍历到叶子节点，规定向左树走编码为0，向右树走编码为1
        _PreDisplay(root);

        //打印编码集合
        auto pos = code.begin();
        while (pos != code.end())
        {
            std::cout << pos->first << ":" << pos->second << std::endl;
            pos++;
        }
    }

    //解码
    char DeCode(const std::string &src)
    {
        TreeNode *node = root;
        for (int i = 0; i < src.size(); i++)
        {
            if (src[i] == '0')
                node = node->left;
            if (src[i] == '1')
                node = node->right;
        }
        assert(node->left == nullptr && node->right == nullptr); // node一定走到了叶子节点
        return node->val;
    }
};