#include "Common.h"

//需求：时间复杂度O(n) 空间复杂度O(1)

//稳定删除
template <typename Element>
void DelElem(vector<Element> &vet, const Element &delPos)
{
    //记录要删除的元素个数del，在遍历时，将元素向前移动del个
    int del = 0;
    for (int i = 0; i < vet.size(); i++)
    {
        if (vet[i] == delPos)
        {
            del++;
        }
        else
        {
            //将元素向前移动del个
            vet[i - del] = vet[i];
        }
    }
    //删除剩下的元素
    vet.resize(vet.size() - del);
}

//不稳定删除
template <typename Element>
void DelElemIsStable(vector<Element> &vet, const Element &delPos)
{
    //左指针找要删除的元素，右指针找不需要删除的位置，最后交换
    int begin = 0;
    int end = vet.size() - 1;
    int size = vet.size();
    while (begin < end)
    {
        while (vet[end] == delPos && end > begin)
        {
            end--;
        }
        while (vet[begin] != delPos && begin < end)
        {
            begin++;
        }
        swap(vet[begin], vet[end]);
    }
    if (end == 0)
    {
        vet.clear();
        return;
    }
    vet.resize(end + 1);
}

int main()
{
    vector<int> del = {1, 1, 1, 1, 1, 1, 1};
    // vector<int> del = {1, 2, 3, 4, 5, 6, 1, 4, 5, 2, 5, 1};
    // vector<int> nodel = {1, 2, 3, 4, 5, 6};

    // vector<int> del = {1, 2, 3, 4, 5};
    SqlList<int> list(del);

    SqlList<int> list2({1,2,3,4});
    DelElemIsStable(list._vet, 1);
    list.PrintVet();

    // DelElem(vet, 1);
    // DelElem(del, 1);
    // DelElem(nodel, 10);
    // DelElemIsStable(vet, 1);
    // DelElemIsStable(del, 1);
    // DelElemIsStable(nodel, 10);
    // PrintVet(vet);
    // PrintVet(del);
    // PrintVet(nodel);
    return 0;
}