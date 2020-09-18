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
    int n;
    while (~scanf("%d", &n))
    {
        while (n--)
        {
            char str1[MAX], str2[MAX];
            scanf("%s %s", str1, str2);
            int len1 = strlen(str1);
            int len2 = strlen(str2);
            bool flag = false;
            if (len1 == len2)
            {
                for (int i = 0; i < len2; i++)
                {
                    str2[len2 + i] = str2[i];
                }
                len2 = len2 * 2;
                str2[len2] = '\0';
                if (strstr(str2, str1) != NULL)
                    flag = true;
            }
            if (flag)
                printf("Yes\n");
            else
                printf("No\n");
        }
    }
}