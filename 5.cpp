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
                for (int i = 0, j = 0; i < len1; i++)
                {
                    int k = j;
                    while (j < len2)
                    {
                        if (str1[i++] != str2[j++])
                            break;
                    }
                    if (j == len2 && k != len2)
                    {
                        for (j = 0; j < k; i++, j++)
                        {
                            if (str1[i] != str2[j])
                                break;
                        }
                        if (j == k && str1[i] == '\0')
                        {
                            flag = true;
                            break;
                        }
                    }
                    i = -1;
                    j = k + 1;
                    if (j == len2)
                        break;
                }
            }
            if (flag)
                printf("Yes\n");
            else
                printf("No\n");
        }
    }
}