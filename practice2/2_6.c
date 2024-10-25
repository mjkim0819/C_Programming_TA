#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100

// 사용자로부터 문자들과 정렬 방식을 입력받는 함수
void input_char(char str[], char* sort_order) {
    printf("최대 %d개의 문자를 입력하세요: ", MAX_SIZE);
    fgets(str, MAX_SIZE, stdin);

    // 문자열 끝의 개행문자 제거
    str[strcspn(str, "\n")] = '\0';

    printf("정렬 방식을 입력하세요 (오름차순/내림차순): ");
    fgets(sort_order, 11, stdin); // 사용자로부터 정렬 방식 입력받기
    sort_order[strcspn(sort_order, "\n")] = '\0'; // 문자열 끝의 개행문자 제거
}

// 매개변수로 받은 문자열과 정렬 방식을 바탕으로 문자들을 정렬하는 함수
void func_sort(char str[], char sort_order[]) {
    int len = strlen(str); // 문자열의 길이 계산

    for (int i = 0; i < len - 1; i++) {   // 첫번째 문자부터
        for (int j = i + 1; j < len; j++) {    // 그 이후에 오는 문자들과 비교
            if ((strcmp(sort_order, "오름차순") == 0 && str[i] > str[j]) ||
                (strcmp(sort_order, "내림차순") == 0 && str[i] < str[j])) {
                // 오름차순로 정렬해야 하면서, str[i](앞에 오는 문자)보다 str[j](뒤에 오는 문자)이 더 큰 경우 swap
                // 내림차순을 정렬해야 하면서, str[i](앞에 오는 문자)보다 str[j](뒤에 오는 문자)이 더 작은 경우 swap
                char temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }
}

// 정렬된 문자들을 출력하는 함수
void func_print(char str[]) {
    printf("정렬된 문자들: %s\n", str);
}

int main() {
    char str[MAX_SIZE];
    char sort_order[11];

    // 사용자 입력 받기
    input_char(str, sort_order);

    // 정렬 함수 호출
    func_sort(str, sort_order);

    // 정렬된 문자 출력
    func_print(str);

    return 0;
}