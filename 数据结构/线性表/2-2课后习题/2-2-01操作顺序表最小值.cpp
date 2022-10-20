#include <iostream>

#include <vector>
using namespace std;

//函数返回是否删除成功，并将最小值从数组上删除，空出的位置以数组最后元素填上
bool PopMinElement(vector<int> &vet, int &min)
{
    if (vet.size() == 0)
    {
        return false;
    }
    min = vet[0];
    size_t minPos = 0;
    for (int i = 0; i < vet.size(); i++)
    {
        if (vet[i] < min)
        {
            min = vet[i];
            minPos = i;
        }
    }
    swap(vet[minPos], vet[vet.size() - 1]);
    vet.erase(vet.end() - 1);
    return true;
}

int main()
{
    vector<int> vet = {3, 5, 1, 7, 0, 9, 2};
    int min = 0;
    bool ret = PopMinElement(vet, min);

    cout << "min: " << min << " ret: " << ret << endl;

    for (auto element : vet)
    {
        cout << element << " ";
    }
    return 0;
}