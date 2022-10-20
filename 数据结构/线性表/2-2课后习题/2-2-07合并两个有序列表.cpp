#include "Common.h"

/**
 * @brief 合并两个有序列表
 *
 */

void MergeArray(vector<int> &front, vector<int> &end, vector<int> &ret)
{
    ret.clear();
    int front_begin = 0;
    int end_begin = 0;
    while (front_begin < front.size() && end_begin < end.size())
    {
        if (front[front_begin] < end[end_begin])
        {
            ret.push_back(front[front_begin]);
            front_begin++;
        }
        else
        {
            ret.push_back(end[end_begin]);
            end_begin++;
        }
    }
    while (front_begin < front.size())
    {
        ret.push_back(front[front_begin]);
        front_begin++;
    }
    while (end_begin < end.size())
    {
        ret.push_back(end[end_begin]);
        end_begin++;
    }
}

int main()
{
    vector<int> arr1 = {1, 2, 3, 4, 5, 6, 7, 8};
    vector<int> arr2 = {0};
    vector<int> ret;
    MergeArray(arr1, arr2, ret);
    SqlList<int>::PrintVet(ret);
    return 0;
}