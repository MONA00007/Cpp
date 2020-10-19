#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <queue>
#define maxn 25
#define INF 1000000000
using namespace std;
typedef long long int LL;
int xx[4] = {-1, 0, 1, 0}, yy[4] = {0, 1, 0, -1};
int g[maxn][maxn];
int n, m, p_x, p_y, b_x, b_y;
bool vis[maxn][maxn], having[maxn][maxn][maxn][maxn];
struct node
{
    int step, px, py, bx, by;
};

void dfs(int x, int y)
{
    for (int i = 0; i < 4; ++i)
    {
        int ax = x + xx[i], ay = y + yy[i];
        if (g[ax][ay] && !vis[ax][ay])
        {
            vis[ax][ay] = true;
            dfs(ax, ay);
        }
    }
}

int bfs()
{
    node cur, next;
    cur.bx = b_x, cur.by = b_y;
    cur.px = p_x, cur.py = p_y, cur.step = 0;
    queue<node> q;
    q.push(cur);
    while (!q.empty())
    {
        cur = q.front(), q.pop();
        memset(vis, false, sizeof(vis));
        vis[cur.bx][cur.by] = true;
        vis[cur.px][cur.py] = true;
        dfs(cur.px, cur.py);
        for (int i = 0; i < 4; i++)
        {
            int x1 = cur.bx + xx[i], y1 = cur.by + yy[i];
            if (g[x1][y1])
            {
                int x2 = cur.bx - xx[i], y2 = cur.by - yy[i];
                if (vis[x2][y2])
                {
                    if (having[cur.bx][cur.by][x2][y2])
                        continue;
                    having[cur.bx][cur.by][x2][y2] = true;
                    next.bx = x1, next.by = y1;
                    next.px = x2, next.py = y2;
                    next.step = cur.step + 1;
                    if (g[x1][y1] == 3)
                        return next.step;
                    q.push(next);
                }
            }
        }
    }
    return -1;
}

int main(int agrc, char *agrv[])
{
    while (cin >> n >> m)
    {
        memset(g, 0, sizeof(g));
        char str[maxn];
        for (int i = 1; i <= n; ++i)
        {
            scanf("%s", str);
            for (int j = 1; j <= m; ++j)
            {
                if (str[j - 1] == 'o')
                    g[i][j] = 1;
                else if (str[j - 1] == 'X')
                    p_x = i, p_y = j, g[i][j] = 1;
                else if (str[j - 1] == '*')
                    g[i][j] = 1, b_x = i, b_y = j;
                else if (str[j - 1] == '@')
                    g[i][j] = 3;
            }
        }
        memset(having, false, sizeof(having));
        printf("%d", bfs());
    }
}