#include <iostream>
int main(int argc, char* argv[])
{
	long long a = 0;
	long long b = 0;
	long long c = 0;
	long long d = 0;

	scanf_s("%ll", &a);
	scanf_s("%ll", &b);
	scanf_s("%ll", &c);
	scanf_s("%ll", &d);

	for (long long x = -100; x <= 100; ++x)
	{
		if ((a * x * x * x + b * x * x + c * x + d) == 0)
			printf("%ll ", x);
	}
	return EXIT_SUCCESS;
}