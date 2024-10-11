#include<iostream>
int main(int argc, char* argv[])
{
    int n = 0;
    int x = 0;
    int a[100] = { 0 };

    scanf_s("%d", &n);

    for (int i = 0; i < n; ++i)
    {
        scanf_s("%d", &a[i]);
    }

    scanf_s("%d", &x);

    int p = 1;

    for (int i = 0; i < n; ++i)
    {
        if (x > a[i])
        {
            p = i + 1;
            break;
        }
    }


    if (p == 1 && x <= a[n - 1])
    {
        p = n + 1;
    }

    printf("%d", p);

    return EXIT_SUCCESS;
}