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
#define MAX 10
//#define INF 1000000000
using namespace std;
//typedef long long int LL;

struct node
{
    int x, y, len, time;
    friend bool operator<(node a, node b)
    {
        return a.len > b.len;
    }
};
int xx[4] = {0, 0, 1, -1}, yy[4] = {1, -1, 0, 0}; //四向移动
int pp[MAX][MAX];                                 //存储地图
int BFS(int begin_x, int begin_y, int end_x, int end_y, int a, int b)
{
    priority_queue<node> q;
    node index;
    index.len = 0, index.time = 6;
    index.x = begin_x, index.y = begin_y;
    q.push(index);
    while (!q.empty())
    {
        index = q.top();
        q.pop();
        if (index.x == end_x && index.y == end_y)
            return index.len;
        if (pp[index.x][index.y] == 4 && index.time > 0)
        {
            node temp = index;
            index.time = 6;
            //index.len++;
            pp[index.x][index.y] = 0;
            q.push(temp);
        }
        for (int i = 0; i < 4; i++)
        {
            node temp = index;
            temp.time--;
            temp.len++;
            temp.x += xx[i];
            temp.y += yy[i];
            if (pp[temp.x][temp.y] != 0 && temp.time > 0)
                q.push(temp);
        }
    }
    return -1;
}

int main(int agrc, char *agrv[])
{
    int n;
    while (~scanf("%d", &n))
    {
        while (n--)
        {
            memset(pp, 0, sizeof(pp));
            int a, b;
            int begin_x, begin_y;
            int end_x, end_y;
            scanf("%d %d", &a, &b);
            for (int i = 1; i <= a; i++)
            {
                for (int j = 1; j <= b; j++)
                {
                    scanf("%d", &pp[i][j]);
                    if (pp[i][j] == 2)
                    {
                        begin_x = i;
                        begin_y = j;
                    }
                    if (pp[i][j] == 3)
                    {
                        end_x = i;
                        end_y = j;
                    }
                }
            }
            int flag = BFS(begin_x, begin_y, end_x, end_y, a, b);
            printf("%d\n", flag);
        }
    }
}