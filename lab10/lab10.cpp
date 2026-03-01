#include <iostream>
#include <stdlib.h>
#include <ctime>

using namespace std;
void packData(short* source, int N, int* packed) // Задание 2(А). Упаковка.
{
	short* end = source + N;

	for (short* ptr = source; ptr < end; ptr++)
	{
		int value = *ptr;

		(*(packed + value))++;
	}
}

void unpackData(int* packed, short* unpacked) // Задание 2(Б). Распаковка.
{
	short* ptr = unpacked;
	for (short value = 0; value <= 17; value++)
	{
		int count = *(packed + value);

		for (int i = 0; i < count; i++)
		{
			*ptr = value;
			ptr++;
		}
	}
}
int main()
{
	int N;
	cout << "Введите длину исходного массива (более 1000): " << endl;
	cin >> N;

	int packed[18] = { 0 };
	short source[N] = { 0 };
	short unpacked[N] = { 0 };
	// Создаем рандомный исходный массив

	srand(time(NULL));
	int randomCounts[18] = { 0 };

	for (int i = 0; i < N; i++)
	{
		short randomValue = rand() % 17;
		randomCounts[randomValue]++;
	}

	short* fillPtr = source;
	for (int value = 0; value < 18; value++)
	{
		for (int c = 0; c < randomCounts[value]; c++)
		{
			*fillPtr = value;
			fillPtr++;
		}
	}
	
	packData(source, N, packed);
	unpackData(packed, unpacked);

	cout << packed << endl;
	cout << unpacked << endl;
}