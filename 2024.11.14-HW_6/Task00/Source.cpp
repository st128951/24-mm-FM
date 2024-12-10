#include<cstdio>
#include<cstdlib>
#include<ctime>

int* initIntArray(int len)
{
	int* res = nullptr;
	if (len > 0)
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
		exit(0);
	}
	else if (len < 0)
	{
		printf("Number of elements can not be less then 0\n");
		exit(0);
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

void randomizeIntArray(int* a, int len, int min = -100, int max = 100)
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

void DelFirstEl(int** a, int* len)
{
	int* newArray = initIntArray(*len - 1);
	if (newArray != nullptr)
	{
		for (int i = 1; i < *(len); ++i)
		{
			newArray[i - 1] = (*a)[i];
		}
		free(*a);
		*a = newArray;
		(*len)--;
	}
}

void DelFinalEl(int** a, int* len)
{
	int* newArray = initIntArray(*len - 1);
	if (newArray != nullptr)
	{
		for (int i = 0; i < (*len - 1); ++i)
		{
			newArray[i] = (*a)[i];
		}
		free(*a);
		*a = newArray;
		(*len)--;
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

void ClearAndChangeArray(int* a, int len)
{
	
	for (int i = 0; a != nullptr && i < len; ++i)
		{
			a[i] = 0;
		}
	printf("Add elements of new array : \n");
	ManualArray(a, len); 
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
	printf("4 - Change Array\n");
	printf("5 - Delete first element\n");
	printf("6 - Delete final element\n");
	printf("7 - Clean console\n");
}

void choice_1(int choice)
{
	switch (choice)
	{
	case 0:
	{
		exit(0);
	}
	case 1:
	{
		printf("The Number of elements - ");
		break;
	}
	default: 
	{
		printf("Unknown command. Try again\n");
		exit(0);
	}
	}
}

void choice_2(int choice_a, int* a, int len)
{
	switch (choice_a)
	{
	case 0:
	{
		exit(0);
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
		exit(0);
	}
	}
}

int main(int argc, char* argv[])
{
	system("cls");
	srand(time(0));
	printMenu1();
	int choice = 0;
	scanf_s("%d", &choice);

	choice_1(choice);

	int len = 0;
	scanf_s("%d", &len);
	printf("\n");

	int* a = initIntArray(len);

	printMenu2();
	int choice_a = 0;
	scanf_s("%d", &choice_a);

	choice_2(choice_a, a, len);

	bool flag = true;
	while (flag)
	{
		printf("\n");
		printMenu3();
		printf("\n");
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
			printf("\n New Array :\n");
			printIntArray(a, len);
			break;
		}
		case 3:
		{
			int el = 0;
			printf("New element - ");
			scanf_s("%d", &el);
			addElementToStart(&a, &len, el);
			printf("\nNew Array :\n");
			printIntArray(a, len);
			break;
		}
		case 4:
		{
			printf("Number of elements is %d\n", len);
			ClearAndChangeArray(a, len);
			break;
		}
		case 5:
		{
			DelFirstEl(&a, &len);
			printf("First element deleted\n");
			break;
		}
		case 6:
		{
			DelFinalEl(&a, &len);
			printf("Final element deleted\n");
			break;
		}
		case 7:
		{
			system("cls");
			break;
		}
		default:
		{
			printf("Unknown command. Try again\n");
			exit(0);
		}
		}
	}
	
	free(a);

	return 0;
}