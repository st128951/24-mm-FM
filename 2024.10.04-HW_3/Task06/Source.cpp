=
#include <iostream>
int main ()
{
int gcd(int a, int b) 
{
	if (a * b == 0) return a + b;
	if (a < b) return gcd(a, b % a);
	else return gcd(a % b, b);
}


	int a, b;
	printf("Enter two integers: ");
	scanf("%d %d", &a, &b);
	printf("The least common multiple of %d and %d is: %d\n", a, b, a * b / gcd(a, b));
	return 0;
}