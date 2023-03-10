/**
 * @file 8-3-7-2016统考真题.cpp
 * @author your name (you@domain.com)
 * @brief
 * 已知由n个正整数构成的集合A,将其划分为
 * 两个不相交的子集A1和A2，元素个数分别是n1和n2，n1和n2中的元素之和分别为S1和S2。
 * 设计一个尽可能高效的划分算法，满足最小且|S1-S2|最大。要求：
 * 1）给出算法的基本设计思想。
 * 2）根据设计思想，采用C或C++语言描述算法，关键之处给出注释。
 * 3）说明你所设计算法的平均时间复杂度和空间复杂度
 * @version 0.1
 * @date 2023-03-10
 *
 * @copyright Copyright (c) 2023
 *
 */

/**
 * 简单思路：可以先排序,然后找到中间值。
 * 将两半的数组加和即可
 * 排序算法选用综合性能最好的快速排序
 * 时间复杂度O(NlogN),空间复杂度O(1)
 *
 * 也可以使用快速排序思路，找到枢轴值在数组的位置m
 * 当m=n/2时说明找到的位置，无需对数组排序
 * 当m<n/2时，要找的位置在右数组,递归处理
 * 当m>n/2时，要找的位置在左数组,递归处理
 * 时间复杂度O(N),空间复杂度O(1)
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

// 查找第k小的元素的下标
int FindK(std::vector<int> &vet, int begin, int end, int k)
{
    if (vet.size() < k)
    {
        return -1;
    }
    int mid = _sort(vet, begin, end);
    if (mid + 1 == k)
    {
        // cout << "DEBUG:" << vet[mid] << endl;
        return mid;
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

void PrintMergeDebug(vector<int> &vet, int begin, int end)
{
    int target = FindK(vet, begin, end, vet.size() / 2);
    int n1 = target - begin + 1;
    int n2 = end - target + 1;
    cout << "DEBUG: n1=" << target - begin + 1 << " n2=" << end - target << " abs(n2-n1)=" << abs(n2 - n1) << endl;

    int S1 = 0;
    for (int i = 0; i <= target; i++)
    {
        S1 += vet[i];
    }
    int S2 = 0;
    for (int i = target + 1; i < end; i++)
    {
        S2 += vet[i];
    }
    cout << "DEBUG: S1=" << S1 << " S2=" << S2 << " abs(S1-S1)=" << abs(S1 - S2);
}

int main(int argc, char const *argv[])
{
    vector<int> vet = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    PrintMergeDebug(vet, 0, vet.size() - 1);
    return 0;
}
