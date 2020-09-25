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

int Partiton(int left, int right)
{
    int temp = a[left];
    while (left < right)
    {
        while (left < right && temp < a[right])
            right--;
        a[left] = a[right];
        while (left < right && temp >= a[left])
            left++;
        a[right] = a[left];
    }
    a[left] = temp;
    return left;
}

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

void QuickSort(int left, int right)
{
    if (left < right)
    {
        int temp = Partiton(left, right);
        QuickSort(left, temp - 1);
        QuickSort(temp + 1, right);
    }
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
        display(n);
        QuickSort(0, n - 1);
        display(n);
    }
}