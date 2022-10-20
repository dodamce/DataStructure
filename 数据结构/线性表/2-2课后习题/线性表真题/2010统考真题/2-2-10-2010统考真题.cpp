//移动顺序表的元素，效率尽可能高效，使用C/C++ 或 Java
#include "Common.h"

void ReserveArray(vector<int> &vet, size_t pos)
{
    //先全部逆转
    std::reverse(vet.begin(), vet.end());
    //逆转size-pos个
    std::reverse(vet.begin(), vet.begin() + vet.size() - pos);
    //逆转后pos个
    std::reverse(vet.begin() + vet.size() + pos, vet.end());
}

//空间复杂度O(1),空间复杂度O(n)

int main()
{
    vector<int> vet = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    ReserveArray(vet, 4);
    SqlList<int>::PrintVet(vet);
    return 0;
}