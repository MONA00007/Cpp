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
#define MAX 7
//#define INF 1000000000
using namespace std;
//typedef long long int LL;
int a[MAX] = {0};
int f(int n)
//根据n=1时，方法数为1，n=2时，方法数为2......推导出来公式，f(n)=2**(n-1)
//计算过程中打表
{
    if (a[n])
        return a[n]; //已存在直接返回
    else
        return a[n] = f(n - 1) * 2; //不存在计算并赋给表
}

int main(int agrc, char *agrv[])
{
    int n;
    a[1] = 1;
    f(6);
    while (~scanf("%d", &n))
    {
        printf("%d\n", a[n]); //打表查询
    }
}