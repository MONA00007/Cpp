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
#define MAXN 8001
#define INF 0x3f3f3f3f
using namespace std;
typedef long long int LL;
int n, m;
bool g[MAXN][MAXN];
int dis[MAXN];
struct node
{
    int no, len;
};
void BFS(int x)
{
    memset(dis, INF, sizeof(dis));
    dis[x] = 0;
    queue<node> q;
    node temp, next;
    temp.no = x, temp.len = 0;
    q.push(temp);
    while (!q.empty())
    {
        temp = q.front(), q.pop();
        for (int i = 0; i < n; i++)
        {
            if (g[temp.no][i] && temp.len + 1 < dis[i])
            {
                dis[i] = temp.len + 1;
                next.no = i, next.len = dis[i];
                q.push(next);
            }
        }
    }
}
int main(int agrc, char *agrv[])
{
    int a, b, k;
    while (~scanf("%d %d", &n, &m))
    {
        for (int i = 0; i < m; i++)
        {
            scanf("%d %d", &a, &b);
            g[a][b] = true, g[b][a] = true;
        }
        scanf("%d", &k);
        for (int i = 0; i < k; i++)
        {
            scanf("%d %d", &a, &b);
            if (a == b)
                printf("0\n");
            else
            {
                BFS(a);
                if (dis[b] != INF)
                    printf("%d\n", dis[b] - 1);
                else
                    printf("-1\n");
            }
        }
    }
}
