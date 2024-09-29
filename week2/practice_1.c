#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// Call by Value ������� �� ���� ��ȯ�ϴ� �Լ�
// ���� ����Ǿ� ���޵ǹǷ� ���� ���� �ٲ��� ����
void swap_by_value(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
    printf("After value swap(in function), A : %d, B : %d\n", a, b);
}

// Call by Reference(������) ������� �� ���� ��ȯ�ϴ� �Լ�
// �����͸� ����� ���� ������ �ּҸ� �����ϹǷ� ���� ���� �����
void swap_by_pointer(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
    printf("After value swap(in function), A : %d, B : %d\n", *a, *b);
}

int main() {
    int a, b;

    // ����ڷκ��� ��ȯ�� �� �Է� �ޱ�
    printf("Before swap, A : ");
    scanf("%d", &a);
    printf("B : ");
    scanf("%d", &b);

    // �Ű������� ������ ���� �޾� ��ȯ
    swap_by_value(a, b);
    printf("After value swap(in main), A : %d, B : %d\n\n\n", a, b);

    // �����ͷ� ������ ���� �޾� ��ȯ
    swap_by_pointer(&a, &b);
    printf("Reference value swap(in main), A : %d, B : %d\n", a, b);

    return 0;
}
