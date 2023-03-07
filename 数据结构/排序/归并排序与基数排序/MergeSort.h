/**
 * @file MergeSort.h
 * @author your name (you@domain.com)
 * @brief
 * 先将数组分成两段，记作left段和right段
 * 将left段排成有序，将right段排成有序
 * 最后将left和right段排成有序
 * 将left和right排成有序的时候需要借助一个辅助数组，将排序的值先写到这个数组中，最后再拷贝到原数组上。
 * 时间复杂度O(NlogN)
 * 空间复杂度O(N)
 * 稳定排序
 * 只适用于顺序结构
 * @version 0.1
 * @date 2023-03-07
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <class ValueType>
void _merge(vector<ValueType> &vet, int leftBegin, int leftEnd, int rightBegin, int rightEnd, vector<ValueType> &buff)
{
    int buffPos = 0;
    int begin = leftBegin;
    int end = rightEnd;
    while ((leftBegin <= leftBegin) && (rightBegin <= rightEnd))
    {
        if (vet[leftBegin] <= vet[rightBegin])
        {
            buff[buffPos++] = vet[leftBegin];
            leftBegin++;
        }
        else
        {
            buff[buffPos++] = vet[rightBegin];
            rightBegin++;
        }
    }
    while (leftBegin <= leftEnd)
    {
        buff[buffPos++] = vet[leftBegin++];
    }
    while (rightBegin <= rightEnd)
    {
        buff[buffPos++] = vet[rightBegin++];
    }
    for (int i = begin; i <= end; i++)
    {
        vet[i] = buff[i - begin];
    }
}

// 类似二叉树后序遍历
template <class ValueType>
void _MergeSort(vector<ValueType> &vet, int begin, int end, vector<ValueType> &buff)
{
    if (begin >= end)
    {
        return;
    }
    int mid = (begin + end) / 2;
    _MergeSort(vet, begin, mid, buff);
    _MergeSort(vet, mid + 1, end, buff);
    _merge(vet, begin, mid, mid + 1, end, buff);
}

template <class ValueType>
void MergeSort(vector<ValueType> &vet)
{
    if (vet.size() == 0)
    {
        return;
    }
    vector<ValueType> buff(vet.size());
    _MergeSort(vet, 0, vet.size() - 1, buff);
}