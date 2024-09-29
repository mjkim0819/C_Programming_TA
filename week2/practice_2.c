#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// �迭�� ����Ͽ� ���� ��ȯ�ϴ� �Լ�
// �迭�� ù ��°�� �� ��° ���� ��ȯ
void swap_by_array(int arr[]) {
    int temp = arr[0];
    arr[0] = arr[1];
    arr[1] = temp;
}

// �����͸� ����Ͽ� �� ���� ��ȯ�ϴ� �Լ�
// ������ ���޵� ������ ���� ��ȯ
void swap_by_pointer(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int arr[2];  // �� ���� ������ �迭 ����

    // ù ��° ��ȯ: �迭�� ���� �� ��ȯ
    printf("Before Swap: ");
    scanf("%d %d", &arr[0], &arr[1]);

    swap_by_array(arr);  // �迭�� �Ű������� ����
    printf("Swap by index: %d %d\n", arr[0], arr[1]);

    // �� ��° ��ȯ: �����͸� ����Ͽ� �� ��ȯ
    printf("\nBefore Swap: ");
    scanf("%d %d", &arr[0], &arr[1]);

    swap_by_pointer(&arr[0], &arr[1]);
    printf("Swap by pointer: %d %d\n", arr[0], arr[1]);


    return 0;
}
