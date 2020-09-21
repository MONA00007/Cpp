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
    char str1[MAX], str2[MAX];
    while (gets(str1))
    {
        scanf("%s", str2);
        char str3[MAX];
        int len1, len2, len3;
        len1 = strlen(str1);
        len2 = strlen(str2);
        len3 = 0;
        for (int i = 0; i < len1; ++i)
        {
            bool flag = true;
            for (int j = 0; j < len2; ++j)
            {
                if (str1[i] == str2[j])
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
                str3[len3++] = str1[i];
        }
        str3[len3] = '\0';
        printf("%s\n", str3);
    }
}