#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;
double a, b, c, d;
double ans[5];
int k = 0;
double f(double x)
{
    return a * x * x * x + b * x * x + c * x + d;
}
int main()
{
    cin >> a >> b >> c >> d;
    double i;
    int cnt = 0; //找到的实根个数
    for (i = -100; i <= 100; i++)
    {
        double left = i, right = i + 1;
        if (f(left) * f(right) == 0) //left和right肯定有一个是根
        {
            if (f(left) == 0)
                ans[k++] = left;
        }
        else if (f(left) * f(right) < 0) //某一个根肯定在left和right之间
        {
            while ((fabs(right - left)) >= 0.00001)
            {
                double mid = (left + right) / 2.0;
                if (f(left) * f(mid) <= 0)
                    right = mid;
                else
                    left = mid;
            }
            //printf("%.2lf\n",left);
            ans[k++] = left;
        }
        else //根不在 left和right之间
            continue;
    }
    for (int j = 0; j < k; j++)
    {
        if (j == k - 1)
            printf("%.2lf", ans[j]);
        else
            printf("%.2lf ", ans[j]);
    }
    return 0;
}