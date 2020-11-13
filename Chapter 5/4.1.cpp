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
#define MAX 51
//#define INF 1000000000
using namespace std;
//typedef long long int LL;
int n, len;
char str[MAX];
bool flag;

bool cmp(int a, int b)
{
    return a > b;
}

int cal(int v, int w, int x, int y, int z)
{
    v = str[v] - '@', w = str[w] - '@', x = str[x] - '@', y = str[y] - '@', z = str[z] - '@';
    int t = v - w * w + x * x * x - y * y * y * y + z * z * z * z * z;
    return t;
}

void DFS(int v, int w, int x, int y, int z)
{
    int t = cal(v, w, x, y, z);
    if (t == n)
    {
        flag = true;
        printf("%c%c%c%c%c\n", str[v], str[w], str[x], str[y], str[z]);
        return;
    }
    if (flag)
        return;
    if (z + 1 < len)
        DFS(v, w, x, y, z + 1);
    if (y + 1 < len)
        DFS(v, w, x, y + 1, z);
    if (x + 1 < len)
        DFS(v, w, x + 1, y, z);
    if (w + 1 < len)
        DFS(v, w + 1, x, y, z);
    if (v + 1 < len)
        DFS(v + 1, w, x, y, z);
}

int main(int agrc, char *agrv[])
{
    while (~scanf("%d", &n) && n)
    {
        scanf("%s", str);
        len = strlen(str);
        sort(str, str + len, cmp);
        flag = false;
        DFS(0, 0, 0, 0, 0);
        if (!flag)
            printf("no solution\n");
    }
}
