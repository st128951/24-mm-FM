#include <iostream>
int main(int argc, char* argv[])
{
    int i = 0;
    int j = 0;
    scanf_s("%d", &i);
    scanf_s("%d", &j);

    int temp_i = i;
    int temp_j = j;

    while (temp_j != 0)
    {
        int z = temp_j;
        temp_j = temp_i % temp_j;
        temp_i = z;
    }

    int a0 = 1;
    int a1 = 1;
    int a = 0;
    for (int k = 2; k < temp_i; ++k) 
    {
        a = (a0 + a1) % 1000000000;
        a0 = a1;
        a1 = a;
    }
    printf("%d", a1);

    return EXIT_SUCCESS;
}