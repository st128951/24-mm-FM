#include<iostream>
int main(int argc, char* argv[])
{
    int n = 0;
    int m = 0;
    int a[1000] = { 0 };

    scanf_s("%d", &n);

    for (int i = 0; i < n; ++i) 
    {
        scanf_s("%d", &a[i]);
    }

    scanf_s("%d", &m);

    for (int k = 0; k < m; ++k)
    {
        int ik = 0;
        int jk = 0;

        scanf_s("%d", &ik);
        scanf_s("%d", &jk);

        for (int i = ik - 1; i < jk; ++i)
        {
            printf("%d ", a[i]);
        }
        printf("\n");
    }
    return EXIT_SUCCESS;
}