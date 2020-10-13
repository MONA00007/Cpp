#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

//为了避免排序后造成原序列的相对位置发生改动，这里使用vector容器
int func(vector<int> ve, int C)
{
    int count = 0;
    sort(ve.begin(), ve.end() - 1); //对ve容器进行递增排序
    int n = ve.size();

    for (int j = 0; j < n; j++)
    {
        for (int i = j + 1; i < n; i++)
        {
            if (ve[i] == ve[j] + C)
                count++;
            else if (ve[i] > ve[j] + C)
                break;
        }
    }
    return count;
}

int main()
{
    int n, x;
    cin >> n >> x;
    int a[10000];
    int aa, s, m, k;

    while (cin >> aa >> s >> m)
    {
        for (int i = 0; i < m; i++)
        {
            a[k++] = aa;
            aa += s;
        }
    }
    vector<int> ve(a, a + n);
    cout
        << func(ve, x);
}