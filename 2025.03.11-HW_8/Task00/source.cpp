#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"Matrix.h"

int main(int argc, char* argv[])
{
	Matrix matr(4, 5);
	for (int i = 0; i < matr.getR(); ++i)
	{
		for (int j = 0; j < matr.getC(); ++j)
		{
			matr.set(i, j, rand() % (1 - 10 + 1) + 1);
		}
	}
	matr.print(std::cout);
	std::cout << matr.det() << "\n";
	Matrix m1 = transpose(matr);
	m1.print(std::cout);
	return 0;
}