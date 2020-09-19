#include <iostream>
#include <algorithm>
#include <functional>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>

#define MAX 101
//#define INF 1000000000

using namespace std;
//typedef long long int LL;
int num;
bool hashtable[10] = {false};
int p[10] = {0};
void generateP(int index, int n)
{
    if (index == n + 1)
    {
        num++;
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (!hashtable[i])
        {
            bool flag = true;
            for (int pre = 1; pre < index; ++pre)
            {
                if (abs(pre - index) == abs(i - p[pre]))
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                p[index] = i;
                hashtable[i] = true;
                generateP(index + 1, n);
                hashtable[i] = false;
            }
        }
    }
}

int main()
{
    int n;
    while (~scanf("%d", &n))
    {
        num = 0;
        generateP(1, n);
        printf("%d\n", num);
    }
}