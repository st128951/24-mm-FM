#include<iostream>
#include <cmath> 
int main(int argc, char* argv[])
{
    int n = 0;
    int x = 0;
    int a[1000] = { 0 };

    scanf_s("%d", &n);

    for (int i = 0; i < n; ++i)
    {
        scanf_s("%d", &a[i]);
    }


    scanf_s("%d", &x);


    int cv = a[0];
    int md = abs(a[0] - x);

    for (int i = 1; i < n; ++i)
    {
        int ctemp = abs(a[i] - x);
        if (ctemp < md || (ctemp == md && a[i] < cv))
        {
            cv = a[i];
            md = ctemp;
        }
    }

    printf("%d\n", cv);

    return EXIT_SUCCESS;
}