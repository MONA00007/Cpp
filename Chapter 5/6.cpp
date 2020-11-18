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
#define MAX 41
//#define INF 1000000000
using namespace std;
//typedef long long int LL;
int n, m, cnt;
int xx[2] = {2, 1}, yy[2] = {1, 2};

void DFS(int x, int y)
{
    if (x == n && y == m)
    {
        cnt++;
        return;
    }
    for (int i = 0; i < 2; i++)
    {
        int x1 = x + xx[i], y1 = y + yy[i];
        if (x1 >= 1 & x1 <= n && y1 <= m)
            DFS(x1, y1);
    }
}
int main(int agrc, char *agrv[])
{

    while (~scanf("%d %d", &n, &m) && (m + n))
    {
        cnt = 0;
        DFS(1, 1);
        printf("%d", cnt);
    }
}
