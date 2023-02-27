#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * @brief 线性表中各结点的检索概率不等时，可用如下策略提高顺序检索的效率：
 * 若找到指定的结点，则将该结点和其前驱结点（若存在）交换，使得经常被检索的结点尽量位于表的前端。
 * 试设计在顺序结构和链式结构的线性表上实现上述策略的顺序检索算法
 */

class IndexVet
{
private:
    vector<int> buff;

public:
    IndexVet(const vector<int> &vet)
    {
        for (auto &num : vet)
        {
            buff.push_back(num);
        }
    }

    void DisPlay()
    {
        for (auto &num : buff)
        {
            cout << num << " ";
        }
        cout << "\n";
    }

    bool Find(int val)
    {
        for (int i = 0; i < buff.size(); i++)
        {
            if (buff[i] == val)
            {
                // val这个位置向前移动
                if (i - 1 >= 0)
                {
                    std::swap(buff[i], buff[i - 1]);
                }
                return true;
            }
        }
        return false;
    }
};

int main(int argc, char const *argv[])
{
    IndexVet vet({3, 2, 5, 1, 6, 7, 0});
    vet.DisPlay();
    vet.Find(2);
    vet.DisPlay();
    vet.Find(2);
    vet.DisPlay();
    vet.Find(0);
    vet.DisPlay();
    return 0;
}
