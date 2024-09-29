#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <math.h> // ceil 함수 사용을 위한 헤더

bool rooms[8] = { false };  // 호텔 객실 상태 (false: 예약 가능, true: 예약 불가)

// VIP룸 예약 확인 함수
int vip_check(int people) {
    int rooms_needed = (int)ceil((double)people / 4);  // 필요한 VIP룸 수
    int count = 0;  // 예약된 VIP룸 수
    int allocated_rooms[3] = { 0 };  // 예약된 방 번호 저장

    for (int i = 0; i < 3; i++) {
        if (!rooms[i]) {  // 예약 가능 여부 확인
            rooms[i] = true;  // 예약 상태 변경
            allocated_rooms[count] = 301 + i;  // 예약된 방 번호 저장
            count++;  // 예약된 VIP룸 수 증가
            if (count == rooms_needed) {
                printf("예약이 완료되었습니다. 방 번호: ");
                for (int j = 0; j < count; j++) {
                    printf("%d ", allocated_rooms[j]);
                }
                printf("\n");
                return count;  // VIP룸 예약 완료
            }
        }
    }

    // 방이 남아있으나 예약 인원이 모두 수용되지 않는 경우
    if (count > 0) {
        printf("예약이 완료되었습니다. 방 번호: ");
        for (int j = 0; j < count; j++) {
            printf("%d ", allocated_rooms[j]);
        }
        printf("\n");
        printf("%d명은 예약할 수 없습니다.\n", people - (count * 4));  // 예약되지 못한 인원 수
    }

    return count > 0 ? count : 0;  // 추가로 예약이 불가능한 경우, 중복 메시지 방지
}

// 일반룸 예약 확인 함수
int normal_check(int people) {
    int rooms_needed = (int)ceil((double)people / 2);  // 필요한 일반룸 수
    int count = 0;  // 예약된 일반룸 수
    int allocated_rooms[5] = { 0 };  // 예약된 방 번호 저장

    for (int i = 3; i < 8; i++) {
        if (!rooms[i]) {  // 예약 가능 여부 확인
            rooms[i] = true;  // 예약 상태 변경
            allocated_rooms[count] = 201 + (i - 3);  // 예약된 방 번호 저장
            count++;  // 예약된 일반룸 수 증가
            if (count == rooms_needed) {
                printf("예약이 완료되었습니다. 방 번호: ");
                for (int j = 0; j < count; j++) {
                    printf("%d ", allocated_rooms[j]);
                }
                printf("\n");
                return count;  // 일반룸 예약 완료
            }
        }
    }

    // 방이 남아있으나 예약 인원이 모두 수용되지 않는 경우
    if (count > 0) {
        printf("예약이 완료되었습니다. 방 번호: ");
        for (int j = 0; j < count; j++) {
            printf("%d ", allocated_rooms[j]);
        }
        printf("\n");
        printf("%d명은 예약할 수 없습니다.\n", people - (count * 2));  // 예약되지 못한 인원 수
    }

    return count > 0 ? count : 0;  // 추가로 예약이 불가능한 경우, 중복 메시지 방지
}

// 호텔 예약 함수
int reservation_hotel(int people, int room_type) {
    if (room_type == 1) {  // VIP룸 선택
        return vip_check(people);
    }
    else {  // 일반룸 선택
        return normal_check(people);
    }
}

int main() {
    int people, room_type;

    // 5번의 예약 요청 받기
    for (int i = 0; i < 5; i++) {
        printf("예약 인원을 입력하세요 : ");
        scanf("%d", &people);

        if (people <= 0) {
            printf("0명 이하로 예약할 수 없습니다.\n");
            i--;  // 유효한 입력이 들어올 때까지 반복
            continue;
        }

        printf("방 타입을 선택하세요 (1: VIP룸, 2: 일반룸): ");
        scanf("%d", &room_type);

        if (room_type < 1 || room_type > 2) {
            printf("1 또는 2를 입력하세요.\n");
            i--;  // 유효한 입력이 들어올 때까지 반복
            continue;
        }

        int reserved_rooms = reservation_hotel(people, room_type);
        if (reserved_rooms == 0 && people > 0) {
            printf("예약이 불가능합니다.\n");
        }
    }

    // 최종 객실 현황 출력
    printf("\n현재 객실 현황:\n");
    for (int i = 0; i < 8; i++) {
        if (rooms[i]) {
            printf("%d호: 예약 완료\n", (i < 3 ? 301 + i : 201 + (i - 3)));
        }
        else {
            printf("%d호: 예약 가능\n", (i < 3 ? 301 + i : 201 + (i - 3)));
        }
    }

    return 0;
}
