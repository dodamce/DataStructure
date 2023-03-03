#include "./插入排序/InsertSort.h"

#define SIZE 10

#include <time.h>

template <class ValueType>
void DisPlay(const vector<ValueType> &vet)
{
    for (auto &val : vet)
    {
        cout << val << " ";
    }
    cout << "\n";
}

template <class ValueType>
void TestInsertSort(vector<ValueType> &vet)
{
    InsertSort(vet);
    DisPlay(vet);
}

int main(int argc, char const *argv[])
{
    srand((unsigned)time(nullptr));
    vector<int> vet(SIZE);
    for (size_t i = 0; i < vet.size(); i++)
    {
        vet[i] = rand() % 100 + 1;
    }
    TestInsertSort(vet);
    return 0;
}
