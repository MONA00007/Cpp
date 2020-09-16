#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>

#define MAX 1500
//#define INF 1000000000

using namespace std;
typedef long long int LL;
struct bign
{
    int num[MAX];
    int len;
    bign()
    {
        memset(num, 0, sizeof(num));
        len = 0;
    };
};

bign change(char str[]) //将字符串str转换成大数a
{
    bign a;
    a.len = strlen(str);
    for (int i = 0; i < a.len; i++)
    {
        a.num[i] = str[a.len - 1 - i] - '0';
    }
    return a;
}

bign multi(bign a, bign b) //大数相乘，返回大数c
{
    bign c;
    c.len = a.len + b.len - 1;
    for (int i = 0; i < a.len; i++) //a和b每一位相乘
    {
        for (int j = 0; j < b.len; j++)
        {
            c.num[i + j] += a.num[i] * b.num[j];
        }
    }
    for (int i = 0; i < c.len; i++) //处理进位
    {
        if (c.num[i] >= 10)
        {
            c.num[i + 1] += c.num[i] / 10;
            c.num[i] %= 10;
        }
    }
    if (c.num[c.len])
        c.len++;
    return c;
}

int main()
{
    char str1[MAX], str2[MAX];
    while (~scanf("%s %s", str1, str2))
    {
        bign a = change(str1);
        bign b = change(str2);
        bign c = multi(a, b);
        for (int i = 0; i < c.len; i++)
        {
            printf("%d", c.num[c.len - i - 1]);
        }
        printf("\n");
    }
}