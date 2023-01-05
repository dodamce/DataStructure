#include "criticalpath.h"

int main()
{
    ALGraph G;
    CreateAOE(&G); // 创建AOE网
    initStack(&T);
    TopologicalOrder(G);
    CriticalPath(G);
    deleStack(T);
    system("pause");
    return 0;
}
