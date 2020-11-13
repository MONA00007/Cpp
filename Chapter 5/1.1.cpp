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
int n, maxn, laste, ans, maxst;
struct node
{
    int st, ed;
} act[MAX];
int x[MAX];
void DFS(int index)
{
    if (index == n)
    {
        maxn = max(maxn, ans);
        return;
    }
    for (int i = index; i < n; i++)
    {

        int laste1 = laste, ans1 = ans;
        if (laste <= act[x[i]].st && laste <= maxst)
        {
            ans += act[x[i]].ed - act[x[i]].st;
            laste = act[x[i]].ed;
        }
        swap(x[index], x[i]);
        DFS(index + 1);
        swap(x[index], x[i]);
        laste = laste1, ans = ans1;
    }
}
int main(int agrc, char *agrv[])
{
    while (~scanf("%d", &n))
    {
        maxst = 0;
        for (int i = 0; i < n; i++)
        {
            scanf("%d %d", &act[i].st, &act[i].ed);
            x[i] = i;
            maxst = max(maxst, act[i].st);
        }
        maxn = 0, laste = 0, ans = 0;
        DFS(0);
        printf("%d", maxn);
    }
}
