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
#define MAXN 1001
#define INF 0x3f3f3f3f
using namespace std;
//typedef long long int LL;
int n;
struct node
{
    int deadline, score;
    bool t;
} a[MAXN];
bool cmp(node a, node b)
{
    return a.score > b.score || a.score == b.score && a.deadline < b.deadline;
}
bool table[MAXN];
int func()
{
    int sum = 0, day = 0;
    sort(a, a + n, cmp);
    for (int i = 0; i < n; i++)
    {
        for (int j = a[i].deadline; j > 0; j--)
        {
            if (!table[j])
            {
                table[j] = true;
                a[i].t = true;
                break;
            }
        }
        if (!a[i].t)
            sum += a[i].score;
    }
    return sum;
}
int main(int agrc, char *agrv[])
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i].score >> a[i].deadline;
    printf("%d", func());
}
