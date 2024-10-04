#include <iostream>
int main(int argc, char* argv[])
{
	int m = 0;
	int n = 0;
	int o = 0;

	scanf_s("%d", &o);

	for (int i = 1; i <= o;  ++i)
	{
		scanf_s("%d", &n);
		scanf_s("%d", &m);
		printf("%d\n", 19 * m + (n + 239) * (n + 366) / 2);
	}
	return EXIT_SUCCESS;
}