#include "./插入排序/InsertSort.h"
#include "./插入排序/HalfInsertSort.h"
#include "./插入排序/ShellSort.h"
#include "./交换排序/BubbleSort.h"
#include "./交换排序/QuickSort.h"
#include "./选择排序/SelectSort.h"
#include "./选择排序/HeapSort.h"
#include "debug.h"

#define SIZE 10

#include <time.h>

template <class ValueType>
void TestInsertSort(vector<ValueType> &vet)
{
    InsertSort(vet);
    DisPlay(vet);
}

// ----------------------------------------------------------------

template <class ValueType>
void TestHalfInsertSort(vector<ValueType> &vet)
{
    HalfInsertSort(vet);
    DisPlay(vet);
}

// ----------------------------------------------------------------

template <class ValueType>
void TestShellSort(vector<ValueType> &vet)
{
    ShellSort(vet);
    DisPlay(vet);
}

// ----------------------------------------------------------------

template <class ValueType>
void TestBubbleSort(vector<ValueType> &vet)
{
    BubbleSort(vet);
    DisPlay(vet);
}

// ----------------------------------------------------------------
template <class ValueType>
void TestQuickSort(vector<ValueType> &vet)
{
    QuickSort(vet);
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
    vector<int> buff{9, 8, 7, 6, 5, 4, 3, 2, 1};
    // TestInsertSort(vet);
    // TestHalfInsertSort(buff);
    // TestShellSort(buff);
    // TestBubbleSort(buff);
    // TestQuickSort(buff);
    // SelectSort(buff);
    HeapSort(buff);
    DisPlay(buff);
    return 0;
}
