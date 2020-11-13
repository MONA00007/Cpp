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
int n, m, cnt;
int yy[4] = {-2, -1, 1, 2}, xx[4] = {1, 2, 2, 1};

void DFS(int x, int y)
{
    if (x == n && y == m)
    {
        cnt++;
        return;
    }
    if (x == n)
        return;
    for (int i = 0; i < 4; ++i)
    {
        int x1 = x + xx[i], y1 = y + yy[i];
        if (x1 <= n && y1 >= 1 && y1 <= m)
            DFS(x1, y1);
    }
}
int main(int agrc, char *agrv[])
{
    while (~scanf("%d %d", &n, &m) && (n + m))
    {
        cnt = 0;
        DFS(1, 1);
        printf("%d", cnt);
    }
}
