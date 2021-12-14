#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Russian");

	FILE* file = fopen("..\\massive.txt", "w");

	int menu, n, x, y, z, count; // xzy - побочные
	int i;
	unsigned int min, max, keyboard;
	unsigned int* Massive = 0;
	unsigned int* Mass = 0;
	char * fpath;
	char * str;

	if (file == 0) goto err;
	
	printf("Внимание! В этой программе допускается ввод только целых чисел, начиная с нуля, согласно диапазону unsigned int!\n");
	printf("Добрый день! Это главное меню программы. Как вы хотите осуществить ввод чисел?\n");
	printf("1. Сгенерировать случайные числа\n");
	printf("2. Выполнить ввод чисел вручную\n");
	printf("3. Осуществить открытие файла и перезапись данных из него в новый текстовый файл.\n");
	scanf("%d", &menu);

	if (menu == 1)
	{
		printf("Для генерации чисел необходимо выбрать минимальную и максимальную границы, а также количество генерируемых чисел\n");
		printf("Пожалуйста, введите минимальную границу\n");
		scanf("%d", &min);
		if (min < 0) goto err;
		printf("Пожалуйста, введите максимальную границу (максимальная граница должна быть больше минимальной!)\n");
		scanf("%d", &max);
		if (max >= 4294967295)
		if (max < min) goto err;
		printf("Пожалуйста, введите количество генерируемых чисел\n");
		scanf("%d", &n);
		if (n < 0) goto err;
		system("cls");

		printf("Генерация чисел начинается. Процесс работы будет выводится на экран.");
		Sleep(5000);
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

		if (x == 1) // GEN
		{
			for (i = 0; i < n; i++)
			{
				fprintf(file, "%d\n", Massive[i]);
			}
			if (file != 0)
			{
				printf("Запись произошла успешно!\n");
				goto stop;
			}
			else
			{
				goto err;
			}
		}
		if (x == 2)
		{
			goto stop;
		}
		else
		{
			goto err;
		}

	}
	if (menu == 2) // KLAVA
	{
		
        printf("Пожалуйста, введите количество чисел, которое вы собираетесь ввести\n");
		scanf("%d", &n);
		if (n < 0) goto err;
		printf("Осуществите ввод чисел, которые будут записаны в файл\n");
		for (i = 0; i < n; i++)
		{
			scanf_s("%d", &keyboard);
			fprintf(file, "%d\n", keyboard);
		}
		printf("Запись прошла успешно!\n");
		goto stop;
	}
	if (menu == 3) // CHTENIE
	{
		printf("Для открытия необходимого файла, поместите его в корневую папку программы и назовите его 'input.txt'\n");
		//scanf_s(" %c", &fpath);
		system("pause");
		fpath = 0;
		FILE* file1 = fopen("..\\input.txt", "r");
		if (file1 == 0) goto err;
		printf("Запись в файл 'massive.txt' началась!\n");
		Sleep(1000);

		while (!feof(file1))
		{
			count = fread(&str, sizeof(char), 1, file1);
			if (count != 0)
				fwrite(&str, sizeof(char), 1, file);
		}

		if (file != 0)
		{
			system("cls");
			printf("Запись прошла успешно!\n");
		}
		else
		{
			goto err;
		}
		
	}
	else
	{
	err:
		system("cls");
		printf("Произошла неизвестная ошибка! Закрытие программы...\n");
		Sleep(1000);
		goto stop;
	}

stop:
	fclose(file);
	free(Massive);
	system("pause");
	return 0;
}
