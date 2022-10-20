#include "Common.h"

/**
 * @brief 逆转数组中两个数组的元素
 *
 * @param array 传入需要逆转的数组
 * @param m 第一个数组的长度
 * @param n 第二个数组的长度
 * @return true 逆转成功
 * @return false 逆转失败
 */

void Reserve(vector<int> &vet, int begin, int end)
{
    while (begin < end)
    {
        swap(vet[begin], vet[end]);
        begin++;
        end--;
    }
}

bool ReserveArray(vector<int> &array, int m, int n)
{
    if (m + n != array.size())
    {
        return false;
    }
    //先逆转整体，在分别逆转两个数组
    Reserve(array, 0, array.size() - 1);
    //逆转右数组
    Reserve(array, 0, n - 1);
    //逆转左数组
    Reserve(array, n, n + m - 1);
    return true;
}

int main()
{
    vector<int> array = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
    ReserveArray(array, 6, array.size() - 6);
    SqlList<int>::PrintVet(array);
    return 0;
}