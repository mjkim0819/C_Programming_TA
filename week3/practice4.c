#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <math.h> // ceil �Լ� ����� ���� ���

bool rooms[8] = { false };  // ȣ�� ���� ���� (false: ���� ����, true: ���� �Ұ�)

// VIP�� ���� Ȯ�� �Լ�
int vip_check(int people) {
    int rooms_needed = (int)ceil((double)people / 4);  // �ʿ��� VIP�� ��
    int count = 0;  // ����� VIP�� ��
    int allocated_rooms[3] = { 0 };  // ����� �� ��ȣ ����

    for (int i = 0; i < 3; i++) {
        if (!rooms[i]) {  // ���� ���� ���� Ȯ��
            rooms[i] = true;  // ���� ���� ����
            allocated_rooms[count] = 301 + i;  // ����� �� ��ȣ ����
            count++;  // ����� VIP�� �� ����
            if (count == rooms_needed) {
                printf("������ �Ϸ�Ǿ����ϴ�. �� ��ȣ: ");
                for (int j = 0; j < count; j++) {
                    printf("%d ", allocated_rooms[j]);
                }
                printf("\n");
                return count;  // VIP�� ���� �Ϸ�
            }
        }
    }

    // ���� ���������� ���� �ο��� ��� ������� �ʴ� ���
    if (count > 0) {
        printf("������ �Ϸ�Ǿ����ϴ�. �� ��ȣ: ");
        for (int j = 0; j < count; j++) {
            printf("%d ", allocated_rooms[j]);
        }
        printf("\n");
        printf("%d���� ������ �� �����ϴ�.\n", people - (count * 4));  // ������� ���� �ο� ��
    }

    return count > 0 ? count : 0;  // �߰��� ������ �Ұ����� ���, �ߺ� �޽��� ����
}

// �Ϲݷ� ���� Ȯ�� �Լ�
int normal_check(int people) {
    int rooms_needed = (int)ceil((double)people / 2);  // �ʿ��� �Ϲݷ� ��
    int count = 0;  // ����� �Ϲݷ� ��
    int allocated_rooms[5] = { 0 };  // ����� �� ��ȣ ����

    for (int i = 3; i < 8; i++) {
        if (!rooms[i]) {  // ���� ���� ���� Ȯ��
            rooms[i] = true;  // ���� ���� ����
            allocated_rooms[count] = 201 + (i - 3);  // ����� �� ��ȣ ����
            count++;  // ����� �Ϲݷ� �� ����
            if (count == rooms_needed) {
                printf("������ �Ϸ�Ǿ����ϴ�. �� ��ȣ: ");
                for (int j = 0; j < count; j++) {
                    printf("%d ", allocated_rooms[j]);
                }
                printf("\n");
                return count;  // �Ϲݷ� ���� �Ϸ�
            }
        }
    }

    // ���� ���������� ���� �ο��� ��� ������� �ʴ� ���
    if (count > 0) {
        printf("������ �Ϸ�Ǿ����ϴ�. �� ��ȣ: ");
        for (int j = 0; j < count; j++) {
            printf("%d ", allocated_rooms[j]);
        }
        printf("\n");
        printf("%d���� ������ �� �����ϴ�.\n", people - (count * 2));  // ������� ���� �ο� ��
    }

    return count > 0 ? count : 0;  // �߰��� ������ �Ұ����� ���, �ߺ� �޽��� ����
}

// ȣ�� ���� �Լ�
int reservation_hotel(int people, int room_type) {
    if (room_type == 1) {  // VIP�� ����
        return vip_check(people);
    }
    else {  // �Ϲݷ� ����
        return normal_check(people);
    }
}

int main() {
    int people, room_type;

    // 5���� ���� ��û �ޱ�
    for (int i = 0; i < 5; i++) {
        printf("���� �ο��� �Է��ϼ��� : ");
        scanf("%d", &people);

        if (people <= 0) {
            printf("0�� ���Ϸ� ������ �� �����ϴ�.\n");
            i--;  // ��ȿ�� �Է��� ���� ������ �ݺ�
            continue;
        }

        printf("�� Ÿ���� �����ϼ��� (1: VIP��, 2: �Ϲݷ�): ");
        scanf("%d", &room_type);

        if (room_type < 1 || room_type > 2) {
            printf("1 �Ǵ� 2�� �Է��ϼ���.\n");
            i--;  // ��ȿ�� �Է��� ���� ������ �ݺ�
            continue;
        }

        int reserved_rooms = reservation_hotel(people, room_type);
        if (reserved_rooms == 0 && people > 0) {
            printf("������ �Ұ����մϴ�.\n");
        }
    }

    // ���� ���� ��Ȳ ���
    printf("\n���� ���� ��Ȳ:\n");
    for (int i = 0; i < 8; i++) {
        if (rooms[i]) {
            printf("%dȣ: ���� �Ϸ�\n", (i < 3 ? 301 + i : 201 + (i - 3)));
        }
        else {
            printf("%dȣ: ���� ����\n", (i < 3 ? 301 + i : 201 + (i - 3)));
        }
    }

    return 0;
}
