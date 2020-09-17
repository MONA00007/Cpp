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

#define MAX 101
//#define INF 1000000000

using namespace std;
//typedef long long int LL;

int main()
{
    char str[MAX];
    while (~scanf("%s", str))
    {
        char str2[MAX];
        int a[MAX];
        int j = 0, num = 0;
        for (int i = 0; str[i] != '\0'; ++i) //将*先加入a
        {
            if (str[i] == '*')
            {
                str2[j++] = '*';
                a[i] = i;
            }
        }
        for (int i = 0; str[i] != '\0'; ++i) //再将其他字符加入a
        {
            if (str[i] != '*')
            {
                str2[j] = str[i];
                a[i] = j++;
            }
        }
        str2[j] = '\0';
        a[j] = '\0';
        for (int i = 0; i < j; ++i) //判断字符串是否发生换位
        {
            if (a[i] != i)
                num++;
        }
        printf("%s\n%d\n", str2, num);
    }
}