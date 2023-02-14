// 顺序查找与折半查找
// 循序查找采用链表结构，折半查找采用数组的形式
#include <iostream>
#include <vector>
#include "../../线性表/2-3课后习题/GetListByVector.h" //链表头文件
#include <algorithm>

using namespace std;

// 顺序查找
/**
 * @brief 循序查找链表上的元素
 *
 * @param list 链表节点
 * @param tag 查找的目标
 * @return true 查找成功
 * @return false 查找失败
 */
bool FindTag(NodeListNoHead &list, int tag)
{
    Node *node = list._head;
    bool found = false;
    while (node != nullptr)
    {
        if (node->_val == tag)
        {
            found = true;
            break;
        }
        node = node->_next;
    }
    return found;
}

// 折半查找,顺序表折半查找,仅仅适用于有序顺序表
bool FindTag(vector<int> &buff, int tag)
{
    sort(buff.begin(), buff.end());
    int mid = 0;
    int left = 0;
    int right = buff.size() - 1; //[]型折半查找
    bool found = false;
    while (left <= right)
    {
        mid = (left + right) / 2;
        if (buff[mid] < tag)
        {
            left = mid + 1;
        }
        else if (buff[mid] > tag)
        {
            right = mid - 1;
        }
        else
        {
            found = true;
            break;
        }
    }
    return found;
}

int main(int argc, char const *argv[])
{
    NodeListNoHead list({5, 3, 6, 3, 7, 1});
    // cout << FindTag(list, 3) << endl;
    // cout << FindTag(list, 2) << endl;
    vector<int> ret = {1, 2, 3, 4, 6, 7, 9, 10};
    cout << FindTag(ret, 5) << endl;
    return 0;
}
