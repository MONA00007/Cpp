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

void f(int i, int j, int n)
{
    
}

int main(int agrc, char *agrv[])
{
    int n;
    while (~scanf("%d", &n) && n)
    {
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