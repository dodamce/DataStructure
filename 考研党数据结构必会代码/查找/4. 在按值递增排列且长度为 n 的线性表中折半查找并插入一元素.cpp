#include "../debug.hpp"

// 使用折半插入值val,是vet保持有序
void BinInsert(vector<int> &vet, int val)
{
    // 查找最相近val的值在vet中的位置
    int left = 0;
    int right = vet.size() - 1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (vet[mid] > val)
        {
            right = mid - 1;
        }
        else if (vet[mid] < val)
        {
            left = mid + 1;
        }
        else if (vet[mid] == val)
        {
            // 查找最相近val的值在vet中的位置
            left = mid + 1;
        }
    }
    // vet.insert(vet.begin() + left, val);
    vet.resize(vet.size() + 1);
    // 拷贝元素
    for (int i = vet.size() - 1; i > left; i--)
    {
        vet[i] = vet[i - 1];
    }
    vet[left] = val;
}

int main(int argc, char const *argv[])
{
    vector<int> ret = {1, 2, 3, 4, 5, 6};
    PrintVector(ret);
    BinInsert(ret, 0);
    PrintVector(ret);
    return 0;
}
