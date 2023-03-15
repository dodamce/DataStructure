/**
 * @file 8-6-3计数排序.cpp
 * @author your name (you@domain.com)
 * @brief
 * 创建一个记录表，这个表记录了有多少个元素比当前元素小，设记录表的值为2，那么这个元素最后就应该放到数组下标为2的位置上
 * @version 0.1
 * @date 2023-03-15
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <iostream>
#include <vector>
#include "../debug.h"

using namespace std;

void coutSort(vector<int> &vet)
{
    vector<int> count(vet.size(), 0);
    for (int i = 0; i < vet.size(); i++)
    {
        for (int j = i + 1; j < vet.size(); j++)
        {
            if (vet[i] < vet[j])
            {
                count[j]++;
            }
            else
            {
                count[i]++;
            }
        }
    }
    vector<int> buff(vet.size(), 0);
    for (int i = 0; i < count.size(); i++)
    {
        buff[count[i]] = vet[i];
    }

    vet.swap(buff);
}

int main(int argc, char const *argv[])
{
    vector<int> vet{2, 4, 1, 5, 8, 0, 3, 1, 2};
    DisPlay(vet);
    coutSort(vet);
    DisPlay(vet);                           
    return 0;
}
