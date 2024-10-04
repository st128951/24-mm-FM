#include<iostream>

int main(int argc, char* argv[])
{
	int k = 0;
	int m = 0;
	int n = 0;

	scanf_s("%d", &k);
	scanf_s("%d", &m);
	scanf_s("%d", &n);


	if (n % k == 0)
	{
		int f = (n / k) * 2 * m;
		printf("%d", f);
	}
	else if ((n % k) <= (k / 2) && (n / k) > 0)
	{
		int f = (n / k + 1) * 2 * m - m;
		printf("%d", f);
	}
	else
	{
		int f = (n / k + 1) * 2 * m;
		printf("%d", f);
	}

	return EXIT_SUCCESS;
}