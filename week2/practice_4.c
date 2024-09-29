#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// �����佺�׳׽��� ü ������� �Ҽ��� �ɷ����� �Լ�
void my_eratosthenes(int arr[], int size) {
    int a, b;  // 2���� size+1���� Ž���ϱ� ���� ���� ����
    for (a = 2; a <= size + 1; a++) {  // �迭�� ���� 2���� �����ϹǷ� a�� 2���� ����
        if (arr[a - 2] != 0) {  // �Ҽ��� ���
            // a�� ������� �迭���� 0���� ����
            for (b = a + a; b <= size + 1; b += a) {
                arr[b - 2] = 0;  // a�� ����� 0���� ��ȯ
            }
        }
    }
}

// �迭�� ���� ����ϴ� �Լ�
void print_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// �迭 �� �Ҽ��� ����ϴ� �Լ�
void print_only_primes(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        if (arr[i] != 0) {
            printf("%d ", arr[i]);  // 0�� �ƴ� ��(�Ҽ�)�� ���
        }
    }
    printf("\n");
}

int main() {
    int arr[29];  // 2���� 30���� ������ �迭
    int size = sizeof(arr) / sizeof(arr[0]);  // �迭 ũ�� ���

    // �迭�� 2~30 ������ �� ä���
    for (int i = 0; i < size; i++) {
        arr[i] = i + 2;
    }

    printf("���� �迭: ");
    print_array(arr, size);  // ���� �迭 ���

    // �����佺�׳׽��� ü�� �Ҽ��� ����� ������ 0���� ����
    my_eratosthenes(arr, size);

    printf("�Ҽ��� ������ ���� 0���� ��ȯ�� �迭: ");
    print_array(arr, size);  // 0���� ��ȯ�� �迭 ���

    printf("�Ҽ��� ���: ");
    print_only_primes(arr, size);  // �Ҽ��� ���

    return 0;
}
