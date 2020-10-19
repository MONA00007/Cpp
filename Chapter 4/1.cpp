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
int a[4], cnt;
double x[3];
double cal(double x)
{
    double ans = 0;
    for (int i = 3; i >= 0; i--)
    {
        ans = ans * x + a[i];
    }
    return ans;
}
double func(double low, double high)
{
    double mid;
    double f1, f2, f0;
    f2 = cal(high);
    for (; low <= high; low += 0.5)
    {
        f1 = cal(low);
        if (f1 * f2 < 0)
            break;
    }
    if (low >= high)
        return INF;
    do
    {
        mid = (low + high) / 2;
        f0 = cal(mid);
        if (f1 * f0 < 0)
        {
            high = mid;
            f2 = f0;
        }
        else
        {
            low = mid;
            f1 = f0;
        }
    } while (fabs(f0) >= 1e-2);
    return mid;
}
void solve(double low, double high)
{
    if (cnt == 3)
        return;
    double temp = func(low, high);
    if (temp != INF)
    {
        x[cnt++] = temp;
        solve(low, temp - 1);
        solve(temp + 1, high);
    }
}

int main(int agrc, char *agrv[])
{

    while (~scanf("%d %d %d %d", &a[3], &a[2], &a[1], &a[0]))
    {
        cnt = 0;
        solve(-100, 100);
        sort(x, x + cnt);
        printf("%.2lf %.2lf %.2lf", x[0], x[1], x[2]);
    }
}