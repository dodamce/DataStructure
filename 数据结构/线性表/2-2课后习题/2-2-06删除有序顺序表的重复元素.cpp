#include "Common.h"

template <typename Element>
void DelRepEle(SqlList<Element> &list)
{
    //前后指针
    int begin = 0;
    int end = 1;
    while (end < list._length)
    {
        if (list[begin] != list[end])
        {
            if (end - begin > 1)
            {
                list._vet.erase(list._vet.begin() + begin, list._vet.begin() + end - 1);
                list._length -= end - begin - 1;
            }
            begin++;
            end = begin + 1;
        }
        else
        {
            end++;
        }
    }
}

int main()
{
    SqlList<int> list({1, 1, 1, 1, 2, 2, 2, 2, 2, 3, 4, 5, 6, 7, 8});
    DelRepEle(list);
    list.PrintVet();
    return 0;
}