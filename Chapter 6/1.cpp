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
int n, m, nowx, bestx;
bool g[MAX][MAX];
bool now[MAX], best[MAX];
void DFS(int u)
{
    if (u > n)
    {
        bestx = nowx;
        for (int i = 1; i <= n; i++)
            best[i] = now[i];
        return;
    }
    now[u] = true;
    for (int v = 1; v < u; v++)
    {
        if (now[v] && !g[u][v])
        {
            now[u] = false;
            break;
        }
    }
    if (now[u])
        nowx++, DFS(u + 1), nowx--;
    now[u] = false;
    if (nowx + n - u > bestx)
    {
        now[u] = false;
        DFS(u + 1);
    }
}
int main(int agrc, char *agrv[])
{
    scanf("%d %d", &n, &m);
    //while (~scanf("%d %d", &n, &m))
    int a, b;
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d", &a, &b);
        g[a][b] = g[b][a] = true;
    }
    DFS(1);
    printf("%d\n", bestx);
    int k = 1;
    for (int i = 1; i <= n; i++)
    {
        if (best[i])
        {
            printf("%d", i);
            if (k != bestx)
                printf(" ");
            k++;
        }
    }
}
