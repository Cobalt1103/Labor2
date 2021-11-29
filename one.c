#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Russian");

	FILE* file = fopen("massive.txt", "w");

	int menu, n, x, y, z; // xzy - побочные
	int i;
	unsigned int min, max, keyboard;
	unsigned int* Massive = 0;

	printf("Внимание! В этой программе допускается ввод только натуральных чисел!\n");
	printf("Добрый день! Это главное меню программы. Как вы хотите осуществить ввод чисел?\n");
	printf("1. Сгенерировать случайные числа\n");
	printf("2. Выполнить ввод чисел вручную\n");
	scanf("%d", &menu);

	if (menu == 1)
	{
		printf("Для генерации чисел необходимо выбрать минимальную и максимальную границы, а также количество генерируемых чисел\n");
		printf("Пожалуйста, введите минимальную границу\n");
		scanf("%d", &min);
		printf("Пожалуйста, введите максимальную границу (максимальная граница должна быть больше минимальной!)\n");
		scanf("%d", &max);
		printf("Пожалуйста, введите количество генерируемых чисел\n");
		scanf("%d", &n);
		system("cls");

		printf("Генерация чисел начинается. Процесс работы будет выводится на экран.");
		Sleep(3000);
		system("cls");

		Massive = (unsigned int*)malloc(n * sizeof(unsigned int));

		for (i = 0; i < n; i++)
		{
			Massive[i] = (((double)rand()) / RAND_MAX) * (max - min) + min;
		}
		for (i = 0; i < n; i++)
		{
			printf("Число %d = %d\n", i, Massive[i]);
		}

		printf("Генерация прошла успешно. Чтобы записать полученные данные в файл, нажмите '1', для закрытия пограммы нажмите '2'\n");
		scanf("%d", &x);
		if (x = 1)
		{
			for (i = 0; i < n; i++)
			{
				fprintf(file, "%d\n", Massive[i]);
			}
		}
		if (x = 2)
		{
			goto stop;
		}
	}
	if (menu == 2)
	{
		
        printf("Пожалуйста, введите количество чисел, которое вы собираетесь ввести\n");
		scanf("%d", &n);
		printf("Осуществите ввод чисел, которые будут записаны в файл\n");
		for (i = 0; i < n; i++)
		{
			scanf_s("%d", &keyboard);
			fprintf(file, "%d\n", keyboard);
		}
		
	}

stop:
	free(Massive);
	system("pause");
	return 0;

}
