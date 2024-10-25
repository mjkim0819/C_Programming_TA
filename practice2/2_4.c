#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 에라토스테네스의 체 방식으로 소수를 걸러내는 함수
void my_eratosthenes(int arr[], int size) {
    int a, b;  // 2부터 size+1까지 탐색하기 위한 변수 선언
    for (a = 2; a <= size + 1; a++) {  // 배열의 값이 2부터 시작하므로 a는 2부터 시작
        if (arr[a - 2] != 0) {  // 소수일 경우
            // a의 배수들을 배열에서 0으로 설정
            for (b = a + a; b <= size + 1; b += a) {
                arr[b - 2] = 0;  // a의 배수를 0으로 변환
            }
        }
    }
}

// 배열의 값을 출력하는 함수
void print_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// 배열 내 소수만 출력하는 함수
void print_only_primes(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        if (arr[i] != 0) {
            printf("%d ", arr[i]);  // 0이 아닌 값(소수)만 출력
        }
    }
    printf("\n");
}

int main() {
    int arr[29];  // 2부터 30까지 저장할 배열
    int size = sizeof(arr) / sizeof(arr[0]);  // 배열 크기 계산

    // 배열에 2~30 사이의 값 채우기
    for (int i = 0; i < size; i++) {
        arr[i] = i + 2;
    }

    printf("원래 배열: ");
    print_array(arr, size);  // 원래 배열 출력

    // 에라토스테네스의 체로 소수만 남기고 나머지 0으로 변경
    my_eratosthenes(arr, size);

    printf("소수를 제외한 값은 0으로 변환된 배열: ");
    print_array(arr, size);  // 0으로 변환된 배열 출력

    printf("소수만 출력: ");
    print_only_primes(arr, size);  // 소수만 출력

    return 0;
}