#include "Hash.h"

using namespace std;

void test1()
{
    Hash<char, int> hash;
    hash.insert({'a', 1});
    hash.insert({'c', 2});
    hash.insert({'d', 4});
    hash.insert({'e', 7});
    hash.insert({'b', 8});
    hash.insert({'p', 2});
    hash.disPlay();
    cout << hash['a'] << endl;
    cout << hash['z'] << endl;
}

void test2()
{
    vector<string> Array = {"苹果", "香蕉", "西瓜", "香蕉", "香蕉", "西瓜", "西瓜", "苹果"};
    Hash<string, int> Hash;
    for (int i = 0; i < Array.size(); i++)
    {

        Hash.insert(make_pair(Array[i], i));
    }
    Hash.disPlay();
}

int main(int argc, char const *argv[])
{
    test1();
    test2();
    return 0;
}
