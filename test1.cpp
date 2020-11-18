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
using namespace std;
#define MAX 31
#define INF 1000000000

int w[MAX][MAX], c[MAX][MAX], f[MAX][MAX];
int cw, cc, bestw, cost, n, m;

void func(int t)
{
    if (t > n)
    {
        bestw = min(bestw, cw);
        return;
    }
    for (int j = 1; j <= m; j++)
    {
        if (cc + c[t][j] <= cost && cw + w[t][j] < bestw && f[t][j] == 0)
        {
            cc += c[t][j];
            cw += w[t][j];
            func(t + 1);
            cc -= c[t][j];
            cw -= w[t][j];
        }
    }
}

int main()

{
    cin >> n >> m >> cost;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> w[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> c[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            for (int k = 1; k <= m; k++)
                if (c[i][j] <= c[i][k] && w[i][j] <= w[i][k] && f[i][j] == 0 && j != k)
                    f[i][k] = 1;
    bestw = INF;
    func(1);
    cout << bestw;
}