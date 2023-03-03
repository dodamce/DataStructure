/**
 * @file ShellSort.h
 * @author your name (you@domain.com)
 * @brief
 * 又称缩小增量排序
 * 空间复杂度O(1) 时间复杂度O(n^2)
 * 不是稳定排序
 * 仅适合线性表存储的情况
 * @version 0.1
 * @date 2023-03-03
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include "../debug.h"

using namespace std;

// 升序排列数组
template <class ValueType>
void ShellSort(vector<ValueType> &vet)
{
    // 大区间进行排序,之后缩小区间直到1,此时进行一次插入排序
    int pace = vet.size();
    while (pace > 1)
    {
        pace = pace / 3 + 1;
        for (size_t i = 0; i < vet.size() - pace; i++)
        {
            int pos = i;
            int val = vet[pos + pace];
            // 大距离插入排序
            while (pos >= 0)
            {
                if (vet[pos] > val)
                {
                    vet[pos + pace] = vet[pos];
                    pos -= pace;
                }
                else
                {
                    break; // 找到第一个小于val的位置
                }
            }
            vet[pos + pace] = val;
        }
    }
}