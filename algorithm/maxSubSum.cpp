#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
//#include <functional>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#define MAX 51
//#define INF 1000000000
using namespace std;
typedef long long int LL;
int a[MAX];

void display(int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d", a[i]);
        if (i != n - 1)
            printf(" ");
    }
    printf("\n");
}

LL maxSubSum(int left, int right)
{
    if (left == right)
    {
        if (a[left] > 0)
            return a[left];
        else
            return 0;
    }
    int mid = (left + right) / 2;
    LL maxLeftSum = maxSubSum(left, mid);
    LL maxRightSum = maxSubSum(mid + 1, right);
    LL maxLeftBorderSum = 0, maxRightBorderSum = 0;
    LL leftBorderSum = 0, rightBorderSum = 0;
    for (int i = mid; i >= left; i--)
    {
        leftBorderSum += a[i];
        if (leftBorderSum > maxLeftBorderSum)
            maxLeftBorderSum = leftBorderSum;
    }
    for (int i = mid + 1; i <= right; i++)
    {
        rightBorderSum += a[i];
        if (rightBorderSum > maxRightBorderSum)
            maxRightBorderSum = rightBorderSum;
    }
    return max(maxLeftBorderSum + maxRightBorderSum, max(maxLeftSum, maxRightSum));
}

int main(int agrc, char *agrv[])
{
    int n;
    while (~scanf("%d", &n))
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
        }
        printf("%lld\n", maxSubSum(0, n - 1));
    }
}