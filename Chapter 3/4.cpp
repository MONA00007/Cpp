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
#define MAX 201
//#define INF 1000000000
using namespace std;
//typedef long long int LL;

//利用两路归并排序的思想，在排序过程中确定逆序对个数

struct node
{
    int key, value;
};
char a[MAX][MAX];
int num;

bool cmp(node a, node b) //逆序对个数不相等，按逆序对升序排序；相等按key升序排序
{
    if (a.value != b.value)
        return a.value < b.value;
    else
        return a.key < b.key;
}

void Merge(int L_left, int L_right, int R_left, int R_right, int index)
//合并操作，合并过程中记录逆序对个数
{
    int temp[2 * MAX];
    int k = 0;
    int i = L_left, j = R_left;
    while (i <= L_right && j <= R_right)
    {
        if (a[index][i] <= a[index][j])
            temp[k++] = a[index][i++];
        else
        {
            temp[k++] = a[index][j++];
            num += L_right - i + 1; //记录逆序对
        }
    }
    while (i <= L_right)
        temp[k++] = a[index][i++];
    while (j <= R_right)
        temp[k++] = a[index][j++];
    for (int i = 0; i < k; i++)
    {
        a[index][L_left++] = temp[i];
    }
}

void MergeSort(int left, int right, int index) //两路归并排序
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
            num = 0;
            MergeSort(0, n - 1, i);
            b[i].key = i;     //记录id
            b[i].value = num; //记录逆序对
        }
        sort(b, b + m, cmp);
        for (int i = 0; i < m; i++)
        {
            printf("%d %d\n", b[i].key, b[i].value);
        }
    }
}