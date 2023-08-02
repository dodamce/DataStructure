#include "../debug.hpp"

int dfs(vector<int> &vet, int val, int left, int right)
{
    if (left > right)
        return -1;

    int mid = (left + right) / 2;
    if (vet[mid] == val)
        return mid;
    if (vet[mid] > val)
        return dfs(vet, val, left, mid - 1);
    else
        return dfs(vet, val, mid + 1, right);
}
int RecurBinSearch(vector<int> &vet, int val)
{
    return dfs(vet, val, 0, vet.size() - 1);
}
int main(int argc, char const *argv[])
{
    vector<int> ret = {1, 2, 3, 4, 5, 6};
    PrintVector(ret);
    cout << RecurBinSearch(ret, 4);
    return 0;
}
