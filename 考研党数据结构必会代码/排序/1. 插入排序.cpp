#include "../debug.hpp"
using namespace std;

void InsertSort(vector<int> &arr)
{
    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] < arr[i - 1])
        {
            int left = i - 1;
            int val = arr[i];
            while (left >= 0 && arr[left] > val)
            {
                arr[left + 1] = arr[left];
                left -= 1;
            }
            arr[left + 1] = val;
        }
    }
}

int main(int argc, char const *argv[])
{
    vector<int> arr = {4, 2, 5, 7, 0};
    PrintVector(arr);
    InsertSort(arr);
    PrintVector(arr);
    return 0;
}
