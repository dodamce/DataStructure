#include <string>

#include <iostream>

using namespace std;

/**
 * @brief 字符串暴力匹配算法
 *
 * @param src 源字符串
 * @param dst 需要匹配的字符串
 * @return int 返回第一次出现要匹配的子串的位置，下标从0开始
 */
int BF(const string &src, const string &dst)
{
    if (src.size() == 0 || dst.size() == 0)
    {
        return -1;
    }
    int posSrc = 0;
    int posDst = 0;
    while (posSrc < src.length() && posDst < dst.length())
    {
        if (src[posSrc] == dst[posDst])
        {
            posSrc++;
            posDst++;
        }
        else
        {
            //回退
            posSrc = posSrc - posDst + 1;
            posDst = 0;
        }
    }
    //说明匹配到最后的字符了,返回第一次出现字串的位置
    if (posDst == dst.length())
    {
        return posSrc - posDst;
    }
    else
    {
        return -1;
    }
}

int main()
{
    // cout << BF("abcabcabcdabcde", "abcd") << endl;
    cout << BF("abcdabcabcdabcde", "abcd") << endl;

    return 0;
}