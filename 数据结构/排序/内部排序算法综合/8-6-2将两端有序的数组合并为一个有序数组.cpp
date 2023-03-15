#include <iostream>
#include <vector>
#include "../debug.h"

using namespace std;

int findBoard(vector<int> &vet)
{
    int board = 0;
    for (int i = 0; i < vet.size() - 1; i++)
    {
        if (vet[i] < vet[i + 1])
        {
            board += 1;
        }
        else
        {
            break;
        }
    }
    return board;
}

void MergeVet(vector<int> &vet)
{
    // 找vet数组的有序边界
    int board = findBoard(vet); //[0,board],[board,vet.size()-1]有序
    vector<int> buff;
    int begin_left = 0;
    int end_left = board;
    int begin_right = board + 1;
    int end_right = vet.size() - 1;
    while (begin_left <= end_left && begin_right < end_right)
    {
        if (vet[begin_left] <= vet[begin_right])
        {
            buff.push_back(vet[begin_left]);
            begin_left += 1;
        }
        else
        {
            buff.push_back(vet[begin_right]);
            begin_right += 1;
        }
    }
    while (begin_left <= end_left)
    {
        buff.push_back(vet[begin_left++]);
    }
    while (begin_right <= end_right)
    {
        buff.push_back(vet[begin_right++]);
    }
    vet.swap(buff);
}

int main(int argc, char const *argv[])
{
    vector<int> vet{1, 2, 3, 4, 0, 1, 2, 3, 6};
    DisPlay(vet);

    MergeVet(vet);
    DisPlay(vet);
    return 0;
}
