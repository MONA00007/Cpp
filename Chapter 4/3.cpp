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
#define maxn 1000010
//#define INF 1000000000
using namespace std;
//typedef long long int LL;
int mins, maxs, n;

int main(int agrc, char *agrv[])
{
    //scanf("%d %d", &mins, &maxs);
    while (~scanf("%d %d", &mins, &maxs))
    {
        if (mins > maxs)
            swap(mins, maxs);
        scanf("%d", &n);
        vector<int> vi;

        int x, cnt = 0;
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &x);
            vi.push_back(x);
        }
        int len = vi.size(), i;
        while (mins <= maxs)
        {
            for (i = 0; i < len; i++)
            {
                if ((mins >= vi[i] * 2 && mins <= vi[i] * 10) || (vi[i] >= mins * 2 && vi[i] <= mins * 10))
                    break;
            }
            if (i == len)
            {
                cnt++;
                vi.push_back(mins);
            }
            mins++;
        }
        printf("%d", cnt);
    }
}