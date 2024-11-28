#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MENU 100
#define MAX_NAME_LEN 50

typedef struct {
    int id;
    char name[MAX_NAME_LEN];
    double price;
} MenuItem;

typedef struct {
    char name[MAX_NAME_LEN];
    int quantity;
    double total_price;
} Order;

// 함수 선언
void Initial_menulist(MenuItem* drinks, int* drink_count, MenuItem* desserts, int* dessert_count);
void drink_count(MenuItem* drinks, int drink_count, Order* orders, int* order_count);
void dessert_count(MenuItem* desserts, int dessert_count, Order* orders, int* order_count);
void print_receipt(Order* orders, int order_count, FILE* receipt);

// 메인 함수
int main() {
    MenuItem drinks[MAX_MENU];
    MenuItem desserts[MAX_MENU];
    int drink_count_num = 0, dessert_count_num = 0;
    Order orders[MAX_MENU];
    int order_count = 0;

    Initial_menulist(drinks, &drink_count_num, desserts, &dessert_count_num);

    int choice;
    FILE* receipt = fopen("receipt.txt", "w");
    if (receipt == NULL) {
        printf("영수증 파일을 열 수 없습니다.\n");
        return 1;
    }

    while (1) {
        printf("\n--- 주문 메뉴 ---\n");
        printf("1. 음료 주문\n");
        printf("2. 디저트 주문\n");
        printf("0. 주문 종료\n");
        printf("선택: ");
        scanf("%d", &choice);

        if (choice == 1) {
            drink_count(drinks, drink_count_num, orders, &order_count);
        }
        else if (choice == 2) {
            dessert_count(desserts, dessert_count_num, orders, &order_count);
        }
        else if (choice == 0) {
            break;
        }
        else {
            printf("잘못된 선택입니다. 다시 시도하세요.\n");
        }
    }

    print_receipt(orders, order_count, receipt);
    fclose(receipt);

    return 0;
}

// 메뉴 리스트 초기화 함수
void Initial_menulist(MenuItem* drinks, int* drink_count, MenuItem* desserts, int* dessert_count) {
    FILE* drink_file = fopen("drink.txt", "r");
    FILE* dessert_file = fopen("dessert.txt", "r");

    if (drink_file == NULL || dessert_file == NULL) {
        printf("파일을 열 수 없습니다.\n");
        exit(1);
    }

    char name[MAX_NAME_LEN];
    double price;
    int id = 1;

    while (fscanf(drink_file, "%s %lf", name, &price) != EOF) {
        drinks[*drink_count].id = id++;
        strcpy(drinks[*drink_count].name, name);
        drinks[*drink_count].price = price;
        (*drink_count)++;
    }

    id = 1;
    while (fscanf(dessert_file, "%s %lf", name, &price) != EOF) {
        desserts[*dessert_count].id = id++;
        strcpy(desserts[*dessert_count].name, name);
        desserts[*dessert_count].price = price;
        (*dessert_count)++;
    }

    fclose(drink_file);
    fclose(dessert_file);
}

// 음료 주문 처리 함수
void drink_count(MenuItem* drinks, int drink_count, Order* orders, int* order_count) {
    printf("\n--- 음료 메뉴 ---\n");
    for (int i = 0; i < drink_count; i++) {
        printf("[%d] %s %.2f\n", drinks[i].id, drinks[i].name, drinks[i].price);
    }

    int id, quantity;
    printf("주문할 음료의 ID를 입력하세요: ");
    scanf("%d", &id);
    printf("주문 수량을 입력하세요: ");
    scanf("%d", &quantity);

    for (int i = 0; i < drink_count; i++) {
        if (drinks[i].id == id) {
            printf("%s x %d를 주문했습니다. 총 가격: %.2f\n", drinks[i].name, quantity, drinks[i].price * quantity);

            // 주문 추가 또는 기존 주문 업데이트
            int found = 0;
            for (int j = 0; j < *order_count; j++) {
                if (strcmp(orders[j].name, drinks[i].name) == 0) {
                    orders[j].quantity += quantity;
                    orders[j].total_price += drinks[i].price * quantity;
                    found = 1;
                    break;
                }
            }
            if (!found) {
                strcpy(orders[*order_count].name, drinks[i].name);
                orders[*order_count].quantity = quantity;
                orders[*order_count].total_price = drinks[i].price * quantity;
                (*order_count)++;
            }
            return;
        }
    }
    printf("유효하지 않은 ID입니다.\n");
}

// 디저트 주문 처리 함수
void dessert_count(MenuItem* desserts, int dessert_count, Order* orders, int* order_count) {
    printf("\n--- 디저트 메뉴 ---\n");
    for (int i = 0; i < dessert_count; i++) {
        printf("[%d] %s %.2f\n", desserts[i].id, desserts[i].name, desserts[i].price);
    }

    int id, quantity;
    printf("주문할 디저트의 ID를 입력하세요: ");
    scanf("%d", &id);
    printf("주문 수량을 입력하세요: ");
    scanf("%d", &quantity);

    for (int i = 0; i < dessert_count; i++) {
        if (desserts[i].id == id) {
            printf("%s x %d를 주문했습니다. 총 가격: %.2f\n", desserts[i].name, quantity, desserts[i].price * quantity);

            // 주문 추가 또는 기존 주문 업데이트
            int found = 0;
            for (int j = 0; j < *order_count; j++) {
                if (strcmp(orders[j].name, desserts[i].name) == 0) {
                    orders[j].quantity += quantity;
                    orders[j].total_price += desserts[i].price * quantity;
                    found = 1;
                    break;
                }
            }
            if (!found) {
                strcpy(orders[*order_count].name, desserts[i].name);
                orders[*order_count].quantity = quantity;
                orders[*order_count].total_price = desserts[i].price * quantity;
                (*order_count)++;
            }
            return;
        }
    }
    printf("유효하지 않은 ID입니다.\n");
}

// 영수증 출력 함수
void print_receipt(Order* orders, int order_count, FILE* receipt) {
    printf("\n--- 영수증 ---\n");
    fprintf(receipt, "----------------------\n");
    fprintf(receipt, "        Receipt       \n");
    fprintf(receipt, "----------------------\n");

    double total = 0.0;
    for (int i = 0; i < order_count; i++) {
        printf("%s x %d = %.2f\n", orders[i].name, orders[i].quantity, orders[i].total_price);
        fprintf(receipt, "%s x %d = %.2f\n", orders[i].name, orders[i].quantity, orders[i].total_price);
        total += orders[i].total_price;
    }

    printf("----------------------\n");
    printf("Total :: %.2f\n", total);
    fprintf(receipt, "----------------------\n");
    fprintf(receipt, "Total :: %.2f\n", total);

    printf("영수증이 receipt.txt에 저장되었습니다.\n");
}
