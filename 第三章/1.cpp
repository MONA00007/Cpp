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
#define MAX 51
//#define INF 1000000000
using namespace std;
//typedef long long int LL;
int a[MAX];

int find(int n, int c) //先排序，再进行二分查找
{
    sort(a, a + n);
    int t = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int low = i + 1, high = n - 1, mid;
        bool flag = false;
        while (low <= high)
        {
            if (flag)
                flag = false;
            else
                mid = (low + high) / 2;
            if (a[mid] - a[i] == c)
            {
                flag = true;
                for (int j = mid; j < n; ++j)
                {
                    if (a[j] - a[i] == c)
                        t++;
                    else
                        break;
                }
            }
            else if (a[mid] - a[c] > c)
                high = mid - 1;
            else
                low = mid + 1;
        }
    }
    return t;
}

int main(int agrc, char *agrv[])
{
    int n, c;
    while (~scanf("%d %d", &n, &c))
    {
        for (int i = 0; i < n; ++i)
        {
            scanf("%d", &a[i]);
        }
        printf("%d\n", find(n, c));
    }
}