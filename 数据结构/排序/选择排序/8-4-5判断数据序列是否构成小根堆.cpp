/**
 * @file 8-4-5判断数据序列是否构成小根堆.cpp
 * @author your name (you@domain.com)
 * @brief
 * 类似二叉树的后序遍历即可,这里使用递归的方式
 * @version 0.1
 * @date 2023-03-13
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <iostream>
#include <vector>

using namespace std;

bool isHeapSmall(std::vector<int> &vet, int patent)
{
    int childLeft = 2 * patent + 1;
    int childRight = 2 * patent + 2;
    if (patent >= vet.size() || childLeft >= vet.size() || childRight >= vet.size())
    {
        return true;
    }
    bool leftTree = isHeapSmall(vet, childLeft);
    bool rightTree = isHeapSmall(vet, childRight);
    return leftTree && rightTree && ((vet[childLeft] > vet[patent]) && (vet[childRight] > vet[patent]));
}

int main(int argc, char const *argv[])
{
    // vector<int> vet = {5, 8, 12, 19, 28, 20, 15, 22}; // 小根堆
    vector<int> vet = {3, 5, 12, 19, 20, 15, 22, 8, 28}; // 不是堆结构
    cout << isHeapSmall(vet, 0) << endl;
    return 0;
}
