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
#define MAXN 31
#define INF 0x3f3f3f3f
using namespace std;
//typedef long long int LL;
int n, m, cost, bestw;
struct node
{
    int w, c, num, rc, rw;
    bool table[MAXN];
};
struct node1
{
    int w, c, num;
} a[MAXN][MAXN];
int mc[MAXN], mw[MAXN], rw, rc;
bool operator<(node a, node b)
{
    if (a.num != b.num)
        return a.num < b.num;
    if (a.w != b.w)
        return a.w > b.w;
    return a.c > b.c;
}
bool cmp(node1 a, node1 b)
{
    if (a.w != b.w)
        return a.w < b.w;
    return a.c < b.c;
}
void BFS()
{
    priority_queue<node> q;
    node temp, next;
    temp.w = 0, temp.c = 0, temp.num = 0;
    memset(temp.table, 0, sizeof(temp.table));
    q.push(temp);
    while (!q.empty())
    {
        temp = q.top(), q.pop();
        if (temp.num == n)
            bestw = min(temp.w, bestw);
        else
            for (int i = 0; i < m; i++)
                if (temp.c + a[temp.num][i].c <= cost &&
                    temp.w + a[temp.num][i].w < bestw &&
                    !temp.table[a[temp.num][i].num] &&
                    temp.rc + temp.c <= cost &&
                    temp.rw + temp.w <= bestw)
                {
                    next = temp;
                    next.w += a[temp.num][i].w;
                    next.c += a[temp.num][i].c;
                    next.table[a[temp.num][i].num] = true;
                    next.rc -= mc[temp.num];
                    next.rw -= mw[temp.num];
                    next.num++;
                    q.push(next);
                }
    }
}
int main(int agrc, char *agrv[])
{
    scanf("%d %d %d", &n, &m, &cost);
    {
        for (int i = 0; i < n; i++)
        {
            int temp = INF;
            for (int j = 0; j < m; j++)
            {
                scanf("%d", &a[i][j].w);
                a[i][j].num = j;
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
        for (int i = 0; i < n; i++)
            sort(&a[i][0], &a[i][m], cmp);
        bestw = INF;
        BFS();
        printf("%d", bestw);
    }
}
