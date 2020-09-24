#include <bits/stdc++.h>
int main()
{
    int n;
    int m[55][55];
    while (~scanf("%d", &n) && n != 0)
    {
        int t = 0;
        int i, j;
        for (i = 0; i < (n + 1) / 2; i++) //螺旋圈数
        {
            for (j = i; j < n - i; j++) //每圈从左到右的一行
            {
                m[i][j] = ++t;
            }
            for (j = i + 1; j < n - i; j++) //每圈从上到下的一列
            {
                m[j][n - i - 1] = ++t;
            }
            for (j = n - i - 2; j >= i; j--) //每圈从右到左的一行
            {
                m[n - i - 1][j] = ++t;
            }
            for (j = n - i - 2; j > i; j--) //每圈从下到上的一列
            {
                m[j][i] = ++t;
            }
        }
        for (int p = 0; p < n; p++)
        {
            for (int q = 0; q < n; q++)
            {
                printf("%d ", m[p][q]);
            }
            printf("\n");
        }
    }
    return 0;
}