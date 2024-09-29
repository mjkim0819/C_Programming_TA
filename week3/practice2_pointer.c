#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

#define ROWS 4   // ���� ����
#define COLS 8   // ���� ����

// ����� ����ϴ� �Լ� (������ ���� ���)
void printMatrix(int (*matrix)[COLS]) {
    for (int i = 0; i < ROWS; i++) {           // �� �࿡ ���� �ݺ�
        for (int j = 0; j < COLS; j++) {       // �� ���� ���� �ݺ�
            printf("%d ", *(*(matrix + i) + j)); // ������ ������ ����Ͽ� ���� ��� ���  *(*(matrix + i) + j) == matrix[i][j]
        }
        printf("\n");                           // �� ��� �� �� �ٲ�
    }
}

// ����� ������Ʈ�ϴ� �Լ�
void updateMatrix(int (*matrix)[COLS]) {
    for (int i = 1; i < ROWS; i++) {           // �� ��° ����� ����
        for (int j = 0; j < COLS; j += 2 * i) { // j�� ������Ű�� ¦�� �ε��� ���� ( �� ��° ���� 2���� �ǳʶٰ�, �� ��° ���� 4���� �ǳʶٰ�, �� ��° ���� 8���� �ǳʶٱ�)
            if (j < COLS - 1) {                // ������ ���� �ʰ����� �ʵ��� Ȯ��
                // ���� ���� �� ����� ������ ���� ��� ����
                matrix[i][j] = *(*(matrix + i - 1) + j) + *(*(matrix + i - 1) + j + (int)pow(2, (i - 1)));
                // *(*(matrix + i - 1) + j) == matrix[i-1][j]
                // pow (2, (i - 1))�� 2�� (i - 1) ������ �ǹ�
                // �ι�° ���� 1�� ��(2^0 = 1)�� ���ϰ�, ����° ���� 2�� ��(2^1 = 2)�� ���ϰ�, �׹�° ���� 4�� ��(2^2=4)�� ���ϱ� 

            }
            else {
                // ������ �������� ���� ���� �� �״�� ����
                matrix[i][j] = *(*(matrix + i - 1) + j);    // *(*(matrix + i - 1) + j) == matrix[i-1][j]
            }
        }

    }
}

int main() {
    int matrix[ROWS][COLS] = { 0 };  // �ʱ�ȭ�� 2���� ���

    // ù ��° �� �Է�
    printf("0�� �ƴ� ��� 8���� �Է��ϼ���: ");
    for (int j = 0; j < COLS; j++) {
        int input;
        scanf("%d", &input); // ����� �Է� �ޱ�
        if (input <= 0) {
            printf("����� �Է��ؾ� �մϴ�.\n");
            return 1; // ���� �߻� �� ����
        }
        matrix[0][j] = input; // �Էµ� ���� ù ��° �࿡ ����
    }

    // ��� ������Ʈ
    updateMatrix(matrix);

    // ��� ���
    printf("���� ���:\n");
    printMatrix(matrix);

    // ���� �ջ�� �� ���
    int finalSum = 0; // �հ踦 ������ ����
    for (int j = 0; j < COLS; j++) {
        finalSum += *(*(matrix + ROWS - 1) + j); // ������ ���� ��� ��Ҹ� �ջ�
    }
    printf("���� �ջ�� ��: %d\n", finalSum);

    return 0; // ���α׷� ����
}
