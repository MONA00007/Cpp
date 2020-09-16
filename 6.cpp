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

#define MAX 1001
//#define INF 1000000000

using namespace std;
//typedef long long int LL;

int main()
{
    int n;
    while (~scanf("%d", &n))
    {
        int hashTable[MAX] = {0}, a;
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &a);
            printf("%d", ++hashTable[a]);
            if (i != n - 1)
                printf(" ");
        }
        printf("\n");
    }
}