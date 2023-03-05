/**
 * @file QuickSort.h
 * @author your name (you@domain.com)
 * @brief
 * 快速排序算法
 * 首先在数组上选择一个标准值，将数组分为小于标准值 标准值 大于标准值
 * 递归小于标准值的部分数组和大于标准值的两部分数组,直到这两个数组的长度为1时结束递归,数组排序完成
 *
 * 快速排序时所有内部排序中平均性能最优的
 * 时间复杂度O(NlogN) 最差时间复杂度O(N^2)
 * 空间复杂度O(logN) 最差O(N)
 * 稳定性：不稳定
 * 适合顺序结构排序
 * @version 0.1
 * @date 2023-03-03
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <class ValueType>
int _adjustPivot(vector<ValueType> &vet, int begin, int end)
{
    // 挖坑法调整数组
    int pivot = vet[begin]; // 首元素为标准值
    int left = begin;
    int right = end;
    int init_index = left;
    while (left < right)
    {
        // right先移动,保证right找left,这样left位置就是最后一个小于pivot的位置，最后交换即可
        while (vet[right] >= pivot && left < right)
        {
            right -= 1;
        }
        // left找大于pivot的值
        while (vet[left] <= pivot && left < right)
        {
            left += 1;
        }
        std::swap(vet[left], vet[right]);
    }
    std::swap(vet[left], vet[init_index]);
    return left;
}

template <class ValueType>
void _quickSort(vector<ValueType> &vet, int begin, int end)
{
    if (begin > end)
    {
        return;
    }
    int mid = _adjustPivot(vet, begin, end);
    _quickSort(vet, begin, mid - 1);
    _quickSort(vet, mid + 1, end);
}

// 类似前序遍历方式递归
template <class ValueType>
void QuickSort(vector<ValueType> &vet)
{
    if (vet.size() == 0 || vet.size() == 1)
        return;
    _quickSort(vet, 0, vet.size() - 1);
}
