#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>
#include <locale.h>
#include <malloc.h>
#include <time.h>
#include <stdbool.h>
#include <math.h>


void quickSort(int *numbers, int left, int right)
{
	
	int i, j;
	int tmp, pivot;
	i = left;
	j = right;
	pivot = numbers[(left + (right - left) / 2)];

	

	do {
		while (numbers[i] < pivot) {
			i++;
		}
		while (numbers[j] > pivot) {
			j--;
		}
		if (i <= j) {
			if (numbers[i] > numbers[j]) {
				tmp = numbers[i];
				numbers[i] = numbers[j];
				numbers[j] = tmp;
			}
			i++;
			if (j > 0) {
				j--;
			}
		}
	} while (i <= j);

	if (i < right) {
		quickSort(numbers, i, right);
	}
	if (j > left) {
		quickSort(numbers, left, j);
	}

}

void norma1(unsigned int* numbers, int size)
{
	int i = 0, kol = 0;

	for (i = 0; i < size; i++)
	{
		kol += numbers[i];
	}
	printf("Первая норма вектора = %d\n", kol);
}

void norma2(unsigned int* numbers, int size) 
{
	int i = 0, kol = 0;

	for (i = 0; i < size; i++)
	{
		kol += pow(numbers[i], 2);
	}
	kol = sqrt(kol);
	printf("Вторая норма вектора = %d\n", kol);
}

void normaInfinity(unsigned int* numbers, int size)
{
	int i = 0, last = 0;

	for (i = 0; i < size; i++)
	{
		if (last < numbers[i])
		{
			last = numbers[i];
		}
	}
	printf("Бесконечная норма вектора = %d\n", last);
}

void normir(unsigned int* numbers, int size)
{
	int i = 0;
	double k = 0, x = 0;

	for (i = 0; i < size; i++)
	{
		x += pow(numbers[i], 2);
	}

	x = sqrt(x);
	x = round(x);

	printf("Результат нормировки:\n");
	Sleep(2000);

	for (i = 0; i < size; i++)
	{
		k = numbers[i] / x;
		printf("%lf\n", k);
	}
}


