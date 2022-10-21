#include <vector>
#include <iostream>
#include <assert.h>

using namespace std;

//寻找数组的主元素，这个元素数目超过数组的一般

int GetMainElem(vector<int> &vet)
{
    assert(vet.size() > 0);
    if (vet.size() == 1)
    {
        return vet[0];
    }

    //首先找到数组中出现次数最多的元素
    int times = 1;
    int ret = vet[0];
    for (int i = 0; i < vet.size(); i++)
    {
        if (vet[i] == ret)
        {
            times++;
        }
        else
        {
            if (times > 0)
            {
                times--;
            }
            else
            {
                //更换元素
                ret = vet[i];
                times = 1;
            }
        }
    }
    //找到出现次数最多的元素，判断其是否是出现次数超多数组一半
    int flags = 0;
    for (int i = 0; i < vet.size(); i++)
    {
        if (vet[i] == ret)
        {
            flags++;
        }
    }
    return flags > vet.size() / 2 ? ret : -1;
}

//时间复杂度O(n) 遍历两遍 空间复杂度为O(1)

int main()
{
    // vector<int> vet = {0, 5, 5, 3, 5, 1, 5, 7};
    vector<int> vet = {0, 5, 5, 3, 5, 7, 5, 5};
    cout << GetMainElem(vet) << endl;
    return 0;
}