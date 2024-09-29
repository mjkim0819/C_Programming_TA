#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100

// ����ڷκ��� ���ڵ�� ���� ����� �Է¹޴� �Լ�
void input_char(char str[], char* sort_order) {
    printf("�ִ� %d���� ���ڸ� �Է��ϼ���: ", MAX_SIZE);
    fgets(str, MAX_SIZE, stdin);

    // ���ڿ� ���� ���๮�� ����
    str[strcspn(str, "\n")] = '\0';

    printf("���� ����� �Է��ϼ��� (��������/��������): ");
    fgets(sort_order, 11, stdin); // ����ڷκ��� ���� ��� �Է¹ޱ�
    sort_order[strcspn(sort_order, "\n")] = '\0'; // ���ڿ� ���� ���๮�� ����
}

// �Ű������� ���� ���ڿ��� ���� ����� �������� ���ڵ��� �����ϴ� �Լ�
void func_sort(char str[], char sort_order[]) {
    int len = strlen(str); // ���ڿ��� ���� ���

    for (int i = 0; i < len - 1; i++) {   // ù��° ���ں���
        for (int j = i + 1; j < len; j++) {    // �� ���Ŀ� ���� ���ڵ�� ��
            if ((strcmp(sort_order, "��������") == 0 && str[i] > str[j]) ||
                (strcmp(sort_order, "��������") == 0 && str[i] < str[j])) {
                // ���������� �����ؾ� �ϸ鼭, str[i](�տ� ���� ����)���� str[j](�ڿ� ���� ����)�� �� ū ��� swap
                // ���������� �����ؾ� �ϸ鼭, str[i](�տ� ���� ����)���� str[j](�ڿ� ���� ����)�� �� ���� ��� swap
                char temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }
}

// ���ĵ� ���ڵ��� ����ϴ� �Լ�
void func_print(char str[]) {
    printf("���ĵ� ���ڵ�: %s\n", str);
}

int main() {
    char str[MAX_SIZE];
    char sort_order[11];

    // ����� �Է� �ޱ�
    input_char(str, sort_order);

    // ���� �Լ� ȣ��
    func_sort(str, sort_order);

    // ���ĵ� ���� ���
    func_print(str);

    return 0;
}
