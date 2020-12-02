#include <iostream>
#include <algorithm>
#define MAXN 3001
using namespace std;
int n, m, a[MAXN], b[MAXN];
int func()
{
    sort(a, a + n);
    for (int i = 1; i < n; i++)
        b[i - 1] = a[i] - a[i - 1];
    sort(b, b + n - 1, [](int a, int b) { return a > b; });
    int sum = a[n - 1] - a[0] + m;
    for (int i = 0; i < m - 1; i++)
        sum -= b[i];
    return sum;
}
int main(int agrc, char *agrv[])
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    printf("%d", func());
}
