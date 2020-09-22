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
#define MAX 101
//#define INF 1000000000
using namespace std;
//typedef long long int LL;

struct node
{
    char str[MAX];
    int deadline, time_need;
};
int main(int agrc, char *agrv[])
{
    int T;
    node a[20];
    while (~scanf("%d", &T))
    {
        while (T--)
        {
            int n;
            scanf("%d", &n);
            for (int i = 0; i < n; ++i)
            {
                scanf("%s %d %d", a[i].str, &a[i].deadline, &a[i].time_need);
            }

            for (int i = 0; i < n; i++)
            {
                printf("%s\n", a[i].str);
            }
        }
    }
}