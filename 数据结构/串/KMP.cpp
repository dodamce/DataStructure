#include <string>
#include <iostream>
#include <vector>
#include <assert.h>

using namespace std;

// 使用KMP算法返回src第一个匹配dst的位置,下标从0开始,从src的pos位置开始匹配

void InitNext(const string &dst, vector<int> &next)
{
    next[0] = -1;
    next[1] = 0;
    int k = 0;
    for (int i = 2; i < dst.size(); i++)
    {
        k = next[i - 1];
        while (k != -1 && dst[i - 1] != dst[k])
        {
            k = next[k];
        }
        next[i] = k + 1;
    }
}

int KMP(const string &src, const string &dst, int pos)
{
    assert(pos >= 0 && pos < src.length() && src.size() > 0 && dst.size() > 0);
    int i = pos;
    int j = 0;
    int srcSize = src.size();
    int dstSize = dst.size();
    vector<int> next(dst.size(), -1);
    InitNext(dst, next);
    while (i < srcSize && j < dstSize)
    {
        if (j == -1 || src[i] == dst[j])
        {
            i++;
            j++;
        }
        else
        {
            j = next[j];
        }
    }
    if (j == dst.size())
    {
        return i - j;
    }
    else
    {
        return -1;
    }
}

int main()
{
    // cout << KMP("abcabcabcdabcde", "abcd", 0) << endl;
    // cout << KMP("abcdabcabcdabcde", "abcd", 0) << endl;
    cout << KMP("abcdabcabcdabcde", "ababaaababaa", 0) << endl;

    return 0;
}