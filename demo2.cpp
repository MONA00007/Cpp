#include <bits/stdc++.h>

using namespace std;

struct stick
{

    int x;

    int y;
};

int cmp(stick a, stick b)
{

    if (a.x < b.x)

        return 1;

    else if (a.x == b.x && a.y < b.y)

        return 1;

    else

        return 0;
}

stick st[5005], st0[5005];

int main()
{

    int n, i, j, m;

    cin >> n;

    for (i = 0; i < n; i++)
    {

        cin >> st[i].x >> st[i].y;
    }

    m = 1;

    st0[1].x = st0[1].y = 0;

    sort(st, st + n, cmp);

    for (i = 0; i < n; i++)
    {

        for (j = 1; j <= m; j++)
        {

            if (st[i].x >= st0[j].x && st[i].y >= st0[j].y)
            {

                st0[j].x = st[i].x;

                st0[j].y = st[i].y;

                break;
            }
        }

        if (j > m)
        {

            m += 1;

            st0[m].x = st[i].x;

            st0[m].y = st[i].y;
        }
    }

    cout << m + 1;

    return 0;
}