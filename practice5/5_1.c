#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
	// 본 풀이는 원래 문자열 -> 소문자 -> 대문자 순으로 출력함
	char buffer[100] = " ";
	char *input = NULL;
	int len = 0;

	scanf("%s", buffer);

	len = strlen(buffer) + 1;

	input = (char*)malloc(sizeof(char) * len);
	
	for (int i = 0; i < len; ++i) {
		if (buffer[i] >= 'A' && buffer[i] <= 'Z') {
			input[i] = buffer[i] + 32;
		}
		else {
			input[i] = buffer[i];
		}
	}
	printf("%s\n", input);

	for (int i = 0; i < len; ++i) {
		if (buffer[i] >= 'a' && buffer[i] <= 'z') {
			input[i] = buffer[i] - 32;
		}
		else {
			input[i] = buffer[i];
		}
	}
	printf("%s\n", input);

	free(input);

	return 0;
}