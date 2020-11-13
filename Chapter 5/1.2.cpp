#include <iostream>
using namespace std;
int a[10005], b[10005], c[10005];
int cost, ans, n, l;
void dfs(int t)
{
    l = 0;
    for (int i = 1; i <= n; i++)
    {

        if (a[i] >= b[t])
        {

            cost = cost + c[i];
            dfs(i);
            cost = cost - c[i];
            l++;
        }
    }
    if (l == 0)
        if (cost > ans)
            ans = cost;
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i] >> b[i];
        c[i] = b[i] - a[i];
    }
    dfs(0);
    cout << ans;
    return 0;
}