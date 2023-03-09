/**
 * @file 8-3-2双向冒泡排序算法.h
 * @author your name (you@domain.com)
 * @brief
 * 双向冒泡算法,添加标记位,让奇数偶数次遍历方向不同即可
 * @version 0.1
 * @date 2023-03-09
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void BubbleSort(vector<int> &vet)
{
    bool flag = false;
    size_t left = 0;
    size_t right = vet.size() - 1;
    while (left < right)
    {
        if (flag == false)
        {
            // 奇数趟,从前往后遍历
            for (size_t i = left; i < right; i++)
            {
                if (vet[i] > vet[i + 1])
                {
                    std::swap(vet[i], vet[i + 1]);
                }
            }
            right -= 1;
            flag = true;
        }
        else if (flag == true)
        {
            // 偶数趟,从后往前遍历
            for (size_t i = right; i > left; i--)
            {
                if (vet[i] < vet[i - 1])
                {
                    swap(vet[i], vet[i - 1]);
                }
            }
            left += 1;
            flag = false;
        }
    }
}

void DisPlay(vector<int> &vet)
{
    for (auto &num : vet)
    {
        cout << num << " ";
    }
    cout << "\n";
}

int main(int argc, char const *argv[])
{

    vector<int> vet = {9, 7, 5, 8, 4, 3, 1, 0, 2};
    BubbleSort(vet);
    DisPlay(vet);
    return 0;
}