int main()
{
menu:
	setlocale(LC_ALL, "Russian");

    clock_t fTimeStart1, fTimeStop1;
	clock_t fTimeStart2, fTimeStop2;
	clock_t fTimeStart3, fTimeStop3;

	int m, m2, m3, i, j, N, y, k, x;
	char q, s;
	FILE* file = 0;
	unsigned char * fdata;
	unsigned int * mass = 0;
	unsigned int * mass2 = 0;
	N = 0;
	x = 0;
	  
    
    printf("Меню программы:\n");
	printf("1. Вывести данные из файла на экран\n");
	printf("2. Перейти в меню сортировок\n");
	printf("3. Сброс\n");
	printf("4. Перейти в меню норм векторов\n");
	printf("5. Выход\n");
	scanf("%d", &m);
	system("cls");
	
	// Блок, в котором происходит перевод данных из файла в массив, а также подсчёт колличества элементов
	
	
	
	fopen_s(&file, "..//massive.txt", "r");
	while (!feof(file))
	{
		if (fgetc(file) == '\n') N++;
	}
	fclose(file);

	mass = (unsigned int*)malloc(N * sizeof(unsigned int));
	mass2 = (unsigned int*)malloc(N * sizeof(unsigned int));

	for (i = 0; i < N; i++)
	{
		mass[i] = 0;
	}

	fopen_s(&file, "..//massive.txt", "r");
	for (i = 0; i < N; i++)
	{
		fscanf_s(file, "%d\n", &(mass[i]));
	}
	fclose(file);
	
	
	// Блок, в котором происходят действия, исходя из выбора в меню
	
	if (m == 5) goto stop;
	if (m == 1)
	{
		fopen_s(&file, "..//massive.txt", "r");
		while ((q = fgetc(file)) != EOF) 
		{
			putchar(q);
		}
		fclose(file);
		printf("Вывод произошёл успешно!\n");
		goto menu;
	}
	if (m == 2)
	{
		printf("Это меню сортировок. Выберете нужный вам вид сортировки:\n");
		printf("1. Пузырьком\n");
		printf("2. Вставкой\n");
		printf("3. Быстрая\n");
		scanf("%d", &m2);
		if (m2 == 1)
		{
			fTimeStart2 = clock() * 1000 / CLOCKS_PER_SEC;

			int tmp;
			bool noSwap;

			for (int i = N - 1; i >= 0; i--)
			{
				noSwap = 1;
				for (int j = 0; j < i; j++)
				{
					if (mass[j] > mass[j + 1])
					{
						tmp = mass[j];
						mass[j] = mass[j + 1];
						mass[j + 1] = tmp;
						noSwap = 0;
					}
				}
				if (noSwap == 1)
					break;
			
			}

			fTimeStop2 = clock() * 1000 / CLOCKS_PER_SEC;
			FILE* ftime = fopen("..\\ftime.txt", "w");
			fprintf(ftime, "Bubble sort: %i(ms)", fTimeStop2 - fTimeStart2);
			fclose(ftime);

			printf("Результат обработки:\n");
			Sleep(3000);
			for (i = 0; i < N; i++)
			{
				printf("Число [%d] = %d\n", i, mass[i]);
			}
			
			goto menu;
		}
		if (m2 == 2) 
		{
			int newElement, location;

			fTimeStart3 = clock() * 1000 / CLOCKS_PER_SEC;

			for (int i = 1; i < N; i++)
			{
				newElement = mass[i];
				location = i - 1;
				while (location >= 0 && mass[location] > newElement)
				{
					mass[location + 1] = mass[location];
					location = location - 1;
				}
				mass[location + 1] = newElement;
			}

			fTimeStop3 = clock() * 1000 / CLOCKS_PER_SEC;
			FILE* ftime = fopen("..\\ftime.txt", "w");
			fprintf(ftime, "Insert sort: %i(ms)", fTimeStop3 - fTimeStart3);
			fclose(ftime);

			printf("Результат обработки:\n");
			Sleep(3000);
			for (i = 0; i < N; i++)
			{
				printf("Число [%d] = %d\n", i, mass[i]);
			}
			
			goto menu;
		}
		if (m2 == 3)
		{
			fTimeStart1 = clock() * 1000 / CLOCKS_PER_SEC;

			quickSort(mass, 0, N - 1);

			fTimeStop1 = clock() * 1000 / CLOCKS_PER_SEC;
			FILE* ftime1 = fopen("..\\ftime.txt", "w");
			fprintf(ftime1, "Quick sort: %i(ms)", fTimeStop1 - fTimeStart1);
			fclose(ftime1);

			printf("Результат обработки:\n");
			Sleep(3000);
			for (i = 0; i < N; i++)
			{
				printf("Число [%d] = %d\n", i, mass[i]);
			}
			
			goto menu;
		}

	
		
	}
	if (m == 3)
	{
		memcpy(mass, mass2, sizeof(unsigned int) * N);
		goto menu;
	}
	if (m == 4)
	{
		printf("1. Вычислить первую норму вектора\n");
		printf("2. Вычислить вторую норму вектора\n");
		printf("3. Вычислить бесконечную норму вектора\n");
		printf("4. Вычислить нормировку вектора\n");
		
		scanf_s("%d", &m3);

		if (m3 < 1 || m3 > 4)
		{
			goto err;
		}
		
		if (m3 == 1) norma1(mass, N); 
		if (m3 == 2) norma2(mass, N); 
		if (m3 == 3) normaInfinity(mass, N); 
		if (m3 == 4) normir(mass, N); 
		
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
	free(mass);
	free(mass2);
	system("pause");
	return 0;
}
