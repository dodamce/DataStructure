//找数组中没有出现的最小正整数

//本人思路：

//先进行排序，在排序后的数组中找第一个不连续的正整数

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int GetMinIntegral(vector<int> &vet)
{
    //快速排序时间复杂度O(NlogN)
    std::sort(vet.begin(), vet.end());

    //找到数组第一个非0元素
    int pos = 0;
    while (pos < vet.size() && vet[pos] <= 0)
    {
        pos++;
    }
    int ret = 1;
    if (pos == vet.size())
        return ret;

    //找到数组第一个不连续的正整数
    for (int i = pos; i < vet.size(); i++)
    {
        if (vet[i] != ret)
        {
            return ret;
        }
        ret++;
    }
    return ret;
}

//时间复杂度O(NlogN+N)=O(NlogN) 空间复杂度O(1)

//标准答案算法：
/*
使用一个数组cont记录函数传入的数组是否出现了1-n的连续数字 cont[0]对应的整数为1, cont[n-1]对应的整数n 数组初始化为0
传入的数组的大小为n，可能返回值为1 ~ n+1，当转入的数组内部的数字刚好是1 ~ n时，cont数组没有空位，否则会出现空位
*/

/**
简单的理解就是创建一个数组标记传入的数组内的值，用新创建数组的下标来表示传入数组内的值
 */
int GetMinIntegral(vector<int> &vet, bool ret)
{
    if (ret == false)
    {
        return GetMinIntegral(vet);
    }
    else
    {
        //答案思路
        vector<bool> cont(vet.size(), false);
        int end = vet.size();
        for (int i = 0; i < vet.size(); i++)
        {
            if (vet[i] > 0 && vet[i] <= end)
            {
                cont[vet[i] - 1] = true;
            }
        }

        //找到标记的数组的第一个false值的下标就是数组没有出现的最小的正整数
        int pos = 0;
        for (pos = 0; pos < cont.size(); pos++)
        {
            if (cont[pos] == false)
            {
                break;
            }
        }
        return pos + 1;
    }
}

int main()
{
    vector<int> vet = {-5, 0, 1, 2, 4};
    cout << GetMinIntegral(vet) << endl;
    cout << GetMinIntegral(vet, true) << endl;
    return 0;
}