/**
 * @file InsertSort.h
 * @author your name (you@domain.com)
 * @brief 插入排序算法
 * 空间复杂度O(1)
 * 时间复杂度O(n^2)
 * 稳定排序
 * 适用在顺序存储和链式存储
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

// 升序排列数组
template <class ValueType>
void InsertSort(vector<ValueType> &vet)
{
    for (int i = 1; i < vet.size(); i++)
    {
        ValueType val = vet[i];
        for (int pos = i; pos >= 0; pos--)
        {
            if (val < vet[pos - 1] && pos > 0)
            {
                vet[pos] = vet[pos - 1];
            }
            else
            {
                vet[pos] = val;
                break;
            }
        }
    }
}
