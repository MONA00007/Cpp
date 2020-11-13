#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

#define MAX 55
int n, maxst;
int ans, temp, counter;

struct classroom
{
    int start;
    int end;
} a[MAX];

bool cmp(classroom a, classroom b)
{
    return a.start < b.start;
}

void dfs(int i, int rws)
{
    counter = 0;
    for (int j = i + 1; j <= n; j++)
    {
        int t = (a[j].end - a[j].start);
        rws -= t;
        if (a[i].end > maxst || rws + t + temp <= ans)
            break;
        if (a[j].start >= a[i].end)
        {
            temp += t;
            dfs(j, rws);
            temp -= t;
            counter++;
        }
    }
    if (!counter)
        ans = max(ans, temp);
}

int main()
{
    cin >> n;
    a[0].end = 0;
    maxst = 0;
    int rws = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].start >> a[i].end;
        maxst = max(maxst, a[i].start);
        rws += a[i].end - a[i].start;
    }
    sort(a + 1, a + n + 1, cmp);
    dfs(0, rws);
    cout << ans;
    return 0;
}
