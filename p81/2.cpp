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
#define MAX 100001
//#define INF 1000000000
using namespace std;
//typedef long long int LL;
int f(int n) //十进制各位相加
{
    int temp = n / 10;
    if (temp)
        return f(temp) + n % 10;
    else
        return n;
}

int g(int n) //二进制各位相加
{
    int temp = n / 2;
    if (temp)
        return g(temp) + n % 2;
    else
        return n;
}

int main(int agrc, char *agrv[])
{
    int n;
    int num[MAX];
    memset(num, -1, sizeof(num));
    num[0] = 0;
    for (int i = 1; i <= MAX - 1; i++) //打表法
    {
        int f1 = f(i);
        int g1 = g(i);
        if (g1 == f1)
            num[i] = num[i - 1] + 1;
        else
            num[i] = num[i - 1];
    }
    while (~scanf("%d", &n))
    {
        printf("%d\n", num[n]); //直接查表输出
    }
}