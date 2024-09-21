#include <iostream>

int main(int arc, char* argv[])
{
    int h = 0;
    int a = 0;
    int b = 0;
    int d = 0;

    scanf_s("%d", &h);
    scanf_s("%d", &a);
    scanf_s("%d", &b);

    h = h + (((a - b) - h % (a - b)) % (a - b));
    h = (h - a) * ((h / a) - ((h - a) / a));
    d = d + 1;
    h = h + (((a - b) - h % (a - b)) % (a - b));
    d= d + h / (a - b);

    printf("%d", d);

    return EXIT_SUCCESS;
}