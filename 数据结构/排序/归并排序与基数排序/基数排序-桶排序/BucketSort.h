/**
 * @file BucketSort.h
 * @author your name (you@domain.com)
 * @brief
 * 1. 首先按照个位数0-9开辟10个和要排序的数组大小相同的数组。
 * 2. 数组的元素按照个位数对应到相应的桶中。
 * 3. 排列完后重新按照顺序写回数组中
 * 时间复杂度：d趟分配收集，一次分配O( n )，一次收集O( r )
 * 总时间复杂度O(d(n+r))
 * d是排序数字的位数，n是排序数字的长度，r 是开辟的数组的个数
 * 空间复杂度O( r )
 * 基数排序按照位来排序，是稳定的
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

// 获取val的位数
int digitPlace(int val)
{
    int ret = 0;
    while (val != 0)
    {
        ret += 1;
        val /= 10;
    }
    return ret;
}

void BucketSort(vector<int> &vet)
{
    // 获取最大位数
    int times = digitPlace(*std::max_element(vet.begin(), vet.end()));
    int flag = 1;
    for (int i = 0; i < times; i++)
    {
        // 创建10个箱子, 初始化为 INT_MIN
        vector<vector<int>> Bucket(10, vector<int>(vet.size(), INT_MIN));
        for (int pos = 0; pos < vet.size(); pos++)
        {
            // 获取这一位的数字
            int idx = (vet[pos] / flag) % 10;
            Bucket[idx][pos] = vet[pos];
        }
        flag *= 10;
        int index = 0;
        for (int bucket = 0; bucket < 10; bucket++)
        {
            for (int pos = 0; pos < vet.size(); pos++)
            {
                if (Bucket[bucket][pos] != INT_MIN)
                {
                    vet[index++] = Bucket[bucket][pos];
                }
            }
        }
    }
}