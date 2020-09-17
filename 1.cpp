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
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n;
        while (~scanf("%d", &n))
        {
            string str[MAX]; //存储字符串

            for (int i = 0; i < n; ++i)
            {
                cin >> str[i];
            }
            bool len_flag = true, isle_flag = true;
            //判断是否符合两种排序的标准
            for (int i = 1; i < n; i++) //判断是否符合长度排序
            {
                if (str[i - 1].length() > str[i].length())
                {
                    len_flag = false;
                    break;
                }
            }
            for (int i = 1; i < n; ++i) //判断是否符合字典序排序
            {
                if (str[i - 1] > str[i])
                {
                    isle_flag = false;
                    break;
                }
            }
            if (len_flag && isle_flag)
                printf("both\n");
            else if (len_flag)
                printf("lengths\n");
            else if (isle_flag)
                printf("islexicalorder\n");
            else
                printf("none\n");
        }
    }
}