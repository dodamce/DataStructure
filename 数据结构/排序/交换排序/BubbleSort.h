/**
 * @file BubbleSort.h
 * @author your name (you@domain.com)
 * @brief
 * 冒泡排序
 * 时间复杂度O(n^2)
 * 空间复杂度O(1)
 * 稳定排序,因为vet[j] == vet[j + 1]不发生交换,所以可以保证相对位置不变
 * 适合链式存储和顺序存储
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
void BubbleSort(vector<ValueType> &vet)
{
    for (size_t i = 0; i < vet.size(); i++)
    {
        for (size_t j = 0; j < vet.size() - i - 1; j++)
        {
            if (vet[j] > vet[j + 1])
            {
                swap(vet[j], vet[j + 1]);
            }
        }
    }
}