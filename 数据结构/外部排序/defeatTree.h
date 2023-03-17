#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include<assert.h>
//#include<unordered_map>

// 败者树节点结构，这里使用树状结构实现败者树
struct TreeNode
{
    int _fault_pos = -1;        // 失败节点的归并段在数组的位置
    int _win_val = INT_MIN; // 这层节点的胜利者的值
    int _win_pos = -1;//这层胜利节点在数组的位置
    int _del_val = 0;//这个节点参与比较的关键值
    TreeNode *_parent = nullptr;
    TreeNode *_left = nullptr;
    TreeNode *_right = nullptr;
};

struct leave
{
    friend class defeatTree;

private:
    TreeNode *_parent = nullptr;

public:
    std::vector<int> _vet; // 存放数据的数组
    int _begin = 0;        // 存放败者树需要处理vet那个元素

    leave(const std::vector<int> &vet) : _vet(vet) {}

    leave() = default;
};

class defeatTree
{
private:
     //std::unordered_map<leave, int> _index; // leave节点在buff中的映射
    TreeNode* _root = nullptr;
    std::vector<TreeNode*>leaveNodes;

    void _findLeaves(std::vector<TreeNode*>&buff,TreeNode*node) {
        if (node == nullptr) {
            return;
        }
        if (node->_left == nullptr || node->_right == nullptr) {
            buff.push_back(node);
        }
        _findLeaves(buff, node->_left);
        _findLeaves(buff, node->_right);
    }

    //将buff数组的值添加到叶子节点上
    void _update(std::vector<TreeNode*>&leves,std::vector<leave>&buff) {
        assert(leves.size() == buff.size());
        for (int i = 0; i < buff.size(); i++) {
            leves[i]->_del_val = buff[i]._vet[buff[i]._begin];
            leves[i]->_win_val = buff[i]._vet[buff[i]._begin];
            leves[i]->_fault_pos = i;
            leves[i]->_win_pos = i;
        }
    }

    void _adjust(TreeNode*node) {
        while (node->_parent != nullptr) {
            TreeNode* peer = node->_parent->_left == node ? node->_parent->_right : node->_parent->_left;
            TreeNode* parent = node->_parent;

            if (peer->_del_val != INT_MIN) {
                if (node->_win_val < peer->_win_val) {
                    //node获胜
                    parent->_win_val = node->_del_val;
                    parent->_fault_pos = peer->_win_pos;
                    parent->_del_val = node->_del_val;
                    parent->_win_pos = node->_win_pos;
                }
                else {
                    //peer获胜
                    parent->_win_pos = peer->_del_val;
                    parent->_fault_pos = node->_win_pos;
                    parent->_del_val = peer->_del_val;
                    parent->_win_pos = peer->_win_pos;
                }
                std::cout << "DEBUG: " << node->_del_val << ":" << peer->_del_val << std::endl;
            }
            else {
                //对方peer节点未初始化，parent值设定和node相同
                parent->_win_pos = node->_del_val;
                parent->_fault_pos = node->_win_pos;
                parent->_del_val = node->_del_val;
                parent->_win_pos = node->_win_pos;
            }
            node = node->_parent;
        }
    }
public:
    defeatTree(std::vector<leave>& buff)
    {
        ////构建leave和其buff下标的映射
        //for (int i = 0; i < buff.size(); i++) {
        //    _index[buff[i]] = i;
        //}

        // 根据leave叶子节点个数构造完全二叉树
        int leave = 0;
        TreeNode* root = new TreeNode();
        _root = root;
        std::queue<TreeNode*> q;
        int level = 1;
        bool changeLevel = false;
        q.push(root);
        while (leave != buff.size())
        {
            if (changeLevel == true)
            {
                leave -= 1;
                changeLevel = false;
            }
            // 层序创建树，统计数的叶子节点
            for (int i = 0; i < pow(2, level - 1); i++)
            {
                TreeNode* node = q.front();
                q.pop();
                node->_left = new TreeNode();
                node->_right = new TreeNode();
                node->_left->_parent = node;
                q.push(node->_left);
                leave += 1;
                if (leave == buff.size()) {
                    break;
                }
                node->_right->_parent = node;
                q.push(node->_right);
                leave += 1;
                if (leave == buff.size()) {
                    break;
                }
            }
            if (leave == buff.size()) {
                break;
            }
            // 层数增加，重新计算此时叶子节点
            level += 1;
            leave = pow(2, level-1);
            changeLevel = true;
        }

        //找到叶子节点，向上构造败者树
        _findLeaves(leaveNodes,root);
        
        //给叶子节点添加值
        _update(leaveNodes, buff);

        //对每一个叶子节点进行向上调整
        for (int i = 0; i < leaveNodes.size(); i++) {
            _adjust(leaveNodes[i]);
        }
        disPlay(buff);
    }

    void disPlay(std::vector<leave>& buff) {
        std::cout << "最小值:" << _root->_win_val << std::endl;
        TreeNode* node = _root;
        std::cout << "击败的值为: ";
        while (node->_left != nullptr) {
            std::cout << buff[node->_fault_pos]._vet[buff[node->_fault_pos]._begin] <<
                " ";
            node = node->_left;
        }
    }
};