#include <iostream>
using namespace std;
int count;
int m, n;
void move(int a, int b)
{
    if (a == n && b == m)
    {
        count++;
        return;
    }
    if (a < n && b < m)
    {
        for (int i = 0; i <= 1; i++)
        {
            if (i == 0)
            {
                a += 2;
                b += 1;
                move(a, b);
                a -= 2;
                b -= 1;
            }
            else
            {
                a += 1;
                b += 2;
                move(a, b);
                a -= 1;
                b -= 2;
            }
        }
    }
}

int main()

{

    cin >> n >> m;
    move(1, 1);
    cout << count;
}