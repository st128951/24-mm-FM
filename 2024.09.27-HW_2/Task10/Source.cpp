#include<iostream> 

int main(int arc, char* argv[])
{
    int n = 0;

    scanf_s("%d", &n);

    int a = n % 5;

    int b1 = 0;
    int c1 = 0;

    switch (a)
    {
    case 0:
    {
        int b1 = n / 5;
        printf("%d %d", b1, 0);
        break;
    }
    case 1:
    {
        int b1 = (n - 6) / 5;
        int c1 = 2;
        printf("%d %d", b1, c1);
        break;
    }
    case 2:
    {
        int b1 = (n - 12) / 5;
        int c1 = 4;
        printf("%d %d", b1, c1);
        break;
    }
    case 3:
    {
        int b1 = n / 5;
        int c1 = 1;
        printf("%d %d", b1, c1);
        break;
    }
    default:
    {
        int b1 = (n - 6) / 5;
        int c1 = 3;
        printf("%d %d", b1, c1);
        break;
    }
    }

    return EXIT_SUCCESS;
}