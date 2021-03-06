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
bool table[MAX];
int mw[MAX], rw, rc, mc[MAX];
void DFS(int index, int tw, int tc)
{
    if (index == n)
    {
        minw = min(minw, tw);
        return;
    }
    for (int i = 0; i < m; i++)
    {
        int ttc = tc + a[index][i].c, ttw = tw + a[index][i].w;
        if (cost >= ttc && minw > ttw && !table[i] && rc - mc[index] + ttc <= cost) //&& (rw - mw[i] + ttw < minw)
        {
            table[i] = true;
            rw -= mw[index];
            rc -= mc[index];
            DFS(index + 1, ttw, ttc);
            table[i] = false;
            rw += mw[index];
            rc += mc[index];
        }
    }
}

int main(int agrc, char *agrv[])
{
    //scanf("%d %d %d", &n, &m, &cost);
    while (~scanf("%d %d %d", &n, &m, &cost))
    {
        rw = 0, rc = 0;
        for (int i = 0; i < n; i++)
        {
            int temp = INF;
            for (int j = 0; j < m; j++)
            {
                scanf("%d", &a[i][j].w);
                temp = min(temp, a[i][j].w);
            }
            mw[i] = temp;
            rw += temp;
        }
        for (int i = 0; i < n; i++)
        {
            int temp = INF;
            for (int j = 0; j < m; j++)
            {
                scanf("%d", &a[i][j].c);
                temp = min(temp, a[i][j].c);
            }
            mc[i] = temp;
            rc += temp;
        }
        minw = INF;
        DFS(0, 0, 0);
        printf("%d", minw);
    }
}