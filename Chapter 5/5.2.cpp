#include <iostream>
#include <cstdio>

using namespace std;
const int mx = 51;
int dp[mx][mx];
int dx[4] = {1, 2, 2, 1};
int dy[4] = {-2, -1, 1, 2};
int n, m;

int main()
{
    cin >> n >> m;
    dp[1][1] = 1;
    for (int i = 1; i <= m; i++) //横坐标
    {
        for (int j = 1; j <= n; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                int tx = i + dx[k];
                int ty = j + dy[k];
                if (1 <= tx && tx <= m && 1 <= ty && ty <= n)
                    dp[i][j] += dp[tx][ty];
            }
        }
    }
    cout << dp[m][n];
    getchar();
    getchar();
    return 0;
}

#include <stdio.h>

int data[200][200]; //从第一个点0,0开始，0,0 即有一种方法

int main()
{
    int i, j;
    int n, m;
    scanf("%d%d", &n, &m);
    data[1][1] = 1;
    for (j = 1; j <= m; j++) //第0列没有，所以从第1行开始
    {
        for (i = 1; i <= n; i++)
        { /*   往前找四个方向，四个方向的所有值加起来即为本点的值   */
            int da1 = (i - 2 >= 1 && j - 1 >= 1) ? data[i - 2][j - 1] : 0;
            int da2 = (i - 1 >= 1 && j - 2 >= 1) ? data[i - 1][j - 2] : 0;
            int da3 = (i + 2 <= n && j - 1 >= 1) ? data[i + 2][j - 1] : 0;
            int da4 = (i + 1 <= n && j - 2 >= 1) ? data[i + 1][j - 2] : 0;
            data[i][j] = da1 + da2 + da3 + da4;
        }
    }
    printf("%d", data[n][m]);
    return 0; //开心的结束O(∩_∩)O
}