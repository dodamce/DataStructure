#include "../debug.hpp"
// 从小到大排列，建立大堆
void HeapAdjust(vector<int> &vet, int parent, int size)
{
    // vet从begin开始调整为堆，堆的大小为size
    int child = 2 * parent + 1;
    while (child <= size)
    {
        if (child + 1 <= size)
        {
            if (vet[child] < vet[child + 1])
            {
                child += 1;
            }
        }
        if (vet[parent] < vet[child])
            swap(vet[parent], vet[child]);
        parent = child;
        child = 2 * parent + 1;
    }
}
void HeapSort(vector<int> &vet)
{
    for (int i = ((vet.size() - 1) - 1) / 2; i >= 0; i--)
    {
        HeapAdjust(vet, i, vet.size() - 1);
    }
    // PrintVector(vet);
    int endPos = vet.size() - 1;
    while (endPos >= 0)
    {
        swap(vet[0], vet[endPos]);
        endPos -= 1;
        HeapAdjust(vet, 0, endPos);
    }
}
int main(int argc, char const *argv[])
{
    vector<int> arr = {4, 2, 4, 7, 0, 1, 3};
    PrintVector(arr);
    HeapSort(arr);
    PrintVector(arr);
    return 0;
}
