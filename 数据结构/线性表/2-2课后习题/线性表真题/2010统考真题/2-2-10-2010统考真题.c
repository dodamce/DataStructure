#include <stdio.h>

void swap(int *left, int *right)
{
    int temp = *left;
    *left = *right;
    *right = temp;
}
//数组区间[]型
void _reserve(int *arr, int left, int right)
{
    while (left <= right)
    {
        swap(&arr[left], &arr[right]);
        left++;
        right--;
    }
}

void Reserve(int *arr, int length, int p)
{
    _reserve(arr, 0, length - 1);
    _reserve(arr, 0, length - p - 1);
    _reserve(arr, length - p, length - 1);
}

//时间复杂度O(N)

int main()
{
    int array[11] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    Reserve(array, sizeof(array) / sizeof(array[0]), 4);

    for (int i = 0; i < sizeof(array) / sizeof(array[0]); i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
    return 0;
}