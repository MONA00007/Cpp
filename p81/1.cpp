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

int a[MAX][MAX] = {0};

void f(int i, int begin, int circle, int n) //每次递归填一圈，从最外圈开始
{
    if (i == circle + 1)
        return;
    int j, k = i;
    for (j = i; j <= n - k; j++)
        a[i][j] = begin++;
    for (; i <= n - k; i++)
        a[i][j] = begin++;
    for (; j > k; j--)
        a[i][j] = begin++;
    for (; i > k; i--)
        a[i][j] = begin++;
    i = k + 1;
    return f(i, begin, circle, n);
}

int g(int n) //计算每个数长度
{

    int temp = n / 10;
    if (temp)
        return 1 + g(temp);
    else
        return 1;
}

int main(int agrc, char *agrv[])
{
    int n;
    while (~scanf("%d", &n) && n)
    {
        f(1, 1, (n + 1) / 2, n);
        int t = n / 2; //处理n为奇数时的情况
        int max = n * n;
        if (n % 2)
            a[t + 1][t + 1] = max;
        int col_t[MAX]; //存储每列最长的数的长度
        for (int i = 1; i <= n / 2; i++)
            col_t[i] = g(a[i + 1][i]);
        for (int i = n; i > n / 2; i--)
            col_t[i] = g(a[i][i]);
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                int a_t = g(a[i][j]);
                for (int k = 0; k < col_t[j] - a_t; k++)
                    printf(" ");
                printf("%d", a[i][j]);
                if (j != n)
                    printf(" ");
            }
            printf("\n");
        }
    }
}