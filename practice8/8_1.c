#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int num = 0;
char file_name[9] = "x_dan.txt";
FILE* file;

int main() {

	printf("출력하고 싶은 단을 입력 : ");
	scanf("%d", &num);

	file_name[0] = num + '0';

	file = fopen(file_name, "w+");

	for (int i = 1; i <= 9; ++i) {
		fprintf(file, "%d x %d = %d\n", num, i, num * i);
	}

	fclose(file);
	printf("%d_dan.txt에 결과를 저장", num);
	return 0;
}