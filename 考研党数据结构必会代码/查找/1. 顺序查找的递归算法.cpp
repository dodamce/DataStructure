#include <vector>
#include <iostream>
using namespace std;

int Search(vector<int> &seq, int val, int pos)
{
    if (pos >= seq.size())
    {
        return -1;
    }
    if (seq[pos] == val)
    {
        return pos;
    }
    return Search(seq, val, pos + 1);
}

int RecurSeqSearch(vector<int> &seq, int val)
{
    return Search(seq, val, 0);
}

int main(int argc, char const *argv[])
{
    vector<int> ret = {1, 2, 3, 4, 5};
    cout << RecurSeqSearch(ret, -1) << endl;
    return 0;
}
