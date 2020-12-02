#include <iostream>
#include <algorithm>
#include <cstring>
#include <stdio.h>
#include <cmath>
using namespace std;
struct work
{
    int day;
    int lose;
    int t = 1;
};
struct work homework[1000];
bool cmp1(struct work a1, struct work a2)
{
    if (a1.day == a2.day)
    {
        return a1.lose > a2.lose;
    }
    return a1.day < a2.day;
}
main()
{
    int m;

    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> homework[i].day >> homework[i].lose;
        homework[i].t = 1;
    }

    struct work a;
    sort(homework, homework + m, cmp1);
    int ans = 0, day = 1;
    for (int i = 0; i < m; i++)
    {
        if (homework[i].day < day && homework[i].t == 1)
        {
            ans += homework[i].lose;
            for (int j = i + 1; j < m; j++)
            {
                if (homework[j].day >= day && homework[j].t == 1)
                {
                    homework[j].t = 0;
                    break;
                }
            }
        }
        if (homework[i].t == 1)
        {
            day++;
        }
    }
    cout << ans;
}