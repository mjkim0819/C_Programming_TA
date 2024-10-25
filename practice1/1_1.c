#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// Call by Value 방식으로 두 값을 교환하는 함수
// 값만 복사되어 전달되므로 원본 값은 바뀌지 않음
void swap_by_value(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
    printf("After value swap(in function), A : %d, B : %d\n", a, b);
}

// Call by Reference(포인터) 방식으로 두 값을 교환하는 함수
// 포인터를 사용해 실제 변수의 주소를 전달하므로 원본 값이 변경됨
void swap_by_pointer(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
    printf("After value swap(in function), A : %d, B : %d\n", *a, *b);
}

int main() {
    int a, b;

    // 사용자로부터 교환할 값 입력 받기
    printf("Before swap, A : ");
    scanf("%d", &a);
    printf("B : ");
    scanf("%d", &b);

    // 매개변수로 변수를 전달 받아 교환
    swap_by_value(a, b);
    printf("After value swap(in main), A : %d, B : %d\n\n\n", a, b);

    // 포인터로 변수를 전달 받아 교환
    swap_by_pointer(&a, &b);
    printf("Reference value swap(in main), A : %d, B : %d\n", a, b);

    return 0;
}