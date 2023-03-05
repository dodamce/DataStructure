/**
 * @file SelectSort.h
 * @author your name (you@domain.com)
 * @brief
 * 每一次选择最小值火最大值，然后把最小值放到第一位，最大值放到第二位
 * 依次循环，直到把所有的数组元素筛选完毕
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

template <class ValueType>
void SelectSort(vector<ValueType> &vet)
{
    int left = 0;
    int right = vet.size() - 1;
    while (left <= right)
    {
        int minPos = left;
        int maxPos = left;
        for (int i = left; i <= right; i++)
        {
            if (vet[minPos] > vet[i])
            {
                minPos = i;
            }
            else if (vet[maxPos] < vet[i])
            {
                maxPos = i;
            }
        }
        std::swap(vet[left], vet[minPos]);
        if (maxPos == left)
        {
            maxPos = minPos;
        }
        std::swap(vet[maxPos], vet[right]);
        left += 1;
        right -= 1;
    }
}