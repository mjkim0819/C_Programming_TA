#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int my_strcmp(char x1[], char x2[]) {
	for (int i = 0; i < _msize(x1) - 1; ++i) {
		// 이미 같으면 pass
		if (x1[i] == x2[i]) continue;
		else if (x1[i] + 32 == x2[i] || x1[i] - 32 == x2[i]) continue; // x2를 기준으로 두고 x1를 대문자 / 소문자로 바꿔서 비교
		else if (x1[i] == x2[i] + 32 || x1[i] == x2[i] - 32) continue; // x1를 기준으로 두고 x2를 대문자 / 소문자로 바꿔서 비교
		else return 0;
	}
	return 1;
}

int main() {
	char buffer[100] = " ";
	char *x1 = NULL;
	char *x2 = NULL;

	scanf("%s", buffer);
	x1 = (char*)malloc(sizeof(char) * (strlen(buffer) + 1));
	strcpy(x1, buffer);

	scanf("%s", buffer);
	x2 = (char*)malloc(sizeof(char) * (strlen(buffer) + 1));
	strcpy(x2, buffer);

	if (my_strcmp(x1, x2)) printf("True");
	else printf("False");

	free(x1);
	free(x2);

	return 0;
}