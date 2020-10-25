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
#define MAX 31
#define INF 1000000000
using namespace std;
//typedef long long int LL;

struct node
{
    int w, c, no;
} a[MAX][MAX];

int n, m, cost, minw;
void DFS(int index, int tw, int tc)
{
    if (index == n)
    {
        minw = min(minw, tw);
        return;
    }
    for (int i = 0; i < m; i++)
    {
        int ttc = tc + a[i][index].c, ttw = tw + a[i][index].w;
        if (cost >= ttc && minw > ttw)
            DFS(index + 1, ttw, ttc);
    }
}

int main(int agrc, char *agrv[])
{
    while (~scanf("%d %d %d", &n, &m, &cost))
    {

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                scanf("%d", &a[j][i].w);
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                scanf("%d", &a[j][i].c);
            }
        }
        minw = INF;
        DFS(0, 0, 0);
        printf("%d", minw);
    }
}