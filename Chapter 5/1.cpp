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
#define MAX 510
//#define INF 1000000000
using namespace std;
//typedef long long int LL;
int n, maxn, laste, ans, maxst, res;
struct node
{
    int st, ed;
} act[MAX];
bool cmp(node a, node b)
{
    return a.ed < b.ed;
}
void DFS()
{
    bool flag = true;
    for (int i = 0; i < n; i++)
    {
        if (laste > maxst)
            break;
        int t = act[i].ed - act[i].st, laste1 = laste;
        if (laste <= act[i].st && res + ans > maxn)
        {
            ans += t;
            laste = act[i].ed;
            res -= t;
            DFS();
            res += t;
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
        maxst = 0, res = 0;
        for (int i = 0; i < n; i++)
        {
            scanf("%d %d", &act[i].st, &act[i].ed);
            maxst = max(maxst, act[i].st);
            res += act[i].ed - act[i].st;
        }
        maxn = 0, laste = 0, ans = 0;
        sort(act, act + n, cmp);
        DFS();
        printf("%d", maxn);
    }
}
