#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <functional>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#define MAX 51
//#define INF 1000000000
using namespace std;
//typedef long long int LL;
int n, maxn, laste, ans;
struct node
{
    int st, ed;
} act[MAX];
void DFS()
{
    bool flag = true;
    for (int i = 0; i < n; i++)
    {
        if (laste <= act[i].st)
        {
            int t = act[i].ed - act[i].st, laste1 = laste;
            ans += t;
            laste = act[i].ed;
            DFS();
            ans -= t;
            laste = laste1;
            flag = false;
        }
    }
    if (flag)
        maxn = max(maxn, ans);
}
int main(int agrc, char *agrv[])
{
    while (~scanf("%d", &n))
    {
        for (int i = 0; i < n; i++)
            scanf("%d %d", &act[i].st, &act[i].ed);
        maxn = 0, laste = 0, ans = 0;
        DFS();
        printf("%d", maxn);
    }
}
