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

void f(int i, int begin, int circle, int n) //ÿ�εݹ���һȦ��������Ȧ��ʼ
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

int main(int agrc, char *agrv[])
{
    int n;
    while (~scanf("%d", &n) && n)
    {
        f(1, 1, (n + 1) / 2, n);
        int t = n / 2; //����nΪ����ʱ�����
        if (n % 2)
            a[t + 1][t + 1] = n * n;
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                printf("%d", a[i][j]);
                if (j != n)
                    printf(" ");
            }
            printf("\n");
        }
    }
}