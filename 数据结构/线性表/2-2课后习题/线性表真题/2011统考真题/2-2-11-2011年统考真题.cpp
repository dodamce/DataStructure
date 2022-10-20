#include "Common.h"

//找两个有序数组的中位数

/**
先计算两个数组的中位数a，b

1. 如果中位数a=b则整体的中位数就是a或b

2. 如果中位数a<b，需要截取a数组的前面元素 截取b数组的后面的元素，中位数在[a,b]这个区间上

3. 如果中位数a>b，需要截取a数组的后面元素，截取b数组的前面元素，中位数在[b,a]这个区间上
 */

int FindMidNum(vector<int> &front, vector<int> &end)
{
    //先找front的中位数，end的中位数，判断两者的关系
    int front_begin = 0;
    int front_end = front.size() - 1;
    int end_begin = 0;
    int end_end = end.size() - 1;
    //直到两个序列只有一个元素时
    while (front_end != front_begin || end_end != end_begin)
    {
        //求两个数组的中位数
        int mid_front = (front_begin + front_end) / 2;
        int mid_end = (end_begin + end_end) / 2;
        if (front[mid_front] == end[mid_end])
        {
            // 中位数确认
            return front[mid_front];
        }
        else if (front[mid_front] < end[mid_end])
        {
            front_begin = mid_front;
            end_end = mid_end;
        }
        else if (front[mid_front] > end[mid_end])
        {
            front_end = mid_front;
            end_begin = mid_end;
        }
    }
    //返回两个数组中最小的
    return front[front_begin] < end[end_begin] ? front[front_begin] : end[end_begin];
}

//空间复杂度O(1) 时间复杂度O(logN)

int main()
{
    vector<int> vet = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> vet2 = {5, 6, 7, 8, 9, 10};

    cout << FindMidNum(vet, vet2) << endl;
    return 0;
}