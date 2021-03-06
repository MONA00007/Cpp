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
void ShengJin(double a, double b, double c, double d, vector<double> &X123)
{
    /************************************************************************/
    /* 盛金公式求解三次方程的解 
	   德尔塔f=B^2-4AC
           这里只要了实根，虚根需要自己再整理下拿出来
	*/
    /************************************************************************/
    double A = b * b - 3 * a * c;
    double B = b * c - 9 * a * d;
    double C = c * c - 3 * b * d;
    double f = B * B - 4 * A * C;
    double i_value;
    double Y1, Y2;
    if (fabs(A) < 1e-6 && fabs(B) < 1e-6) //公式1
    {
        X123.push_back(-b / (3 * a));
        X123.push_back(-b / (3 * a));
        X123.push_back(-b / (3 * a));
    }
    else if (fabs(f) < 1e-6) //公式3
    {
        double K = B / A;
        X123.push_back(-b / a + K);
        X123.push_back(-K / 2);
        X123.push_back(-K / 2);
    }
    else if (f > 1e-6) //公式2
    {
        Y1 = A * b + 3 * a * (-B + sqrt(f)) / 2;
        Y2 = A * b + 3 * a * (-B - sqrt(f)) / 2;
        double Y1_value = (Y1 / fabs(Y1)) * pow((double)fabs(Y1), 1.0 / 3);
        double Y2_value = (Y2 / fabs(Y2)) * pow((double)fabs(Y2), 1.0 / 3);
        X123.push_back((-b - Y1_value - Y2_value) / (3 * a)); //虚根我不要
        //虚根还是看看吧，如果虚根的i小于0.1，则判定为方程的一根吧。。。
        i_value = sqrt(3.0) / 2 * (Y1_value - Y2_value) / (3 * a);
        if (fabs(i_value) < 1e-1)
        {
            X123.push_back((-b + 0.5 * (Y1_value + Y2_value)) / (3 * a));
        }
    }
    else if (f < -1e-6) //公式4
    {
        double T = (2 * A * b - 3 * a * B) / (2 * A * sqrt(A));
        double S = acos(T);
        X123.push_back((-b - 2 * sqrt(A) * cos(S / 3)) / (3 * a));
        X123.push_back((-b + sqrt(A) * (cos(S / 3) + sqrt(3.0) * sin(S / 3))) / (3 * a));
        X123.push_back((-b + sqrt(A) * (cos(S / 3) - sqrt(3.0) * sin(S / 3))) / (3 * a));
    }
}
int main(int agrc, char *agrv[])
{
    int a[4];
    while (~scanf("%d %d %d %d", &a[3], &a[2], &a[1], &a[0]))
    {
        vector<double> X123;
        ShengJin(a[3], a[2], a[1], a[0], X123);
        sort(X123.begin(), X123.end());
        printf("%.2lf %.2lf %.2lf", X123[0], X123[1], X123[2]);
    }
}