#include <bits/stdc++.h>
using namespace std;

struct stick
{
    int x, y;
} st[5005], st0[5005];

int cmp(stick a, stick b)
{
    if (a.x != b.x)
        return a.x < b.x;
    return a.y < b.y;
}
int main()
{
    int n, i = 0, j, m = 2;
    cin >> n;
    for (; i < n; i++)
        cin >> st[i].x >> st[i].y;
    sort(st, st + n, cmp);
    for (i = 0; i < n; i++)
    {
        for (j = 2; j <= m; j++)
            if (st[i].x >= st0[j].x && st[i].y >= st0[j].y)
            {
                st0[j] = st[i];
                break;
            }
        if (j > m)
            st0[++m] = st[i];
    }
    cout << m;
}