#include<iostream> 

int main(int arc, char* argv[])
{
    int a = 0;
    int b = 0;

    scanf_s("%d", &a);
    scanf_s("%d", &b);

    if (a == 1 && b == 1)
    {
        printf("%d", 0);
    }
    if (a != 1 && b != 1 && a == b)
    {
        printf("%d", 2);
    }
    if (a == 1 && b != 1 || b == 1 && a != 1)
    {
        printf("%d", 1);
    }
    if (a != 1 && b != 1 && a != b)
    {
        printf("%d", 1);
    }

    return EXIT_SUCCESS;
}