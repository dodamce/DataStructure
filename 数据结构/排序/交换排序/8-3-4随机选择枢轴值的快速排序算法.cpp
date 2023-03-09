#include <vector>
#include <algorithm>
#include <iostream>
#include <time.h>
#include "../debug.h"

using namespace std;

// 挖坑法
int _sort(vector<int> &vet, int begin, int end)
{
    // 枢轴值
    int keyPos = rand() % (end - begin + 1) + begin;
    // 将枢轴值交换到数组开始
    std::swap(vet[begin], vet[keyPos]);

    int KeyValue = vet[begin];

    // begin找大于枢纽值,end找小于枢轴值,开始begin位坑
    while (begin < end)
    {
        while (begin < end && vet[end] > KeyValue)
        {
            end--;
        }
        std::swap(vet[begin], vet[end]);

        // 此时end位置位坑
        while (begin < end && vet[begin] < KeyValue)
        {
            begin++;
        }
        std::swap(vet[begin], vet[end]);
    }

    vet[begin] = KeyValue;
    return begin;
}

void _quickSort(vector<int> &vet, int begin, int end)
{
    if (begin >= end)
    {
        return;
    }
    int mid = _sort(vet, begin, end);
    _quickSort(vet, begin, mid - 1);
    _quickSort(vet, mid + 1, end);
}

void quickSort(vector<int> &vet)
{
    srand((unsigned int)time(nullptr));
    _quickSort(vet, 0, vet.size() - 1);
}

int main(int argc, char const *argv[])
{
    vector<int> vet = {9, 6, 5, 8, 4, 3, 1, 0, 2};
    quickSort(vet);
    DisPlay(vet);
    return 0;
}
