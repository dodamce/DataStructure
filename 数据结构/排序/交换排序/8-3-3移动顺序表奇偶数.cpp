/**
 * @file 8-3-3移动顺序表奇偶数.cpp
 * @author your name (you@domain.com)
 * @brief
 * 移动顺序表奇数和偶数，让奇数在偶数前，效率尽可能高
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

// left指针找偶数,right指针找奇数,交换left和right位置元素
// 算法空间复杂度O(1)
// 时间复杂度最优O(logN),最差O(N)
void MoveElem(vector<int> &vet)
{
    size_t left = 0;
    size_t right = vet.size() - 1; //[]型
    while (left < right)
    {
        while ((left < right) && (vet[left] % 2 != 0))
        {
            left += 1;
        }
        while ((left < right) && (vet[right] % 2 == 0))
        {
            right -= 1;
        }

        std::swap(vet[left], vet[right]);
        left += 1;
        right -= 1;
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
    vector<int> vet = {9, 6, 5, 8, 4, 3, 1, 0, 2};
    MoveElem(vet);
    DisPlay(vet);
    return 0;
}
