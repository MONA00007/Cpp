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
void DFS(int x, int y)
{
    if (x == m && y == n)
    {
        cnt++;
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        int x1 = x + xx[i], y1 = y + yy[i];
        if (x1 >= 1 && x1 <= m && y1 >= 1 && y1 <= n)
            DFS(x1, y1);
    }
}
int main(int agrc, char *agrv[])
{
    while (cin >> m >> n)
    {
        DFS(1, 1);
        printf("%d", cnt);
    }
}
