#include <bits/stdc++.h>
using namespace std;
#define M 1001
#define z for(a = 0; a < n; a++)for(b = 0; b < n; b++)
int w[M * M], n, m, k[M], a, b, f;
int F(int x)
{
    int l = 0, r = n * n, i;
    while (r - l)
    {
        i = (l + r) / 2;
        if (w[i] == x)
            return 1;
        if (w[i] < x)
            l = i + 1;
        else
            r = i;
    }
    return 0;
}
main()
{
    cin >> n >> m;
    for (; a < n; a++)
        cin >> k[a];
    z w[a * n + b] = k[a] + k[b];
    sort(w, w + n * n);
    z if (F(m - k[a] - k[b]))
        f = 1;
    if (f)
        puts("Yes");
    else
        puts("No");
}