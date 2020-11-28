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
#define MAXN 100000
#define INF 1000000007
//#define INF 0x3f3f3f3f
using namespace std;
typedef long long int LL;

struct node
{
    int x, num;
};
map<int, bool> vi;
int BFS(int x)
{
    queue<node> q;
    node temp, next;
    temp.x = x, temp.num = 0;
    vi[x] = true;
    q.push(temp);
    while (!q.empty())
    {
        temp = q.front();
        q.pop();
        if (!temp.x % INF)
            return temp.num;
        next = temp, next.num++;
        if (next.num <= MAXN)
        {
            LL tt = temp.x;
            tt = (4 * tt + 3) % INF;
            next.x = tt;

            if (!vi[tt])
                q.push(next), vi[tt] = true;
            tt = temp.x;
            tt = (8 * tt + 7) % INF;
            next.x = tt;
            if (!vi[tt])
                q.push(next), vi[tt] = true;
        }
    }
    return -1;
}
int main(int agrc, char *agrv[])
{
    int x;
    while (~scanf("%d", &x))
    {
        printf("%d", BFS(x));
    }
}
