#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>

using namespace std;
const int mx = 41;
int dp[mx][mx];
int dx[4] = {-1, -2, -2, -1};
int dy[4] = {-2, -1, 1, 2};

int n, m;

int main()
{
    while (cin >> n >> m)
    {
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        for (int i = 0; i <= m; i++) //横坐标
            for (int j = 0; j <= n; j++)
            {
                for (int k = 0; k < 4; k++)
                {
                    int tx = i + dx[k];
                    int ty = j + dy[k];
                    if (0 <= tx && tx <= m && 0 <= ty && ty <= n)
                        dp[i][j] += dp[tx][ty];
                }
            }
        cout << dp[m - 1][n - 1];
    }
    return 0;
}