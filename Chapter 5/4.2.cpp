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
#define MAX 51
//#define INF 1000000000
using namespace std;
//typedef long long int LL;
int n, len;
char str[MAX];
bool vis[MAX];
bool cmp(int a, int b)
{
    return a > b;
}

int cal(int v, int w, int x, int y, int z)
{
    return v - w * w + x * x * x - y * y * y * y + z * z * z * z * z;
}

bool func()
{
    len = strlen(str);
    sort(str, str + len, cmp);
    for (int v = 0; v < len; v++)
    {
        vis[v] = true;
        for (int w = 0; w < len; w++)
        {
            if (!vis[w])
            {
                vis[w] = true;
                for (int x = 0; x < len; x++)
                {
                    if (!vis[x])
                    {
                        vis[x] = true;
                        for (int y = 0; y < len; y++)
                        {
                            if (!vis[y])
                            {
                                vis[y] = true;
                                for (int z = 0; z < len; z++)
                                {
                                    if (!vis[z])
                                    {
                                        vis[z] = true;
                                        if (cal(str[v] - '@', str[w] - '@', str[x] - '@', str[y] - '@', str[z] - '@') == n)
                                        {
                                            printf("%c%c%c%c%c\n", str[v], str[w], str[x], str[y], str[z]);
                                            return true;
                                        }
                                        vis[z] = false;
                                    }
                                }
                                vis[y] = false;
                            }
                        }
                        vis[x] = false;
                    }
                }
                vis[w] = false;
            }
        }
        vis[v] = false;
    }
    return false;
}
int main(int agrc, char *agrv[])
{
    while (~scanf("%d", &n) && n)
    {
        scanf("%s", str);
        if (!func())
            printf("no solution\n");
    }
}
