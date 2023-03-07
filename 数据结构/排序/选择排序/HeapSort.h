/**
 * @file HeapSort.h
 * @author your name (you@domain.com)
 * @brief 首先给这个数组建堆，时间复杂度为O(N)
 * 如果要从小到大排列,建立大堆，每次将堆顶数据移动到数组最后边，再调整堆即可
 * 时间复杂度O(NlogN)
 * 空间复杂度O(1)
 * 不稳定排序
 * 只有顺序查找可以使用
 * @version 0.1
 * @date 2023-03-05
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 建大堆
template <class ValueType>
void adjustDown(vector<ValueType> &vet, int parent, int capacity)
{
    int child = 2 * parent + 1;
    while (child < capacity)
    {
        {
            if (child + 1 < capacity && vet[child] < vet[child + 1])
            {
                child += 1;
            }
            if (vet[parent] < vet[child])
            {
                std::swap(vet[parent], vet[child]);
            }
            else
            {
                break;
            }
            parent = child;
            child = 2 * parent + 1;
        }
    }
}

template <class ValueType>
void HeapSort(vector<ValueType> &vet)
{
    // 构建堆,从下往上建立
    for (int parent = (vet.size() - 1 - 1) / 2; parent >= 0; parent--)
    {
        adjustDown(vet, parent, vet.size());
    }
    int endPos = vet.size();
    // 堆排序
    while (endPos > 0)
    {
        std::swap(vet[0], vet[endPos - 1]);
        endPos -= 1;
        adjustDown(vet, 0, endPos);
    }
}