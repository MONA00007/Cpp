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
int n, m, cost, bestw, rc;
int w[MAXN][MAXN], c[MAXN][MAXN], mc[MAXN], mr[MAXN];
struct node
{
    int w, c, num, rc;
    bool table[MAXN];
};
bool operator<(node a, node b)
{
    if (a.w != b.w)
        return a.w > b.w;
    return a.num < b.num;
}
void BFS()
{
    priority_queue<node> q;
    node temp, next;
    temp.w = 0, temp.c = 0, temp.num = 0, temp.rc = rc;
    memset(temp.table, false, sizeof(temp.table));
    q.push(temp);
    while (!q.empty())
    {
        temp = q.top(), q.pop();
        if (temp.num == n)
            bestw = min(temp.w, bestw);
        else
            for (int i = 0; i < m; i++)
            {
                if (temp.c + c[temp.num][i] <= cost &&
                    temp.w + w[temp.num][i] < bestw &&
                    !temp.table[i] && temp.rc + temp.c <= cost)
                {
                    next = temp;
                    next.w += w[temp.num][i];
                    next.c += c[temp.num][i];
                    next.rc -= mc[temp.num];
                    next.num++;
                    next.table[i] = true;
                    q.push(next);
                }
            }
    }
}
int main(int agrc, char *agrv[])
{
    while (~scanf("%d %d %d", &n, &m, &cost))
    {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                scanf("%d", &w[i][j]);
        for (int i = 0; i < n; i++)
        {
            int temp = INF;
            for (int j = 0; j < m; j++)
            {
                scanf("%d", &c[i][j]);
                temp = min(temp, c[i][j]);
            }
            mc[i] = temp;
            rc += temp;
        }
        bestw = INF;
        BFS();
        printf("%d", bestw);
    }
}
