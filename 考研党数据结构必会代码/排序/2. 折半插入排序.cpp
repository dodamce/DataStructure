#include "../debug.hpp"
using namespace std;

int Search(vector<int> &vet, int left, int right, int val)
{
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (vet[mid] == val)
        {
            left = mid + 1; // 保证稳定性,当元素相等时,位置定位到最后一个相同的元素
        }
        else if (vet[mid] < val)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return left;
}

void BinInsertSort(vector<int> &vet)
{
    for (int i = 1; i < vet.size(); i++)
    {
        if (vet[i] < vet[i - 1])
        {
            // 找插入的位置，大于val的最小值
            int val = vet[i];
            int left = Search(vet, 0, i, val);
            int right = i;
            while (left < right)
            {
                vet[right] = vet[right - 1];
                right -= 1;
            }
            vet[left] = val;
        }
    }
}

int main(int argc, char const *argv[])
{
    vector<int> arr = {4, 2, 4, 7, 0, 1, 3};
    PrintVector(arr);
    BinInsertSort(arr);
    PrintVector(arr);
    return 0;
}
