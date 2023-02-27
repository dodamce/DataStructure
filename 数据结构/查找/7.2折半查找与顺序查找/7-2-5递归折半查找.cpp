#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool MinFind(vector<int> &vet, int find, int begin, int end)
{
    int mid = (begin + end) / 2;
    if (begin > end)
    {
        return false;
    }
    if (vet[mid] < find)
    {
        return MinFind(vet, find, mid + 1, end);
    }
    else if (vet[mid] > find)
    {
        return MinFind(vet, find, begin, mid - 1);
    }
    else
    {
        return true;
    }
}

bool MinFind(vector<int> &vet, int find)
{
    return MinFind(vet, find, 0, vet.size() - 1);
}
int main(int argc, char const *argv[])
{
    vector<int> ret = {1, 4, 2, 5, 3, 6, 0, 9, 8};
    std::sort(ret.begin(), ret.end());
    std::cout << MinFind(ret, 7) << std::endl;
    return 0;
}
