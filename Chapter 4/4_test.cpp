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
#define maxn 25
//#define INF 1000000000
using namespace std;
//typedef long long int LL;
int g[maxn][maxn];
int xx[4] = {1, -1, 0, 0}, yy[4] = {0, 0, 1, -1};
bool vis[maxn][maxn][maxn][maxn];
struct node
{
    int px, py, bx, by, step;
};

int BFS(node st)
{
    node now, next, temp;
    vis[st.px][st.py][st.bx][st.by] = true;
    queue<node> q;
    q.push(st);
    while (!q.empty())
    {
        now = q.front(), q.pop();
        if (g[now.bx][now.by] == 2) //到达目的地返回步数
            return now.step;
        for (int i = 0; i < 4; i++)
        {
            next = now, next.step++;
            next.px += xx[i], next.py += yy[i];
            bool flag = false;
            if (g[next.px][next.py]) //人可以走到此处
            {

                if (next.bx == next.px && next.by == next.py) //人走到箱子上
                {
                    temp = next, temp.bx += xx[i], temp.by += yy[i];
                    if (g[temp.bx][temp.by]) //箱子是否可以推动
                        next = temp, flag = true;
                }
                else //非箱子的可行位置
                    flag = true;
            }
            if (flag && !vis[next.px][next.py][next.bx][next.by])
            {
                vis[next.px][next.py][next.bx][next.by] = true;
                q.push(next);
            }
        }
    }
    return -1;
}

int main(int agrc, char *agrv[])
{
    int n, m;
    while (~scanf("%d %d", &n, &m))
    {
        memset(g, 0, sizeof(g));
        memset(vis, false, sizeof(vis));
        char str[maxn];
        node st;
        st.step = 0;
        for (int i = 1; i <= n; i++)
        {
            scanf("%s", str);
            for (int j = 1; j <= m; j++)
            {
                if (str[j - 1] == 'o') //空地
                    g[i][j] = 1;
                else if (str[j - 1] == 'X') //人位置
                    st.px = i, st.py = j, g[i][j] = 1;
                else if (str[j - 1] == '*') //箱子位置
                    st.bx = i, st.by = j, g[i][j] = 1;
                else if (str[j - 1] == '@') //目的地
                    g[i][j] = 2;
            }
        }
        printf("%d", BFS(st));
    }
}