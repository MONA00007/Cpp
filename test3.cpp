#include <iostream>
#include <stdio.h>
using namespace std;
int w[31][31];
int c[31][31];
int f[31][31];
int cw = 0, cc = 0, bestw = 10000;
int cost;
int n;
int m;
void Backtrack(int t)
{

    int j;
    if (t > n)
    {
        if (bestw > cw)
            bestw = cw;
    }
    else
    {
        for (j = 1; j <= m; j++)
        {
            if (cc + c[t][j] <= cost && cw + w[t][j] < bestw && f[t][j] == 0)
            {
                cc += c[t][j];
                cw += w[t][j];
                Backtrack(t + 1);
                cc -= c[t][j];
                cw -= w[t][j];
            }
        }
    }
}

int main()

{
    int i, j, k;
    cin >> n;
    cin >> m;
    cin >> cost;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= m; j++)
            cin >> w[i][j];
    for (i = 1; i <= n; i++)
        for (j = 1; j <= m; j++)
            cin >> c[i][j];
    for (i = 1; i <= n; i++)
        for (j = 1; j <= m; j++)
            for (k = 1; k <= m; k++)
            {
                if (c[i][j] <= c[i][k] && w[i][j] <= w[i][k] && f[i][j] == 0 && j != k)
                    f[i][k] = 1;
            }
    Backtrack(1);
    cout << bestw;
    return 0;
}