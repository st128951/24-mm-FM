#include<iostream> 
#include<cmath>

int main(int arc, char* argv[])
{
    int a1 = 0;
    int b1 = 0;
    int r1 = 0;
    int a2 = 0;
    int b2 = 0;
    int r2 = 0;

    scanf_s("%d", &a1);
    scanf_s("%d", &b1);
    scanf_s("%d", &r1);
    scanf_s("%d", &a2);
    scanf_s("%d", &b2);
    scanf_s("%d", &r2);
 
    double lght = sqrt((a2 - a1) * (a2 - a1) + (b2 - b1) * (b2 - b1));

    if (r1 + r2 >= lght && lght + r2 >= r1 && lght + r1 >= r2)
    {
        printf("YES");
    }
    else
    {
        printf("NO");
    }
  return EXIT_SUCCESS;
}