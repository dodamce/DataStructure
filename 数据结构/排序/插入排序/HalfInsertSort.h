/**
 * @file HalfInsertSort.h
 * @author your name (you@domain.com)
 * @brief
 * 适用于顺序存储结构
 * 将比较和插入过程分离开，比较采用折半查找
 * 比较次数n*log(n)次
 * 时间复杂度O(n^2)
 * 空间复杂度O(1)
 * 稳定排序
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

// 折半查找算法，找第一个大于val的位置并返回
template <class ValueType>
size_t _HalfFind(vector<ValueType> &vet, int begin, int end, int val)
{
    while (begin <= end)
    {
        int mid = (begin + end) / 2;
        if (vet[mid] > val)
        {
            end = mid - 1;
        }
        else if (vet[mid] < val)
        {
            begin = mid + 1;
        }
        else
        {
            return mid + 1;
        }
    }
    return begin;
}

template <class ValueType>
void _moveElem(std::vector<ValueType> &vet, int begin, int end)
{
    if (begin > end)
    {
        return;
    }
    for (int i = end; i >= begin; i--)
    {
        vet[i] = vet[i - 1];
    }
}

template <class ValueType>
void HalfInsertSort(vector<ValueType> &vet)
{
    for (size_t i = 1; i < vet.size(); i++)
    {
        int val = vet[i];
        size_t begin = _HalfFind(vet, 0, i, val); //[]
        _moveElem(vet, begin, i);
        vet[begin] = val;
    }
}