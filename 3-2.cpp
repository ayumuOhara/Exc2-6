//==========================================================
//	線形探索 経過表示
//==========================================================
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> // printf()
#include <stdlib.h> // srand(),rand()
#include <time.h>
// 関数プロトタイプ
int LinearSearch(const int data[], int dataSize, int key);
int getRandRange(int min, int max);

#define SEARCH_FAIL (-1)

int main()
{
	srand(time(nullptr));
	int dataSize;

	while (true) {
		printf("要素数:");
		do {
			scanf_s("%d", &dataSize);
		} while (dataSize <= 0);

		int* data = (int*)calloc(dataSize, sizeof(int));
		if (data == nullptr) {
			printf("calloc()失敗");
			exit(1);
		}
		for (int i = 0; i < dataSize; i++) {
			data[i] = getRandRange(0, 50);
			printf("data[%d]:%d\n", i, data[i]);
		}
		int key = getRandRange(0, 50);
		printf("探す値:%d\n", key);

		int idx = LinearSearch(data, dataSize, key);
		if (idx == SEARCH_FAIL) {
			puts("\n探索に失敗しました");
		}
		else {
			printf("\n%dはdata[%d]にあります\n", key, idx);
		}
		free(data);
	}
	return 0;
}

int LinearSearch(const int data[], int dataSize, int key)
{
	int i = 0;
	printf("   |");
	for (int i = 0; i < dataSize; i++)
	{
		printf("%3d", i);
	}printf("\n---+");

	int cnt = 0;

	while (cnt < 30)
	{
		printf("-");
		cnt++;
	}puts("");
	
	cnt = 0;

	while (true) {
		if (i == dataSize) {
			return SEARCH_FAIL;
		}
		if (data[i] == key) {
			return i;
		}

		printf("   |  ");
		for (int k = 0; k < i; k++)
		{
			printf("   ");
		}printf("*\n");
		printf("  %d|", i);

		for (int j = 0; j < dataSize; j++)
		{
			printf(" %2d", data[j]);
		}puts("");

		i++;
	}
}

int getRandRange(int min, int max)
{
	int wid = max - min + 1;
	return min + rand() % wid;
}