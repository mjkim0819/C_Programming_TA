#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

#define ROWS 4   // 행의 개수
#define COLS 8   // 열의 개수

// 행렬을 출력하는 함수 (포인터 연산 사용)
void printMatrix(int (*matrix)[COLS]) {
    for (int i = 0; i < ROWS; i++) {           // 각 행에 대해 반복
        for (int j = 0; j < COLS; j++) {       // 각 열에 대해 반복
            printf("%d ", *(*(matrix + i) + j)); // 포인터 연산을 사용하여 현재 요소 출력  *(*(matrix + i) + j) == matrix[i][j]
        }
        printf("\n");                           // 행 출력 후 줄 바꿈
    }
}

// 행렬을 업데이트하는 함수
void updateMatrix(int (*matrix)[COLS]) {
    for (int i = 1; i < ROWS; i++) {           // 두 번째 행부터 시작
        for (int j = 0; j < COLS; j += 2 * i) { // j를 증가시키며 짝수 인덱스 접근 ( 두 번째 행은 2개씩 건너뛰고, 세 번째 행은 4개씩 건너뛰고, 네 번째 행은 8개씩 건너뛰기)
            if (j < COLS - 1) {                // 마지막 열을 초과하지 않도록 확인
                // 이전 행의 두 요소의 합으로 현재 요소 설정
                matrix[i][j] = *(*(matrix + i - 1) + j) + *(*(matrix + i - 1) + j + (int)pow(2, (i - 1)));
                // *(*(matrix + i - 1) + j) == matrix[i-1][j]
                // pow (2, (i - 1))은 2의 (i - 1) 제곱을 의미
                // 두번째 행은 1개 뒤(2^0 = 1)랑 더하고, 세번째 행은 2개 뒤(2^1 = 2)랑 더하고, 네번째 행은 4개 뒤(2^2=4)랑 더하기 

            }
            else {
                // 마지막 열에서는 이전 행의 값 그대로 설정
                matrix[i][j] = *(*(matrix + i - 1) + j);    // *(*(matrix + i - 1) + j) == matrix[i-1][j]
            }
        }

    }
}

int main() {
    int matrix[ROWS][COLS] = { 0 };  // 초기화된 2차원 행렬

    // 첫 번째 행 입력
    printf("0이 아닌 양수 8개를 입력하세요: ");
    for (int j = 0; j < COLS; j++) {
        int input;
        scanf("%d", &input); // 사용자 입력 받기
        if (input <= 0) {
            printf("양수를 입력해야 합니다.\n");
            return 1; // 오류 발생 시 종료
        }
        matrix[0][j] = input; // 입력된 값을 첫 번째 행에 저장
    }

    // 행렬 업데이트
    updateMatrix(matrix);

    // 결과 출력
    printf("최종 행렬:\n");
    printMatrix(matrix);

    // 최종 합산된 수 출력
    int finalSum = 0; // 합계를 저장할 변수
    for (int j = 0; j < COLS; j++) {
        finalSum += *(*(matrix + ROWS - 1) + j); // 마지막 행의 모든 요소를 합산
    }
    printf("최종 합산된 수: %d\n", finalSum);

    return 0; // 프로그램 종료
}
