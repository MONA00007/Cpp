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
vector<int> vi;

int find(int n, int c) //先排序，再进行二分查找
{
    sort(vi.begin(), vi.begin() + n);
    int t = 0;
    int low, high, mid;
    for (int i = 0; i < n - 1; i++)
    {
        low = i + 1, high = n - 1, mid;
        while (low <= high)
        {
            mid = (low + high) / 2;
            if (vi[mid] - vi[i] == c)
            {
                t++;
                for (int j = mid + 1; j < n; ++j)
                {
                    if (vi[j] - vi[i] == c)
                        t++;
                    else
                        break;
                }
                for (int j = mid - 1; j >= 0; --j)
                {
                    if (vi[j] - vi[i] == c)
                        t++;
                    else
                        break;
                }
                break;
            }
            else if (vi[mid] - vi[i] > c)
                high = mid - 1;
            else
                low = mid + 1;
        }
    }
    return t;
}

int main(int agrc, char *agrv[])
{
    int n, c, x;
    while (~scanf("%d %d", &n, &c))
    {
        for (int i = 0; i < n; ++i)
        {
            scanf("%d", &x);
            vi.push_back(x);
        }
        printf("%d\n", find(n, c));
        vi.clear();
    }
}