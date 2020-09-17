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
//typedef long long int LL;

struct node
{
    int x, y; //x为原来的数字，y为出现的次数
    node()
    {
        y = 0;
    }
};

bool cmp(node a, node b) //如果出现次数不相同，就按出现的次数排序
{                        //不然出现次数相同，就按原来的数字大小排序
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
            a[b].x = b; //记录原本的数字
            a[b].y++;   //记录出现的次数
        }
        sort(a, a + MAX, cmp); //进行排序
        for (int i = 0; a[i].y != 0; ++i)
        {
            printf("%d %d\n", a[i].x, a[i].y);
        }
    }
}