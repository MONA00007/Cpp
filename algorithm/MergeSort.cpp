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
//typedef long long int LL;
int a[MAX];

void Merge(int L_left, int L_right, int R_left, int R_right)
{
    int temp[MAX];
    int index = 0;
    int i = L_left, j = R_left;
    while (i <= L_right && j <= R_right)
    {
        if (a[i] <= a[j])
            temp[index++] = a[i++];
        else
            temp[index++] = a[j++];
    }
    while (i <= L_right)
        temp[index++] = a[i++];
    while (j <= R_right)
        temp[index++] = a[j++];
    for (i = 0; i < index; ++i)
    {
        a[L_left++] = temp[i];
    }
}

void MergeSort(int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        MergeSort(left, mid);
        MergeSort(mid + 1, right);
        Merge(left, mid, mid + 1, right);
    }
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
        MergeSort(0, n - 1);
        display(n);
    }
}