#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>    // rand�Լ��� ���õ� ���̺귯��
#include <time.h>    // �ð� �Լ� ����� ���� �������

#define SIZE 100    // �迭�� ũ�� 100

// �������� ���� �Լ�
void sort_Ascending(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {    // ���ʷ� ������ �� ������ ���� �̹� ���ĵ� ������ ���̹Ƿ� size - 1���� �ݺ�
        for (int j = i + 1; j < size; j++) {    // i��° ��� �ڿ� i���� ���� j���� �ִ��� Ȯ��
            if (arr[i] > arr[j]) {    // arr[i]�� arr[j]���� ũ�� �� �� ��ȯ
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

// �������� ���� �Լ�
void sort_Descending(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] < arr[j]) {    // arr[i]�� arr[j]���� ������ �� �� ��ȯ
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

// �迭 ��� �Լ�
void print_Array(int arr[], int size) {
    for (int i = 0; i < size; i++) {    // �迭�� �� ��Ҹ� ������� ���
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[SIZE];
    char choice;    // ������� ���Ĺ���� �Է¹��� ����

    //// 100���� ������ ���� (100���� 1����)
    //for (int iter = 0; iter < SIZE; iter++) {
    //    arr[iter] = SIZE - iter;
    //}

     // ���� �ð��� �������� ���� �õ� �����Ͽ� ������ �� ����
    srand(time(0));

    // 100���� ���� ������ ���� (0���� 999����)
    for (int iter = 0; iter < SIZE; iter++) {
        arr[iter] = rand() % 1000;  // 0���� 999������ ��
    }

    // ���� ��� ����
    printf("���� ����� �����ϼ��� (A: ��������, D: ��������): ");
    scanf(" %c", &choice);

    // ���� �� �迭 ���
    printf("���� �� �迭:\n");
    print_Array(arr, SIZE);

    // ���õ� ���� ��Ŀ� ���� ���� ����
    if (choice == 'A' || choice == 'a') {
        sort_Ascending(arr, SIZE);
        printf("�������� ���� �� �迭:\n");
    }
    else if (choice == 'D' || choice == 'd') {
        sort_Descending(arr, SIZE);
        printf("�������� ���� �� �迭:\n");
    }
    else {
        printf("�߸��� �����Դϴ�. ���α׷��� �����մϴ�.\n");
        return 1; // ���� �ڵ� ��ȯ
    }

    // ���� �� �迭 ���
    print_Array(arr, SIZE);

    return 0;
}
