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
struct node
{
    int key, value;
};
char a[MAX * 2][MAX], c[MAX * 2][MAX];
int num;

bool cmp(node a, node b)
{
    if (a.value != b.value)
        return a.value < b.value;
    else
        return a.key < b.key;
}

void Merge(int L_left, int L_right, int R_left, int R_right, int index)
{
    int temp[2 * MAX];
    int k = 0;
    int i = L_left, j = R_left;
    while (i <= L_right && j <= R_right)
    {
        if (c[index][i] <= c[index][j])
            temp[k++] = c[index][i++];
        else
        {
            temp[k++] = c[index][j++];
            num += L_right - i + 1;
        }
    }
    while (i <= L_right)
        temp[k++] = c[index][i++];
    while (j <= R_right)
        temp[k++] = c[index][j++];
    for (int i = 0; i < k; i++)
    {
        c[index][L_left++] = temp[i];
    }
}

void MergeSort(int left, int right, int index)
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        MergeSort(left, mid, index);
        MergeSort(mid + 1, right, index);
        Merge(left, mid, mid + 1, right, index);
    }
}

int main(int agrc, char *agrv[])
{
    int n, m;
    node b[2 * MAX];
    while (~scanf("%d %d", &n, &m))
    {
        for (int i = 0; i < m; i++)
        {
            scanf("%s", a[i]);
            for (int j = 0; j < n; j++)
            {
                c[i][j] = a[i][j];
            }
            num = 0;
            MergeSort(0, n - 1, i);
            b[i].key = i;
            b[i].value = num;
        }
        sort(b, b + m, cmp);
        for (int i = 0; i < m; i++)
        {
            printf("%s\n", a[b[i].key]);
        }
    }
}