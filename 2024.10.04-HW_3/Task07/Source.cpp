#include <iostream>
int main(int argc, char* argv[])
{
	int m = 0;
	int n = 0;

	scanf_s("%d", &n);
	scanf_s("%d", &m); 

	int temp_n = n;
	int temp_m = m;

	while (temp_m != 0)
	{
		int z = temp_m;
		temp_m = temp_n % temp_m;
		temp_n = z;
	}

	if (m % n == 0)
	{
		printf("%d", 1);
	}
	else
	{
		printf("%d", n / temp_n);
	}
	return EXIT_SUCCESS;
}