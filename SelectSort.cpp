#include <iostream>
#include <algorithm>
#include <functional>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>

#define MAX 101
//#define INF 1000000000

using namespace std;
//typedef long long int LL;

void disp(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d", a[i]);
        if (i != n - 1)
            printf(" ");
    }
    printf("\n");
}
void SelectSort(int a[], int i, int n)
{
    if (i == n - 1)
        return;
    else
    {
        int k = i;
        for (int j = i + 1; j < n; ++j)
        {
            if (a[k] > a[j])
                k = j;
        }
        if (k != i)
            swap(a[i], a[k]);
        SelectSort(a, i + 1, n);
    }
}
int main()
{
    int n;
    while (~scanf("%d", &n))
    {
        int a[MAX];
        for (int i = 0; i < n; ++i)
        {
            scanf("%d", &a[i]);
        }
        printf("ÅÅÐòÇ°£º\n");
        disp(a, n);
        SelectSort(a, 0, n);
        printf("ÅÅÐòºó£º\n");
        disp(a, n);
    }
}