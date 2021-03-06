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
int w[MAXN][MAXN], c[MAXN][MAXN];
bool f[MAXN][MAXN];
struct node
{
    int w, c, num;
    //bool table[MAXN];
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
    temp.w = 0, temp.c = 0, temp.num = 0;
    //memset(temp.table, 0, sizeof(temp.table));
    q.push(temp);
    while (!q.empty())
    {
        temp = q.top(), q.pop();
        if (temp.num == n)
            bestw = min(temp.w, bestw);
        else
            for (int i = 0; i < m; i++)
            {
                if (temp.c + c[temp.num][i] <= cost && temp.w + w[temp.num][i] < bestw && !f[temp.num][i])
                {
                    next.w = temp.w + w[temp.num][i];
                    next.c = temp.c + c[temp.num][i];
                    next.num = temp.num + 1;
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
            for (int j = 0; j < m; j++)
                scanf("%d", &c[i][j]);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                for (int k = 0; k < m; k++)
                    if (c[i][j] <= c[i][k] && w[i][j] <= w[i][k] && f[i][j] == 0 && j != k)
                        f[i][k] = true;
        bestw = INF;
        BFS();
        printf("%d", bestw);
    }
}
