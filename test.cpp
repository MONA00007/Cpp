#include <iostream>
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
#define MAX 31
#define INF 1000000000
using namespace std;
//typedef long long int LL;

struct node
{
    int w, c;
} a[MAX][MAX];


int n, m, cost, minw;
bool table[MAX];
int mw[MAX], rw, rc, mc[MAX];
void DFS(int index, int tw, int tc)
{
    if (index == n)
    {
        minw = min(minw, tw);
        return;
    }
    for (int i = 0; i < m; i++)
    {
        int ttc = tc + a[index][i].c, ttw = tw + a[index][i].w;
        if (cost >= ttc && minw > ttw && !table[i] && (rw - mw[i] + ttw < minw))
        {
            table[i] = true;
            rw -= mw[i];
            DFS(index + 1, ttw, ttc);
            table[i] = false;
            rw += mw[i];
        }
    }
}

int main(int agrc, char *agrv[])
{
   
    
}