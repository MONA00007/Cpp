#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>

#define MAX 1001
//#define INF 1000000000

using namespace std;
typedef long long int LL;

struct node
{
    int x, y;
    node()
    {
        y = 0;
    }
};

bool cmp(node a, node b)
{
    if (a.y != b.y)
        return a.y > b.y;
    else
        return a.x < b.x;
}

int main()
{
    int n;
    while (~scanf("%d", &n))
    {
        node a[MAX];
        int b;
        memset(a, 0, sizeof(a));
        for (int i = 0; i < n; ++i)
        {
            scanf("%d", &b);
            a[b].x = b;
            a[b].y++;
        }
        sort(a, a + MAX, cmp);
        for (int i = 0; a[i].y != 0; ++i)
        {
            printf("%d %d\n", a[i].x, a[i].y);
        }
    }
}