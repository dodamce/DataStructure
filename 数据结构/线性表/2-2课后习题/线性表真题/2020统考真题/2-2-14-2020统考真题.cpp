//三元组的最小距离

/**
 【2020统考真题】
 定义三元组(a, b, c) (a、b、c均为正数）的距离D= |a-b| + |b-c| + |c-a|
 给定3个非空整数集合S1、S2,和S3，按升序分别存储在3个数组中。请设计一个尽可能高效的算法.
 计算并输出所有可能的三元组(a, b, c)中的最小距离。例
 如S1= {-1,0,9}，S2 = {-25,-10,10,11}，S3 = {2,9,17,30,41}
 则最小距离为2，相应的三元组为(9,10,9)。

 思路：
 a<b<c时
|a-b| = l1
|b-c| = l2
|c-a| = l3
D= l1+l2+l3 =2l3 只需要让l3最小即可

每次三个数组中最小的值作为a，最大的值作为c

每次循环让a改变，c不变 直到循环结束，返回循环数值最小的值

 */

//难点，需要后续跟进

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isMin(const int a, const int b, const int c)
{
    return a < b && a < c;
}

int getMinDistance(vector<int> &S1, vector<int> &S2, vector<int> &S3)
{
    int min = INT_MAX;
    int pos_s1 = 0, pos_s2 = 0, pos_s3 = 0;
    while (pos_s1 < S1.size() && pos_s2 < S2.size() && pos_s3 < S3.size())
    {
        //计算距离D
        int D = abs(S1[pos_s1] - S2[pos_s2]) + abs(S2[pos_s2] - S3[pos_s3]) + abs(S1[pos_s1] - S3[pos_s3]);
        if (D < min)
        {
            min = D;
        }
        //改变a,b,c最小值a,其他的值不变
        if (isMin(S1[pos_s1], S2[pos_s2], S3[pos_s3]))
        {
            pos_s1++;
        }
        else if (isMin(S2[pos_s2], S3[pos_s3], S1[pos_s1]))
        {
            pos_s2++;
        }
        else
        {
            pos_s3++;
        }
    }
    return min;
}

int main()
{
    vector<int> S1 = {-1, 0, 9};
    vector<int> S2 = {-25, -10, 10, 11};
    vector<int> S3 = {2, 9, 17, 30, 41};
    cout << getMinDistance(S1, S2, S3) << endl;
    return 0;
}