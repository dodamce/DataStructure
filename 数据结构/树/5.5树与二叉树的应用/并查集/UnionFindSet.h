//构建并查集

#include <assert.h>
#include <vector>
#include <stdio.h>

class UnionFindSet
{
private:
    //数组的下标保存的是并查集的数据，数组的值记录的是并查集这个节点的父节点下标
    std::vector<int> ufs;

public:
    UnionFindSet(size_t size)
    {
        ufs.resize(size, -1);
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
            ufs[root_x] += ufs[root_y];
            ufs[root_y] = root_x;
        }
    }

    //找data的根
    int FindRoot(int data)
    {
        int root = data;
        while (ufs[root] >= 0)
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
        return root;
    }

    //获取并查集中树的个数
    int GetTreeSize()
    {
        int ret = 0;
        for (int i = 0; i < ufs.size(); i++)
        {
            if (ufs[i] < 0)
                ret += 1;
        }
        return ret;
    }

    //打印并查集信息
    void PrintUfs()
    {
        for (int i = 0; i < ufs.size(); i++)
        {
            printf("%2d ", i);
        }
        printf("\n");
        for (int i = 0; i < ufs.size(); i++)
        {
            printf("%2d ", ufs[i]);
        }
        printf("\n");
    }
};