#include <iostream>
#define MAX_SIZE 1000

int main() 
{
    int n = 0;
    int sequence[MAX_SIZE] = { 0 };

    for (int i = 0; i < n; i++) 
    {
        scanf_s("%d", &sequence[i]);
    }

    for (int i = n - 1; i >= 0; i--)
    {
        printf("%d ", sequence[i]);
    }

return EXIT_SUCCESS;
}