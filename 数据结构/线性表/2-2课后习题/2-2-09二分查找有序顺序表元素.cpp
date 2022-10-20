#include "Common.h"

/**
 * @brief 在数组中查找find元素，找到了于后面的元素交换，否则插入到数组位置上，数组有序
 *
 * @param vet
 * @param find
 * @return true:找到元素，并且交换 false:没有找到元素，有序插入到数组上
 */

//二分查找
bool FindEleInArray(vector<int> &vet, int find)
{
    int begin = 0;
    int end = vet.size() - 1;
    while (begin <= end)
    {
        int mid = (begin + end) / 2;
        if (vet[mid] == find)
        {
            //和后面的元素进行交换
            if (mid + 1 <= vet.size() - 1)
            {
                swap(vet[mid], vet[mid + 1]);
            }
            return true;
        }
        else if (vet[mid] < find)
        {
            begin = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    //没有招到对应的位置插入到对应的位置，使数组有序
    vet.insert(vet.begin() + begin, find);
    return false;
}

int main()
{
    vector<int> vet = {1, 2, 3, 4, 5, 6, 7, 8, 20, 40};
    FindEleInArray(vet, 10);
    SqlList<int>::PrintVet(vet);
    return 0;
}