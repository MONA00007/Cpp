#include <stdio.h>
//#include <windows.h>
int main()
{
    int a, b;
    bool flag = false;
    while (~scanf("%d %d", &a, &b))
    {
        if (flag == true)
            printf("\n");
        flag = true;
        printf("%d", a + b);
    }
    return 0;
}