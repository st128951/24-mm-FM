#include<cstdio>
#include<cstdlib>
#include<ctime>

int* initIntArray(int len)
{
	int* res = nullptr;
	if (len != 0)
	{
		res = (int*)malloc(sizeof(int) * len);
		for (int i = 0; res != nullptr && i < len; ++i)
		{
			res[i] = 0;
		}
		return res;
	}
	else if(len == 0)
	{
		printf("Number of elements can not be equal to 0\n");
		return 0;
	}
}

void printIntArray(int* a, int len)
{
	for (int i = 0; a != nullptr && i < len; ++i)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

void randomizeIntArray(int* a, int len, int min = 0, int max = 9)
{
	if (a != nullptr)
	{
		for (int i = 0; i < len; ++i)
		{
			a[i] = rand() % (max - min + 1) + min;
		}
	}
}

void ManualArray(int* a, int len)
{
	if (a != nullptr)
	{
		for (int i = 0; i < len; ++i)
		{
			scanf_s("%d", &a[i]);
		}
	}
}


int sumOfIntArray(int* a, int len)
{
	int res = 0;
	for (int i = 0; a != nullptr && i < len; ++i)
	{
		res += a[i];
	}
	return res;
}

void expandIntArray_back(int** a, int* len)
{
	int* newArray = initIntArray(*len + 1);
	if (newArray != nullptr)
	{
		for (int i = 0; i < *len; ++i)
		{
			newArray[i] = (*a)[i];
		}
		free(*a);
		*a = newArray;
		(*len)++;
	}
}

void expandIntArray_front(int** a, int* len)
{
	int* newArray = initIntArray(*len + 1);
	if (newArray != nullptr)
	{
		for (int i = 1; i < *len + 1; ++i)
		{
			newArray[i] = (*a)[i - 1];
		}
		free(*a);
		*a = newArray;
		(*len)++;
	}
}

void addElementToEnd(int** a, int* len, int element)
{
	expandIntArray_back(a, len);
	(*a)[*len - 1] = element;
}

void addElementToStart(int** a, int* len, int element)
{
	expandIntArray_front(a, len);
	(*a)[0] = element;

}

void printMenu1()
{
	printf("1 - Enter the Number of elements\n");
	printf("0 - Exit\n");
}

void printMenu2()
{
	printf("1 - Enter elements by using console\n");
	printf("2 - Randomize Array\n");
	printf("0 - Exit\n");
}

void printMenu3()
{
	printf("0 - Exit\n");
	printf("1 - Print array\n");
	printf("2 - Add to end\n");
	printf("3 - Add to front\n");
	printf("4 - Clean console\n");
}

int main(int argc, char* argv[])
{
	system("cls");
	srand(time(0));
	printMenu1();
	int choice = 0;
	scanf_s("%d", &choice);

	switch (choice)
	{
	case 0:
	{
		return 0;
	}
	case 1:
	{
		printf("The Number of elements - ");
		break;
	}
	default:
	{
		printf("Unknown command. Try again\n");
		return 0;
	}
	}

	int len = 0;
	scanf_s("%d", &len);
	printf("\n");

	int* a = initIntArray(len);

	printMenu2();
	int choice_a = 0;
	scanf_s("%d", &choice_a);
	switch (choice_a)
	{
	case 0:
	{
		return 0;
	}
	case 1:
	{
		printf("Elements of array : \n");
		ManualArray(a, len);
		break;
	}
	case 2:
	{
		randomizeIntArray(a, len);
		printf("Random Array is ready\n");
		break;
	}
	default:
	{
		printf("Unknown command. Try again\n");
		return 0;
	}
	}

	bool flag = true;
	while (flag)
	{
		printMenu3();
		int choice_2 = 0;
		scanf_s("%d", &choice_2);
		switch (choice_2)
		{
		case 0:
		{
			flag = false;
			break;
		}
		case 1:
		{
			printIntArray(a, len);
			break;
		}
		case 2:
		{
			int el = 0;
			printf("New element - ");
			scanf_s("%d", &el);
			addElementToEnd(&a, &len, el);
			printf("\n");
			printIntArray(a, len);
			break;
		}
		case 3:
		{
			int el = 0;
			printf("New element - ");
			scanf_s("%d", &el);
			addElementToStart(&a, &len, el);
			printf("\n");
			printIntArray(a, len);
			break;
		}
		case 4:
		{
			system("cls");
			break;
		}
		default:
		{
			printf("Unknown command. Try again\n");
			return 0;
		}
		}
	}
	
	free(a);

	return 0;
}