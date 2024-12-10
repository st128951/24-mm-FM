#include <iostream>
#include <cstdlib>

int main(int argc, char* argv[])
{
    int n = 0; 
    int m = 0;

    std::cin >> n;
    std::cin >> m;

    int* a = (int*)malloc(n * sizeof(int));
    int* b = (int*)malloc(m * sizeof(int));
    int c[300000] = { 0 };

    for (int i = 0; i < n; ++i) 
    {
        scanf_s("%d", a + i);
    }

    for (int i = 0; i < m; ++i) 
    {
        scanf_s("%d", b + i); 
    }

    for (int i = 0; i < n; ++i) 
    {
        *(c + *(a + i)) = 1;
    }

    for (int i = 0; i < m; ++i) 
    {
        if (*(c + *(b + i)) == 1) 
        {
            *(c + *(b + i)) = 2; 
        }
    }

    for (int i = 0; i < 300000; ++i)
    {
        if (*(c + i) == 2)
        {
            std::cout << i << " ";
        }
    }

    free(a);
    free(b);
   
    return EXIT_SUCCESS;
}
