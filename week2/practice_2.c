#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 배열을 사용하여 값을 교환하는 함수
// 배열의 첫 번째와 두 번째 값을 교환
void swap_by_array(int arr[]) {
    int temp = arr[0];
    arr[0] = arr[1];
    arr[1] = temp;
}

// 포인터를 사용하여 두 값을 교환하는 함수
// 실제로 전달된 변수의 값을 교환
void swap_by_pointer(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int arr[2];  // 두 값을 저장할 배열 선언

    // 첫 번째 교환: 배열을 통해 값 교환
    printf("Before Swap: ");
    scanf("%d %d", &arr[0], &arr[1]);

    swap_by_array(arr);  // 배열을 매개변수로 받음
    printf("Swap by index: %d %d\n", arr[0], arr[1]);

    // 두 번째 교환: 포인터를 사용하여 값 교환
    printf("\nBefore Swap: ");
    scanf("%d %d", &arr[0], &arr[1]);

    swap_by_pointer(&arr[0], &arr[1]);
    printf("Swap by pointer: %d %d\n", arr[0], arr[1]);


    return 0;
}
