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
    int w, c;
} a[MAX][MAX];
int n, m, cost, minw;
int tw, tc, rw;
void DFS(int index)
{
    if (index == n)
    {
        minw = min(minw, tw);
        return;
    }
    for (int i = 0; i < m; i++)
    {
        tc += a[i][index].c, tw += a[i][index].w;
        if (cost >= tc && minw > tw)
            DFS(index + 1);
        tc -= a[i][index].c, tw -= a[i][index].w;
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
        DFS(0);
        printf("%d", minw);
    }
}