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
#define MAX 33
#define INF 1000000000
using namespace std;
//typedef long long int LL;

struct node
{
    int w, c;
} a[MAX][MAX];
int b[MAX];
int n, m, cost, minw, tw, tc;
void DFS(int now)
{
    if (now == n + 1)
    {
        minw = min(minw, tw);
        return;
    }
    if (b[now])
    {
        DFS(now + 1);
        return;
    }
    for (int i = 1; i <= m; i++)
    {
        tc += a[now][i].c, tw += a[now][i].w;
        if (tc <= cost && tw < minw)
            DFS(now + 1);
        tc -= a[now][i].c, tw -= a[now][i].w;
    }
}

int main(int agrc, char *agrv[])
{
    while (~scanf("%d %d %d", &n, &m, &cost))
    {
        memset(b, 0, sizeof(b));
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                scanf("%d", &a[i][j].w);
            }
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                scanf("%d", &a[i][j].c);
            }
        }
        for (int i = 1; i <= n; i++)
        {
            int w1 = a[i][1].w, c1 = a[i][1].c, t = 1;
            bool flag = false;
            for (int j = 2; j <= m; j++)
            {
                if (a[i][j].w <= w1 && a[i][j].c <= c1)
                {
                    w1 = a[i][j].w, c1 = a[i][j].c;
                    t = j, flag = true;
                }
                else if (a[i][j].w < w1 || a[i][j].c < c1)
                    flag = false;
            }
            if (flag)
                b[i] = t;
        }
        for (int i = 1; i <= n; i++)
        {
            if (b[i])
                tw += a[i][b[i]].w, tc += a[i][b[i]].c;
        }
        minw = INF;
        DFS(1);
        printf("%d", minw);
    }
}
