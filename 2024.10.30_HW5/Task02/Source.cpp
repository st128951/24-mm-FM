#include<iostream>

int main(int argc, char* argv[])
{
	int a[100000] = { 0 };
	int i = 0;
	int n = 0;
	int k = 0;

	std :: cin >> n;

	for (i = 0; i < n; ++i)
	{
		std::cin >> *(a + i);
	}

	std :: cin >> k;

	if (k > 0)
	{
		k %= n;
	}
	else
	{
		k = n - ((-k) % n);
	}

	for (i = n - k; i < n; ++i)
	{
		std::cout << *(a + i) << ' ';
	}

	for (i = 0; i < n - k; ++i)
	{
		std::cout << *(a + i) << ' ';
	}
	
	return EXIT_SUCCESS;
}