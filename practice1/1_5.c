#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>    // rand함수와 관련된 라이브러리
#include <time.h>    // 시간 함수 사용을 위한 헤더파일

#define SIZE 100    // 배열의 크기 100

// 오름차순 정렬 함수
void sort_Ascending(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {    // 차례로 정렬할 때 마지막 값은 이미 정렬된 상태일 것이므로 size - 1까지 반복
        for (int j = i + 1; j < size; j++) {    // i번째 요소 뒤에 i보다 작은 j값이 있는지 확인
            if (arr[i] > arr[j]) {    // arr[i]가 arr[j]보다 크면 두 값 교환
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

// 내림차순 정렬 함수
void sort_Descending(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] < arr[j]) {    // arr[i]가 arr[j]보다 작으면 두 값 교환
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

// 배열 출력 함수
void print_Array(int arr[], int size) {
    for (int i = 0; i < size; i++) {    // 배열의 각 요소를 순서대로 출력
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[SIZE];
    char choice;    // 사용자의 정렬방식을 입력받을 변수

    //// 100개의 정수값 생성 (100부터 1까지)
    //for (int iter = 0; iter < SIZE; iter++) {
    //    arr[iter] = SIZE - iter;
    //}

     // 현재 시간을 기준으로 랜덤 시드 설정하여 랜덤한 값 생성
    srand(time(0));

    // 100개의 랜덤 정수값 생성 (0부터 999까지)
    for (int iter = 0; iter < SIZE; iter++) {
        arr[iter] = rand() % 1000;  // 0부터 999까지의 값
    }

    // 정렬 방식 선택
    printf("정렬 방식을 선택하세요 (A: 오름차순, D: 내림차순): ");
    scanf(" %c", &choice);

    // 정렬 전 배열 출력
    printf("정렬 전 배열:\n");
    print_Array(arr, SIZE);

    // 선택된 정렬 방식에 따라 정렬 수행
    if (choice == 'A' || choice == 'a') {
        sort_Ascending(arr, SIZE);
        printf("오름차순 정렬 후 배열:\n");
    }
    else if (choice == 'D' || choice == 'd') {
        sort_Descending(arr, SIZE);
        printf("내림차순 정렬 후 배열:\n");
    }
    else {
        printf("잘못된 선택입니다. 프로그램을 종료합니다.\n");
        return 1; // 오류 코드 반환
    }

    // 정렬 후 배열 출력
    print_Array(arr, SIZE);

    return 0;
}