#include "../debug.hpp"

int Partition(vector<int> &vet, int left, int right)
{
    int key = vet[left]; // 基准值
    while (left < right)
    {
        // 起始left为坑
        while (left < right && vet[right] >= key)
        {
            right -= 1;
        }
        swap(vet[left], vet[right]);
        // right为坑
        while (left < right && vet[left] <= key)
        {
            left += 1;
        }
        swap(vet[left], vet[right]);
    }
    vet[left] = key;
    return left;
}
void QuickSort(vector<int> &vet, int left, int right)
{
    if (left > right)
    {
        return;
    }
    int mid = Partition(vet, left, right);
    QuickSort(vet, left, mid - 1);
    QuickSort(vet, mid + 1, right);
}
void QuickSort(vector<int> &vet)
{
    QuickSort(vet, 0, vet.size() - 1);
}

int main(int argc, char const *argv[])
{
    vector<int> arr = {4, 2, 4, 7, 0, 1, 3};
    PrintVector(arr);
    QuickSort(arr);
    PrintVector(arr);
    return 0;
}
