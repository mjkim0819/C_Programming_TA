#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MENU_LENGTH 20 // 메뉴 이름 최대 길이

// 메뉴와 가격을 출력하는 함수
void printMenu(char** names, int* prices, int size) {
    printf(" [   MENU             PRICE]\n");
    for (int i = 0; i < size; i++) {
        printf(" [%d] %-14s : %5d\n", i + 1, names[i], prices[i]);
    }
}

int main() {
    FILE* file = fopen("menu.txt", "r"); // menu.txt 파일을 읽기 모드로 열기
    if (file == NULL) {
        perror("파일을 열 수 없습니다.");
        return 0;
    }

    int menuSize = 0; // 현재 메뉴 개수
    int capacity = 5; // 동적 배열의 초기 용량
    char** names = (char**)malloc(capacity * sizeof(char*)); // 메뉴 이름을 저장할 배열 동적 할당
    int* prices = (int*)malloc(capacity * sizeof(int)); // 메뉴 가격을 저장할 배열 동적 할당

    if (names == NULL || prices == NULL) {
        perror("메모리 할당 실패");
        fclose(file);
        return 0;
    }

    char buffer[MAX_MENU_LENGTH]; // 메뉴 이름을 임시로 저장할 버퍼
    int price;

    // menu.txt 파일에서 메뉴와 가격을 읽어와서 배열에 저장
    while (fscanf(file, "%[^:]:%d\n", buffer, &price) == 2) {
        if (menuSize >= capacity) {
            // 용량이 부족하면 두 배로 확장
            capacity *= 2;
            names = (char**)realloc(names, capacity * sizeof(char*));
            prices = (int*)realloc(prices, capacity * sizeof(int));
            if (names == NULL || prices == NULL) {
                perror("메모리 재할당 실패");
                fclose(file);
                return 0;
            }
        }

        // 메뉴 이름을 동적 할당하여 배열에 저장
        names[menuSize] = (char*)malloc((strlen(buffer) + 1) * sizeof(char));
        if (names[menuSize] == NULL) {
            perror("메모리 할당 실패");
            fclose(file);
            return 0;
        }
        strcpy(names[menuSize], buffer); // 메뉴 이름 복사
        prices[menuSize] = price; // 가격 저장
        menuSize++;
    }

    fclose(file); // 파일 닫기

    // 메뉴 출력
    printMenu(names, prices, menuSize);

    int choice = 0; // 사용자가 선택한 메뉴 번호
    int menu_cnt[20] = { 0, }; // 각 메뉴의 주문 개수를 저장할 배열

    // 주문 입력 받기
    while (1) {
        printf("메뉴를 고르세요. 주문 완료는 0을 누르세요 : ");
        scanf("%d", &choice);
        if (choice == 0) break; // 0을 입력하면 주문 종료
        printf("%s 주문 받았습니다.\n", names[choice - 1]);
        menu_cnt[choice - 1]++; // 선택한 메뉴의 주문 개수 증가
    }

    int total = 0; // 총 결제 금액
    FILE* result = fopen("receipt.txt", "w+"); // 영수증 파일 작성
    for (int i = 0; i < menuSize; ++i) {
        if (menu_cnt[i]) {
            total += menu_cnt[i] * prices[i]; // 총 결제 금액 계산
            fprintf(result, "%s : %d\n", names[i], prices[i]); // 메뉴와 가격을 영수증에 기록
        }
    }

    fprintf(result, "결제 금액 : %d", total); // 총 결제 금액 기록

    // 동적 할당 해제
    for (int i = 0; i < menuSize; i++) {
        free(names[i]);
    }
    free(names);
    free(prices);

    return 0;
}

