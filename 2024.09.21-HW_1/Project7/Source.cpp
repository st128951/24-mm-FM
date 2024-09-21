#include<iostream>

int main(int argc, char* argv[])
{
	int a = 0;
	int b = 0;

	scanf_s("%d", &a);
	scanf_s("%d", &b);

	int c = a * b;

	printf("%d", (c % 109 + 109) % 109 + 1);

	return EXIT_SUCCESS;
}