#include "../debug.hpp"
void BubbleSort(vector<int> &vet)
{
    bool flag = true;
    for (int i = 0; i < vet.size(); i++)
    {
        bool flag = true;
        for (int j = 0; j < vet.size() - i - 1; j++)
        {
            if (vet[j] > vet[j + 1])
            {
                swap(vet[j], vet[j + 1]);
                flag = false;
            }
        }
        if (flag == true)
        {
            break;
        }
    }
}

int main(int argc, char const *argv[])
{
    vector<int> arr = {4, 2, 4, 7, 0, 1, 3};
    PrintVector(arr);
    BubbleSort(arr);
    PrintVector(arr);
    return 0;
}
