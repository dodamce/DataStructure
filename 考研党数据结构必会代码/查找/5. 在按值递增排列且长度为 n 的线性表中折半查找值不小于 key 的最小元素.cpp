#include "../debug.hpp"
using namespace std;

int BinSearch(vector<int> &vet, int val)
{
    int left = 0;
    int right = vet.size() - 1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (vet[mid] < val)
        {
            left = mid + 1;
        }
        else if (vet[mid] > val)
        {
            right = mid - 1;
        }
        else
        {
            return mid;
        }
    }
    if (left <= vet.size() - 1)
    {
        return left;
    }
    return -1;
}

int main(int argc, char const *argv[])
{
    vector<int> ret = {1, 2, 3, 4, 6};
    PrintVector(ret);
    cout << BinSearch(ret, 5) << endl;
    return 0;
}