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
int n, maxn, laste, ans;
struct node
{
    int st, ed;
} act[MAX];
int x[MAX];
void DFS(int index)
{
    if (index >= n)
    {
        maxn = max(maxn, ans);
        return;
    }
    for (int i = 0; i < n; i++)
    {
        swap(x[index], x[i]);
        int laste1 = laste, ans1 = ans;
        if (laste <= act[x[i]].st)
        {
            ans += act[x[i]].ed - act[x[i]].st;
            laste = act[x[i]].ed;
        }
        DFS(index + 1);
        swap(x[index], x[i]);
        laste = laste1, ans = ans1;
    }
}
int main(int agrc, char *agrv[])
{
    while (~scanf("%d", &n))
    {
        for (int i = 0; i < n; i++)
            scanf("%d %d", &act[i].st, &act[i].ed), x[i] = i;
        maxn = 0, laste = 0, ans = 0;
        DFS(0);
        printf("%d", maxn);
    }
}
