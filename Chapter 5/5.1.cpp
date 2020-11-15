#include <iostream>
using std::cin;
using std::cout;

int dp[100][100];
int main()
{
    int n, m;
    cin >> n >> m;
    n--, m--;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == j && j == 0)
                dp[i][j] = 1; //循环内初始化边界
            else if (i == 0 && j != 0)
                dp[i][j] = 0;
            else
            {
                if (i > 1)
                {
                    if (j > 0)
                        dp[i][j] += dp[i - 2][j - 1];
                    if (j != m)
                        dp[i][j] += dp[i - 2][j + 1];
                }
                if (j > 1)
                    dp[i][j] += dp[i - 1][j - 2];
                if (j < m - 1)
                    dp[i][j] += dp[i - 1][j + 2];
            }
        }
    }
    cout << dp[n][m];

    return 0;
}