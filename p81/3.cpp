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
#define MAX 100001
//#define INF 1000000000
using namespace std;
//typedef long long int LL;
int item[MAX];

int f(int left, int right) //左右标逼近
{
    if (left == right || (right - left == 1 && item[right] == item[left])) //左右标相邻或为同一个试，递归结束
        return 0;
    if (item[left] == item[right]) //左右标相等时，不做处理，左右标继续逼近
        return 0 + f(left + 1, right - 1);
    else if (item[left] < item[right]) //左小于右时，左标与左标右手第一个相加，次数加一，左标向左移动一位
    {
        item[left + 1] += item[left];
        return 1 + f(left + 1, right);
    }
    else //跟上面一种情况相反
    {
        item[right - 1] += item[right];
        return 1 + f(left, right - 1);
    }
}

int main(int agrc, char *agrv[])
{
    int n;
    while (~scanf("%d", &n))
    {

        for (int i = 0; i < n; i++)
        {
            scanf("%d", &item[i]);
        }
        int times = f(0, n - 1);
        printf("%d\n", times);
    }
}