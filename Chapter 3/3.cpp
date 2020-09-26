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
#define MAX 100001
//#define INF 1000000000
using namespace std;
//typedef long long int LL;
int a[MAX];
int find(int n, int x)
{
    int low = 0, mid, high = x - 1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (a[mid] == x)
            return x;
        else if (a[mid] > x)
            high = mid - 1;
        else
            low = mid + 1;
    }
    //high m low   m high low    high low m    NULL
}
int main(int agrc, char *agrv[])
{
    int n, m, temp;
    while (~scanf("%d", &n))
    {
        for (int i = 0; i < n; ++i)
        {
            scanf("%d", &a[i]);
        }
        scanf("%d", &m);
        for (int i = 0; i < m; i++)
        {
            scanf("%d", &temp);
            printf("%d\n", find(n, temp));
        }
    }
}