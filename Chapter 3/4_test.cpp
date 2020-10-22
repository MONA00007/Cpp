#include <iostream>
#include <string>
using namespace std;
int Count = 0;

void Merge(string &str, int low, int high)
{
    string tmpa;
    int i, j, mid, k = 0;
    mid = (low + high) / 2;
    i = low;
    j = mid + 1;
    while (i <= mid && j <= high)
    {
        if (str[i] <= str[j])
        {
            tmpa[k++] = str[i++];
        }
        else
        {
            tmpa[k++] = str[j++];
            Count += mid - i + 1;
        }
    }
    while (i <= mid)
    {
        tmpa[k++] = str[i++];
    }
    while (j <= high)
        tmpa[k++] = str[j++];
    for (k = 0, i = low; i <= high; k++, i++)
        str[i] = tmpa[k];
}
void MergeSort(string &str, int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        MergeSort(str, low, mid);
        cout << "low" << endl;
        MergeSort(str, mid + 1, high);
        cout << "high" << endl;
        Merge(str, low, high);
    }
}

int main()
{
    int len, n, i;
    while (cin >> len >> n)
    {
        string *str = new string[200];
        int count[200] = {0};
        for (i = 0; i < n; i++)
        {
            cin >> str[i];
            Count = 0;
            MergeSort(str[i], 0, len - 1);
            count[i] = Count;
            cout << count[i] << endl;
        }
        getchar();
    }
}
