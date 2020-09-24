#include <iostream>
using namespace std;
int twoSum(int n) //计算二进制各位数的数字之和
{
    if (n == 1)
        return 1;
    return (n % 2) + twoSum(n / 2);
}

int tenSum(int n) //计算十进制各位数的数字之和
{
    if (n < 10)
        return n;
    return n % 10 + tenSum(n / 10);
}

int main()
{
    int n, sum = 0;
    while (cin >> n)
    {
        for (int i = 1; i <= n; i++)
            if (twoSum(i) == tenSum(i))
                sum++;
        cout << sum;
    }
}