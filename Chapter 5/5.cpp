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
int xx[4] = {-2, -1, 1, 2}, yy[4] = {1, 2, 2, 1};
int num[MAX][MAX];
int DFS(int x, int y)
{

    for (int i = 0; i < 4; i++)
    {
        int x1 = x + xx[i], y1 = y + yy[i];
        if (x1 >= 1 & x1 <= n && y1 <= m)
            num[x1][y1] += DFS(x1, y1);
    }
    return num[x][y];
}
int main(int agrc, char *agrv[])
{

    while (~scanf("%d %d", &n, &m) && (m + n))
    {
        DFS(1, 1);
        printf("%d", num[n][m]);
    }
}
