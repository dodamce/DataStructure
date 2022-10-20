#include "Common.h"

/**
 * @brief 删除有序顺序表的一段数值
 *
 */

template <typename Element>
bool DelEleForRange(SqlList<Element> &list, const Element begin, const Element end)
{
    if (begin > end)
    {
        return false;
    }
    size_t del = 0;
    for (int i = 0; i < list._length; i++)
    {
        if (list._vet[i] >= begin && list._vet[i] <= end)
        {
            del++;
            continue;
        }
        list._vet[i - del] = list._vet[i];
    }
    list._length -= del;
    return true;
}

int main()
{
    // SqlList<int> list({1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12});
    // SqlList<int> list({1, 4, 1, 3, 1});
    SqlList<int> list({4, 1, 7, 3, 8, 6});
    DelEleForRange(list, 4, 7);
    list.PrintVet();
    return 0;
}