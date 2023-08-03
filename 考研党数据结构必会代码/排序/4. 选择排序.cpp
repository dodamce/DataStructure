#include "../debug.hpp"

void SelectSort(vector<int> &vet)
{
    for (int i = 0; i < vet.size(); i++)
    {
        int max = 0;
        for (int j = 0; j < vet.size() - i; j++)
        {
            if (vet[max] < vet[j])
            {
                max = j;
            }
        }
        swap(vet[max], vet[vet.size() - i - 1]);
    }
}
int main(int argc, char const *argv[])
{
    vector<int> arr = {4, 2, 4, 7, 0, 1, 3};
    PrintVector(arr);
    SelectSort(arr);
    PrintVector(arr);
    return 0;
}
