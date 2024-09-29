#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// ���� ������ ������ ����
const double PI = 3.14;  // �ε��Ҽ������� ���� �߻��ϴ� ������ �ذ��ϱ� ���� double���� ���
// ��ǻ�ʹ� �������� ����ϱ� ������ �Ҽ��� ǥ���ϰ� �����ϴµ� ������� ����
// �Ҽ��� ��Ȯ�� ���� �ƴ϶� �ٻ�ġ�� ǥ���ϴµ� �� �������� ������ �߻�
// float(7�ڸ� ��ȿ����)���� double(15~16�ڸ� ��ȿ����)�� �� ��Ȯ�ϰ� ǥ�� ���� 

// ���� ���̸� ���ϴ� �Լ�
double calculate_area(double radius) {
    return PI * radius * radius;
}

// ���� �ѷ��� ���ϴ� �Լ�
double calculate_circumference(double radius) {
    return 2 * PI * radius;
}

int main() {
    double radius, area, circumference;  // float ��� double ���

    // ����ڷκ��� ������ �Է� �ޱ�
    printf("����/�ѷ��� ���� ���� �������� �Է��Ͻÿ� : ");
    scanf("%lf", &radius);  // double �Է� �ޱ� ���� %lf

    // ���̿� �ѷ� ���
    area = calculate_area(radius);
    circumference = calculate_circumference(radius);

    // ��� ���
    printf("�Է��� ������ : %.0f �� ����\n", radius); //�Ǽ��� ���������� ����ϱ� ���� %.0f ���
    printf("���� ���̴� %.6f\n", area);
    printf("���� �ѷ��� %.6f\n", circumference);  //�Ҽ��� 6�ڸ����� ����ϱ� ���� %.6f ���

    return 0;
}
