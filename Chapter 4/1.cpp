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
#define MAX 10005
#define INF 1000000000
using namespace std;
typedef long long int LL;
int cnt;
double x[3], a[4];
double cal(double x, int n)
{
    double ans = 0;
    for (int i = n; i >= 0; i--)
    {
        ans = ans * x + a[i];
    }
    return ans;
}
void func(double low, double high)
{
    cnt = 0;
    for (int i = low; i <= high; ++i)
    {
        double x1 = i, x2 = i + 1;
        double f1 = cal(x1, 3), f2 = cal(x2, 3);
        if (f1 * f2 == 0)
        {
            if (f1 == 0)
                x[cnt++] = x1;
        }
        else if (f1 * f2 < 0)
        {
            while (fabs(x1 - x2) >= 1e-3) //精确到0.001
            {
                double x0 = (x1 + x2) / 2, f0 = cal(x0, 3);
                if (f1 * f0 <= 0)
                    x2 = x0;
                else
                    x1 = x0;
            }
            x[cnt++] = x1;
        }
        if (cnt == 3)
            break;
    }
}

int main(int agrc, char *agrv[])
{
    //scanf("%lf %lf %lf %lf", &a[3], &a[2], &a[1], &a[0]);
    while (~scanf("%lf %lf %lf %lf", &a[3], &a[2], &a[1], &a[0])) //实数
    {
        func(-100, 100);
        for (int i = 0; i < cnt; i++) //解个数0~3
        {
            if (i == cnt - 1)
                printf("%.2lf", x[i]);
            else
                printf("%.2lf ", x[i]);
        }
        //printf("%.2lf %.2lf %.2lf", x[0], x[1], x[2]);
    }
}