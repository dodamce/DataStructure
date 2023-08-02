#include "../debug.hpp"
int BinSearch(vector<int> &array, int val)
{
    int left = 0;
    int right = array.size() - 1; //[]
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (array[mid] == val)
        {
            return mid;
        }
        else if (array[mid] > val)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    // 没查找到
    return -1;
}
int main(int argc, char const *argv[])
{
    vector<int> ret = {1, 2, 3, 4, 5, 6};
    PrintVector(ret);
    cout << BinSearch(ret, 9);
    return 0;
}
