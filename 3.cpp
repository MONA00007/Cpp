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
        for (int i = 0; str[i] != '\0'; ++i)
        {
            if (str[i] == '*')
            {
                str2[j] = '*';
                a[i] = j++;
            }
        }
        for (int i = 0; str[i] != '\0'; ++i)
        {
            if (str[i] != '*')
            {
                str2[j] = str[i];
                a[i] = j++;
            }
        }
        str2[j] = '\0';
        a[j] = '\0';
        for (int i = 0; i < j; ++i)
        {
            if (a[i] != i)
                num++;
        }
        printf("%s\n%d\n", str2, num / 2);
    }
}