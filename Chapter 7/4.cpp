#include <iostream>
#include <algorithm>
#define MAXN 201
using namespace std;
int n, score;
double avg, sum;
struct node
{
    int ai, bi;
} a[MAXN];
int func()
{
    sort(a, a + n, [](node a, node b) { return a.bi < b.bi; });
    double aim = avg * n;
    int time = 0;
    for (int i = 0; i < n; i++)
    {
        if (sum + score - a[i].ai >= aim)
        {
            int k = score - a[i].ai;
            for (int j = 0; j < k; j++)
            {
                time += a[i].bi;
                sum++;
                if (sum >= aim)
                    break;
            }
            break;
        }
        else
        {
            sum += score - a[i].ai;
            time += (score - a[i].ai) * a[i].bi;
        }
    }
    return time;
}
int main(int agrc, char *agrv[])
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].ai >> a[i].bi;
        sum += a[i].ai;
    }
    cin >> score >> avg;
    printf("%d", func());
    system("pause");
}
