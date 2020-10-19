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
#define maxn 1000001
//#define INF 1000000000
using namespace std;
//typedef long long int LL;
int num[maxn];
int main(int agrc, char *agrv[])
{
    int n, a, b;
    memset(num, -1, sizeof(num));
    num[1] = 0;
    while (cin >> n)
    {
        while (n--)
        {
            scanf("%d %d", &a, &b);
            int end, ans;

            for (int i = 2; i <= b; i++)
            {
                if (num[i] == -1)
                {
                    ans = 1, end = sqrt(i) + 1;
                    for (int j = 2; j < end; ++j)
                    {
                        if (i % j == 0)
                        {
                            ans += j;
                            if ((j * j - i) != 0)
                                ans += i / j;
                        }
                    }
                    num[i] = num[i - 1];
                    if (ans == i)
                        num[i]++;
                }
            }
            printf("%d\n", num[b] - num[a]);
        }
    }
}