#include <vector>
#include "../debug.hpp"
using namespace std;
/**
using c++11
 */

void reverse(vector<int> &vet)
{
    int left = 0;
    int right = vet.size() - 1;
    while (left < right)
    {
        swap(vet[left], vet[right]);
        left += 1;
        right -= 1;
    }
}

int main(int argc, char const *argv[])
{
    vector<int> vet = {1, 2, 3, 4, 5};
    reverse(vet);
    PrintVector(vet);
    return 0;
}
