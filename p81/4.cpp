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
#define MAX 101
//#define INF 1000000000
using namespace std;
//typedef long long int LL;

int f(int n)
//根据n=1时，方法数为1，n=2时，方法数为2......推导出来公式，f(n)=2**(n-1)
{
    if (n == 1)
        return 1;
    return f(n - 1) * 2;
}

int main(int agrc, char *agrv[])
{
    int n;
    while (~scanf("%d", &n))
    {
        printf("%d\n", f(n));
    }
}