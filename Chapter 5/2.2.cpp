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
#define MAX 50
#define INF 1000000000
using namespace std;
//typedef long long int LL;

struct node
{
    int w, c;
} a[MAX][MAX];
int n, m, cost, minw, ww[MAX], b[MAX];
//bool table[MAX];
int mw[MAX], rw, rc, mc[MAX];

void DFS(int index, int tw, int tc)
{
    if (index == n)
    {
        minw = min(minw, tw);
        return;
    }
    if (b[index] != -1)
    {
        int ttc = tc + mc[index], ttw = tw + mw[index];
        if (cost >= ttc && minw > ttw && rc - mc[index] + ttc <= cost && rw - mw[index] + ttw < minw)
        {
            //table[i] = true;
            rw -= mw[index];
            rc -= mc[index];
            DFS(index + 1, ttw, ttc);
            //table[i] = false;
            rw += mw[index];
            rc += mc[index];
        }
        return;
    }
    for (int i = 0; i < m; i++)
    {
        int ttc = tc + a[index][i].c, ttw = tw + a[index][i].w;
        if (cost >= ttc && minw > ttw && rc - mc[index] + ttc <= cost && rw - mw[index] + ttw < minw)
        {
            //table[i] = true;
            rw -= mw[index];
            rc -= mc[index];
            DFS(index + 1, ttw, ttc);
            //table[i] = false;
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
            int temp = INF, t = -1;
            for (int j = 0; j < m; j++)
            {
                scanf("%d", &a[i][j].w);
                if (temp > a[i][j].w)
                    temp = a[i][j].w, t = j;
            }
            mw[i] = temp; //记录最小每件物品的最小W
            ww[i] = t;    //记录最小W的物品号
            rw += temp;
        }
        for (int i = 0; i < n; i++)
        {
            int temp = INF, t = -1;
            for (int j = 0; j < m; j++)
            {
                scanf("%d", &a[i][j].c);
                if (temp > a[i][j].c)
                    temp = a[i][j].c, t = j;
            }
            mc[i] = temp;
            if (t == ww[i]) //最小C和最小W为同一件
                b[i] = t;
            else
                b[i] = -1;
            rc += temp;
        }
        minw = INF;
        DFS(0, 0, 0);
        printf("%d", minw);
    }
}
