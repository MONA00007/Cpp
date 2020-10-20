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
#define MAX 10005
//#define INF 1000000000
using namespace std;
//typedef long long int LL;

struct node
{
    int to, val, next;
} edge[MAX];

int n, m, cnt, ans, Min, root;
int head[MAX], depth[MAX], size[MAX], ms[MAX];
bool vis[MAX];

void add(int a, int b, int c)
{
    edge[cnt].to = b, edge[cnt].val = c, edge[cnt].next = head[a];
    head[a] = cnt++;
}

void init()
{
    int a, b, c;
    cnt = 0, ans = 0;
    memset(head, -1, sizeof(head));
    memset(vis, false, sizeof(vis));
    for (int i = 1; i < n; ++i)
    {
        scanf("%d %d %d", &a, &b, &c);
        add(a, b, c);
        add(b, a, c);
    }
}

void getSize(int u, int fa) //以u为根的子树大小
{
    size[u] = 1;
    ms[u] = 0;
    for (int i = head[u]; i != -1; i = edge[i].next)
    {
        int v = edge[i].to;
        if (v == fa || vis[v])
            continue;
        getSize(v, u);
        size[u] += size[v];
        if (size[v] > ms[u])
            ms[u] = size[v];
    }
}

void getRoot(int r, int u, int fa) //求重心，去掉u之后Min值最小的为重心
{
    ms[u] = max(ms[u], size[r] - size[u]);
    if (Min > ms[u])
    {
        Min = ms[u];
        root = u;
    }
    for (int i = head[u]; i != -1; i = edge[i].next)
    {
        int v = edge[i].to;
        if (v == fa || vis[v])
            continue;
        getRoot(r, v, u);
    }
}

void getDepth(int u, int deep, int fa)
{
    depth[cnt++] = deep;
    for (int i = head[u]; i != -1; i = edge[i].next)
    {
        int v = edge[i].to;
        if (v == fa || vis[v])
            continue;
        getDepth(v, deep + edge[i].val, u);
    }
}

int cal(int u, int d)
{
    cnt = 0;
    getDepth(u, d, -1);
    sort(depth, depth + cnt);
    int left = 0, right = cnt - 1, res = 0;
    while (left < right)
    {
        while (left < right && depth[left] + depth[right] > m)
            --right;
        res += right - left;
        ++left;
    }
    return res;
}

void dfs(int u)
{
    Min = n;
    getSize(u, -1);
    getRoot(u, u, -1);
    ans += cal(root, 0);
    vis[root] = true;
    for (int i = head[root]; i != -1; i = edge[i].next)
    {
        int v = edge[i].to;
        if (vis[v])
            continue;
        ans -= cal(v, edge[i].val);
        dfs(v);
    }
}

int main(int agrc, char *agrv[])
{

    while (~scanf("%d %d", &n, &m) && (n + m))
    {
        init();
        dfs(1);
        printf("%d\n", ans);
    }
    //l
}