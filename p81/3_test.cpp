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
#define MAX 10001
//#define INF 1000000000
using namespace std;
//typedef long long int LL;
int item[MAX];

int f(int left, int right) //左右标逼近
{
    int times = 0;
    while (left < right)
    {
        if (item[left] == item[right])
        {
            left++;
            right--;
        }
        else if (item[left] < item[right])
        {
            item[left + 1] += item[left];
            left++;
            times++;
        }
        else
        {
            item[right - 1] += item[right];
            right--;
            times++;
        }
    }
    return times;
}

int main(int agrc, char *agrv[])
{
    int n;
    scanf("%d", &n);
    //while (~scanf("%d", &n))
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &item[i]);
        }
        int times = f(0, n - 1);
        printf("%d\n", times);
    }
}