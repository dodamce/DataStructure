//构建并查集

#include <assert.h>
#include <vector>

class UnionFindSet
{
private:
    //数组的下标保存的是并查集的数据，数组的值记录的是并查集这个节点的父节点下标
    std::vector<int> ufs;

public:
    UnionFindSet(size_t size)
    {
        ufs.reserve(size, -1);
    }

    // x和y所在的两个集合合并
    void Union(int x, int y)
    {
        assert(x < ufs.size() && y < ufs.size());
        int root_x = FindRoot(x);
        int root_y = FindRoot(y);

        if (root_x != root_y)
        {
            //不在一棵树上
            ufs[root_x] += root_y;
            ufs[root_y] = root_x;
        }
    }

    //找data的根
    int FindRoot(int data)
    {
        int root = data;
        while (ufs[root] > 0)
        {
            root = ufs[root];
        }

        //找到根后，这里做优化，降低并查集树的高度
        //把这个节点到根节点路径上的所有节点插入到根节点上
        while (data != root)
        {
            int parent = ufs[data];
            ufs[data] = root;
            data = parent;
        }
    }
};