#include<iostream>

int main(int argc, char* argv[])
{
	int n = 0;
	int m = 0;

	scanf_s("%d", &n);
	scanf_s("%d", &m);

	int f = (n + 1) * m + (m + 1) * n;
	int z = n + m;
	if (n == 1 || m == 1)
	{
		printf("%d", n * m * 4);
	}
	else if (m % 2 == 0 || n % 2 == 0)
	{
		printf("%d", f + z);
	}
	else
	{
		printf("%d", f + z - 2);
	}

	return EXIT_SUCCESS;
}
