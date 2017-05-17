#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>

void push(int *a, int value, int &i)
{
	if (!a[i])
	{
		int b = i + 1;
		a = (int*)realloc(a, b * sizeof(int));
	}
	a[i] = value;
	i++;
}

void pop(int *a, int &i)
{
	int b = i - 1;
	for (int j = 0; j < b; j++)
		a[j] = a[j + 1];
	a = (int*)realloc(a, b * sizeof(int));
	i--;
}

int main()
{
	int *a = NULL, i = 0, elem, k;
	a = (int*)realloc(a, sizeof(int));
	do
	{
		printf("1 - Add element\n");
		printf("2 - Del element\n");
		printf("3 - Print list\n");
		scanf("%i", &k);
		switch (k)
		{
		case 1:
			printf("What's you want to add? \n");
			scanf("%d", &elem);
			push(a, elem, i);
			break;
		case 2:
			pop(a, i);
			break;
		case 3:
			for (int j = 0; j < i; j++)
				printf("%d ", a[j]);
			break;
		default:
			printf("Wrong command!\n");
		}
	} while (k != 5);
	return 0;
}