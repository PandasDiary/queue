#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>

void push(int *a, int elem, int &i)
{
	int b = i + 1;
	a = (int*)realloc(a, b * sizeof(int));
	a[i] = elem;
	i++;
}


int main()
{
	int *a, i = 0, elem, k, b;
	a = (int*)malloc(sizeof(int));
	do
	{
		printf("1 - Add element\n");
		printf("2 - Del element\n");
		printf("3 - Print queue\n");
		scanf("%i", &k);
		switch (k)
		{
		case 1:
			printf("What's you want to add? \n");
			scanf("%d", &elem);
			b = i + 1;
			a = (int*)realloc(a, b * sizeof(int));//���������� ������� ������� �� 1 �������
			a[i] = elem;//������ ���������� �������� � �������
			i++;
			//push(a, elem, i);
			break;
		case 2:
			if (i > 0)
			{
				i--;
				for (int j = 0; j < i; j++)//�������� ��� �������� ������� �� 1 �����
					a[j] = a[j + 1];
				a = (int*)realloc(a, i * sizeof(int));//��������� ������ ������� �� 1 
			}
			break;
		case 3:
			for (int j = 0; j < i; j++)//����� ���� �������
				printf("%d ", a[j]);
			printf("\n");
			break;
		default:
			printf("Wrong command!\n");
		}
	} while (k != 5);
	free(a);
	return 0;
}