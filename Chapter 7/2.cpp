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
#define MAXN 1001
#define INF 0x3f3f3f3f
using namespace std;

int n;
int func()
{
    int max1, max2, max3, min1, min2, temp;
    max1 = max2 = max3 = -INF, min1 = min2 = INF;
    while (n--)
    {
        cin >> temp;
        if (temp > max3)
        {
            if (temp >= max2)
            {
                if (temp >= max1)
                    max3 = max2, max2 = max1, max1 = temp;
                else
                    max3 = max2, max2 = temp;
            }
            else
                max3 = temp;
        }
        if (temp < min2)
        {
            if (temp <= min1)
                min2 = min1, min1 = temp;
            else
                min2 = temp;
        }
    }
    return max(max1 * max2 * max3, max1 * min1 * min2);
}
int main(int agrc, char *agrv[])
{
    cin >> n;
    printf("%d", func());
}
