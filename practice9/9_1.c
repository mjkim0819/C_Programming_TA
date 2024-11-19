#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// 숫자인지 확인하는 함수 (하이픈 또는 숫자일 시 0 리턴, 다른 문자는 1 리턴)
int is_digits_only(const char* str) {
    for (int i = 0; str[i] != '\0'; i++) {
        // 하이픈은 제외하고 숫자만 확인
        if (str[i] != '-' && !isdigit(str[i])) {
            return 0;
        }
    }
    return 1;
}

// 구조체와 공용체 정의
struct person {
    char name[15];              // 이름
    union {                     // 공용체
        char phone[15];         // 전화번호
        char registration[15];  // 주민번호
    } contact_info;             // 공용체를 포함한 구조체
};

void main() {
    struct person p;   // 구조체 변수 선언
    int isPhone;        // 전화번호인지 주민번호인지 구분할 변수

    // 사용자로부터 이름 입력 받기
    printf("이름을 입력하세요: ");
    scanf("%s", p.name);  // 이름은 최대 14글자까지 입력받기 (배열 크기 - 1)

    // 사용자로부터 전화번호 또는 주민번호 입력 받기
    printf("전화번호 또는 주민번호를 입력하세요: ");
    scanf("%s", p.contact_info.phone);  // 전화번호 또는 주민번호 입력 (최대 14글자)

    // 주민번호 확인: XXXXXX-XXXXXXX 형식 (14자리)
    if (strlen(p.contact_info.phone) == 14 &&
        p.contact_info.phone[6] == '-' &&  // 7번째 자리가 하이픈인지 확인
        is_digits_only(p.contact_info.phone) &&  // 하이픈 또는 숫자인지 확인
        isdigit(p.contact_info.phone[0]) &&
        isdigit(p.contact_info.phone[13])) {
        isPhone = 0; // 주민번호로 간주
    }
    // 전화번호 확인: XXX-XXXX-XXXX 형식 (13자리)
    else if (strlen(p.contact_info.phone) == 13 &&
        p.contact_info.phone[3] == '-' &&  // 4번째 자리가 하이픈인지 확인
        p.contact_info.phone[8] == '-' &&  // 7번째 자리가 하이픈인지 확인
        is_digits_only(p.contact_info.phone) &&  // 하이픈 또는 숫자인지 확인
        isdigit(p.contact_info.phone[0]) &&
        isdigit(p.contact_info.phone[12])) {
        isPhone = 1; // 전화번호로 간주
    }
    else {
        printf("입력 형식이 올바르지 않습니다.\n");
        return;
    }

    // 출력
    printf("\n--- 이름과 연락처 정보 ---\n");
    printf("이름 ==> %s\n", p.name);
    if (isPhone) {
        printf("전화번호 ==> %s\n", p.contact_info.phone);
    }
    else {
        printf("주민번호 ==> %s\n", p.contact_info.registration);
    }
}
