/**
 * @file 8-6-4比较次数小于n实现排序.cpp
 * @author your name (you@domain.com)
 * @brief
 * 题干要求就是实现快速排序算法
 * 全速排序元素比较次数小于n
 * @version 0.1
 * @date 2023-03-15
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include "../debug.h"

using namespace std;

// 将枢轴值放到对应最终位置上,返回枢轴值的最终位置
int sort(vector<int> &vet, int begin, int end)
{
    int key = vet[begin];

    // 此时begin为坑，使用挖坑法
    while (begin < end)
    {
        while (begin < end && vet[end] >= key)
        {
            end--;
        }

        std::swap(vet[begin], vet[end]);

        // end变成坑

        while (begin < end && vet[begin] <= key)
        {
            begin++;
        }

        std::swap(vet[begin], vet[end]);
    }
    vet[begin] = key;
    return begin;
}

void quickSort(vector<int> &vet, int begin, int end)
{
    if (begin >= end)
    {
        return;
    }
    int mid = sort(vet, begin, end);
    quickSort(vet, begin, mid - 1);
    quickSort(vet, mid + 1, end);
}

int main(int argc, char const *argv[])
{
    vector<int> vet = {5, 3, 1, 6, 2, 7, 9, 0, 1, 2};
    DisPlay(vet);
    quickSort(vet, 0, vet.size() - 1);
    DisPlay(vet);
    return 0;
}
