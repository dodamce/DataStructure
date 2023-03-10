/**
 * @file 8-3-5找第k大的数字.cpp
 * @author your name (you@domain.com)
 * @brief
 * 简单思路：排序后返回数组k位置的元素 时间复杂度大于O(NlogN)
 * 答案思路：利用快速排序返回的枢轴值位置m
 * 如果m=k则枢轴值就是要找的第k小的数字
 * m<k,要找的值在右数组上,递归的查找右数组的第k-m小的元素
 * m>k,要找的值在左数组上,递归的查找左数组的第k小的元素
 * @version 0.1
 * @date 2023-03-09
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 排序枢轴值函数,返回枢轴值在数组的位置,[]
int _sort(vector<int> &vet, int begin, int end)
{
    int KeyValue = vet[begin];
    // begin位置是枢轴值,挖坑法,开始begin位置位坑
    while (begin < end)
    {
        while (vet[end] > KeyValue)
        {
            end--;
        }
        std::swap(vet[begin], vet[end]);
        // 此时end为坑
        while (vet[begin] < KeyValue)
        {
            begin++;
        }
        std::swap(vet[begin], vet[end]);
    }
    vet[begin] = KeyValue;
    return begin;
}

// 查找第k小的元素
int FindK(std::vector<int> &vet, int begin, int end, int k)
{
    if (vet.size() < k)
    {
        return -1;
    }
    int mid = _sort(vet, begin, end);
    if (mid + 1 == k)
    {
        cout << "DEBUG:" << vet[mid] << endl;
        return vet[mid];
    }
    else if (mid + 1 < k)
    {
        return FindK(vet, mid + 1, end, k);
    }
    else
    {
        return FindK(vet, begin, mid - 1, k);
    }
}

int main(int argc, char const *argv[])
{
    vector<int> vet = {1, 2, 3, 4, 5, 6, 7};
    FindK(vet, 0, vet.size() - 1, 7);
    return 0;
}
