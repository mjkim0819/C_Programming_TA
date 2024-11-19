#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 월을 나타내는 열거형 정의
enum Month {
    January = 1, February, March,
    April, May, June,
    July, August, September,
    October, November, December
};

void main() {
    enum Month monthInput; // 사용자 입력을 받을 열거형 변수

    // 사용자로부터 월 입력 받기
    printf("월 입력: ");
    scanf("%d", &monthInput);  // 열거형 변수는 정수값으로 입력받음

    // 입력된 값에 따라 월 이름 출력
    switch (monthInput) {
    case January:
        printf("%d월은 January입니다.\n", monthInput);
        break;
    case February:
        printf("%d월은 February입니다.\n", monthInput);
        break;
    case March:
        printf("%d월은 March입니다.\n", monthInput);
        break;
    case April:
        printf("%d월은 April입니다.\n", monthInput);
        break;
    case May:
        printf("%d월은 May입니다.\n", monthInput);
        break;
    case June:
        printf("%d월은 June입니다.\n", monthInput);
        break;
    case July:
        printf("%d월은 July입니다.\n", monthInput);
        break;
    case August:
        printf("%d월은 August입니다.\n", monthInput);
        break;
    case September:
        printf("%d월은 September입니다.\n", monthInput);
        break;
    case October:
        printf("%d월은 October입니다.\n", monthInput);
        break;
    case November:
        printf("%d월은 November입니다.\n", monthInput);
        break;
    case December:
        printf("%d월은 December입니다.\n", monthInput);
        break;
    default:
        printf("잘못된 월 번호입니다. 1부터 12까지의 숫자를 입력해주세요.\n");
        break;
    }
}
