#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX(X,Y) ((X) > (Y) ? (X) : (Y))

int main() {
    int r = 0;
    int max_c = 0;
    scanf("%d", &r);

    // 각 행에 대한 포인터 배열을 생성
    char** array = (char**)malloc(r * sizeof(char*));

    // 각 행에 대해 열의 크기만큼 동적 할당
    for (int i = 0; i < r; i++) {
        char buffer[100] = " ";
        scanf("%s", buffer);
        max_c = MAX(max_c, strlen(buffer));

        array[i] = (char*)malloc( (strlen(buffer) + 1) * sizeof(char));
        strcpy(array[i], buffer);
    }

    // 보통 행->열 순으로 2중 for문
    // 해당 문제에서는 세로로 출력해야 하기 때문에, 열을 기준으로 행을 탐색
    for (int i = 0; i < max_c; ++i) {
        for (int j = 0; j < r; ++j) {
            if (strlen(array[j]) >= i + 1) printf("%c", array[j][i]);
        }
    }

    // 메모리 해제
    for (int i = 0; i < r; i++) {
        free(array[i]);
    }
    free(array);

    return 0;
}