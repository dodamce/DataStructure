/**
 * @file 8-3-6荷兰国旗问题.cpp
 * @author your name (you@domain.com)
 * @brief
 * 将顺序表的色块序列按照红白蓝的顺序排列好
 * 要求时间复杂度O(n)
 * 思路使用左右指针
 * red指针前都是红色块,blue指针后都是蓝色
 * @version 0.1
 * @date 2023-03-09
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

enum color
{
    RED,
    WHITE,
    BLUE
};

void MakeFlag(vector<color> &vet)
{
    int red = 0;
    int blue = vet.size() - 1;

    int pos = 0;
    while (pos <= blue)
    {
        if (vet[pos] == RED)
        {
            // vet[red]
            std::swap(vet[pos], vet[red]);
            red += 1;
            pos += 1;
            // red位置一定是白色，因为如果是红色的花pos和red位置是相同的，不会错开
            // 如果red位置是蓝色，这两个指针同时不移动
            // 只有当red位置出现白色，pos和red位置才会错开，此时red位置一定是白色
        }
        else if (vet[pos] == BLUE)
        {
            std::swap(vet[pos], vet[blue]);
            blue -= 1;
        }
        else
        {
            pos += 1;
        }
    }
}

void DisPlay(std::vector<color> &vet)
{
    for (auto &num : vet)
    {
        if (num == BLUE)
        {
            cout << "BLUE ";
        }
        else if (num == RED)
        {
            cout << "RED ";
        }
        else
        {
            cout << "WHITE ";
        }
    }
    cout << "\n";
}

int main(int argc, char const *argv[])
{
    vector<color> vet{BLUE, RED, BLUE, WHITE, BLUE, RED, BLUE, WHITE, WHITE};
    MakeFlag(vet);
    DisPlay(vet);
    return 0;
}
