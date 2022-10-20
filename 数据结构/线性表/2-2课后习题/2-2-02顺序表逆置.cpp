#include "Common.h"

template <class ElemType>
void reverse(vector<ElemType> &vet)
{
    size_t begin = 0;
    size_t end = vet.size() - 1;
    while (begin < end)
    {
        swap(vet[begin], vet[end]);
        begin++;
        end--;
    }
}

int main()
{
    vector<int> vet = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    SqlList<int> list(vet);
    reverse(list._vet);
    list.PrintVet();
    return 0;
}