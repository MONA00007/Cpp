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
#define MAX 1000001
//#define INF 1000000000
using namespace std;
//typedef long long int LL;
vector<int> vi;

int find(int n, int c) //先排序，再进行二分查找
{
    sort(vi.begin(), vi.begin() + n);
    int t = 0;
    int low, high, mid;
    for (int i = 0; i <= n - 1; i++)
    {
        low = 0, high = n - 1, mid;
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
            else if (vi[mid] - vi[i] < c)
                low = mid + 1;
        }
    }
    return t;
}

int main(int agrc, char *agrv[])
{
    int n, c, a, s, m, k;

    //while (~scanf("%d %d", &n, &c))
    scanf("%d %d", &n, &c);
    {
        k = 0;
        while (~scanf("%d %d %d", &a, &s, &m))
        {
            for (int i = 0; i < m; i++)
            {
                vi.push_back(a);
                k++;
                a += s;
            }
        }
        printf("%d", find(min(n, k), c));
        //vi.clear();
    }
}