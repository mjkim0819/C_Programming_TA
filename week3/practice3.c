#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// ��ǥ ��� ��� �Լ�
void print_plane(int x, int y) {
    // y���� ������ �Ʒ��� ��� (-2, -1, 1, 2)
    for (int i = 2; i >= -2; i--) { // y��ǥ
        // x���� ���ʿ��� ���������� ��� (-2, -1, 1, 2)
        for (int j = -2; j <= 2; j++) { // x��ǥ
            // i �Ǵ� j�� 0�̸� ��� ����
            if (i == 0 || j == 0) {
                continue;
            }
            else if (i == y && j == x) {
                printf("X "); // �Էµ� ��ǥ�� 'X' ǥ��
            }
            else {
                printf("O "); // ������ �κп� 'O' ǥ��
            }
        }
        if (i == 0) {
            continue; // i=0�� ���� �� �ٲ� ����
        }
        else {
            printf("\n"); // �ٸ� ���� �� �ٲ�
        }
    }
}

// X�� ��Ī ��ȯ �Լ�
void reflect_x(int* y) {
    *y = -(*y); // y��ǥ�� ����
}

// Y�� ��Ī ��ȯ �Լ�
void reflect_y(int* x) {
    *x = -(*x); // x��ǥ�� ����
}

// ���� ��Ī ��ȯ �Լ�
void reflect_origin(int* x, int* y) {
    *x = -(*x); // x��ǥ ����
    *y = -(*y); // y��ǥ ����
}

int main() {
    int x, y;
    int original_x, original_y;

    // ����ڷκ��� ��ǥ �Է� �ޱ�
    printf("x��ǥ�� y��ǥ�� �Է��ϼ��� (-2, -1, 1, 2): ");
    scanf("%d %d", &x, &y);

    // �Էµ� ��ǥ�� ��ȿ���� Ȯ��
    while (x != -2 && x != -1 && x != 1 && x != 2) {
        printf("��ȿ���� ���� x��ǥ�Դϴ�. (-2, -1, 1, 2) �� �ϳ��� �Է��ϼ���: ");
        scanf("%d", &x);
    }
    while (y != -2 && y != -1 && y != 1 && y != 2) {
        printf("��ȿ���� ���� y��ǥ�Դϴ�. (-2, -1, 1, 2) �� �ϳ��� �Է��ϼ���: ");
        scanf("%d", &y);
    }

    original_x = x;  // ���� x��ǥ ���� (�����ʹ� ���� �ƿ� �ٲ�� ������ original_x�� ���ٸ� x�� ��Ī�� ���� �ٽ� y�� ��Ī�ϰ�, �ٽ� ���� ��Ī��)
    original_y = y;  // ���� y��ǥ ����

    // �Է� ��ǥ ��� ���
    printf("�Է��� ��ǥ ���:\n");
    print_plane(original_x, original_y);

    // X�� ��Ī ��� ���
    reflect_x(&y);
    printf("X�� ��Ī ���:\n");
    print_plane(original_x, y);

    // Y�� ��Ī ��� ���
    reflect_y(&x);
    printf("Y�� ��Ī ���:\n");
    print_plane(x, original_y);

    // ���� ��Ī ��� ���
    reflect_origin(&original_x, &original_y);
    printf("���� ��Ī ���:\n");
    print_plane(original_x, original_y);

    return 0;
}
