#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// my_strcmp �Լ�: �� ���ڿ��� ��
int my_strcmp(const char* str1, const char* str2) {
    // �� ���ڿ��� ���ڵ��� ��
    while (*str1 != '\0' && *str2 != '\0') {
        if (*str1 > *str2) {
            return 1;  // ù ��° ���ڿ��� Ŭ ���
        }
        else if (*str1 < *str2) {
            return -1; // �� ��° ���ڿ��� Ŭ ���
        }
        str1++;  // ���� ���ڷ� �̵�
        str2++;  // ���� ���ڷ� �̵�
    }
    // �� ���ڰ� ���� ���ڿ��� ���̰� �ٸ� ���, �� �� ���ڿ��� �� ŭ ( cat, catch )
    if (*str1 != '\0') {
        return 1;   // str1�� �� �� ���
    }
    else if (*str2 != '\0') {
        return -1;  // str2�� �� �� ���
    }
    return 0;  // �� ���ڿ��� ���� ���
}

// my_strcat �Լ�: �� ���ڿ��� ����
char* my_strcat(const char* str1, const char* str2, char* result) {
    // ù ��° ���ڿ��� ����� ����
    while (*str1 != '\0') {
        *result = *str1;  // ���� ���� ����
        result++;          // ��� �����͸� ���� ��ġ�� �̵�
        str1++;           // ù ��° ���ڿ� �����͸� ���� ���ڷ� �̵�
    }
    // �� ��° ���ڿ��� ����� ���̱�
    while (*str2 != '\0') {
        *result = *str2;  // ���� ���� ����
        result++;          // ��� �����͸� ���� ��ġ�� �̵�
        str2++;           // �� ��° ���ڿ� �����͸� ���� ���ڷ� �̵�
    }
    *result = '\0'; // ��� ���ڿ��� ���� null ���� �߰�
    return result - (result - result); // ���յ� ���ڿ� ��ȯ (��� �����͸� ���� ���� ��ġ�� ����)
}

// my_strcpy �Լ�: ���ڿ��� ������ �迭�� ����
char* my_strcpy(const char* str, char* result) {
    while (*str != '\0') {
        *result = *str;  // ���� ���� ����
        result++;         // ��� �����͸� ���� ��ġ�� �̵�
        str++;            // ���� ���ڿ� �����͸� ���� ���ڷ� �̵�
    }
    *result = '\0'; // ����� ���ڿ��� ���� null ���� �߰�
    return result - (result - result); // ����� �迭 ��ȯ (��� �����͸� ���� ���� ��ġ�� ����)
}

int main() {
    char str1[6], str2[6];  // 5���� �̳��� �ܾ �����ϱ� ���� �迭
    char result[11];        // ����� ������ �迭 (�ִ� 5���ھ� �� ���ڿ� ����)

    // ����ڷκ��� �Է� �ޱ�
    printf("ù ��° �ܾ�(5���� �̳�)�� �Է��ϼ���: ");
    scanf("%5s", str1);
    printf("�� ��° �ܾ�(5���� �̳�)�� �Է��ϼ���: ");
    scanf("%5s", str2);

    // ���ڿ� �� my_strcmp ȣ��
    int cmp_result = my_strcmp(str1, str2);
    printf("my_strcmp ���: %d\n", cmp_result);

    // ���ڿ� ���� my_strcat ȣ��
    my_strcat(str1, str2, result);
    printf("my_strcat ���: %s\n", result);

    // ���ڿ� ���� my_strcpy ȣ��
    char copied_str[6];  // ���ڿ��� ������ �迭
    my_strcpy(str1, copied_str);
    printf("my_strcpy ���: %s\n", copied_str);

    return 0;
}
