#include <iostream>
int main(int argc, char* argv[])
{
    int a = 0;
    int b = 0;

    scanf_s("%d", &a);
    scanf_s("%d", & b);

    int temp_a = a;
    int temp_b = b;

    while (temp_b != 0)
    {
        int z = temp_b;
        temp_b = temp_a % temp_b;
        temp_a = z;
    }

    int f = (a * b) / temp_a;

    printf("%d", f);

    return EXIT_SUCCESS;
}