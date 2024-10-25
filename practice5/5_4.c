#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// '+' 출력을 위한 변수
int chk_900, chk_400, chk_500, chk_90, chk_40, chk_50, chk_9, chk_4, chk_5;

int main() {
	int num = 0;
    int cnt = 0;
	scanf("%d", &num);

    // 가능한 최대 문자열 수를 미리 할당후 아래에서 다시 문자열 크기 만큼 재할당
    char* ans = (char*)malloc(sizeof(char) * 13);
    // 쓰레기값 방지를 위한 초기화
    memset(ans, ' \0', sizeof(char) * 13);
    printf("%d = ", num);

    /*
    900이나 400일때 예외 처리

    500 이상이면 D

    100 이상일 동안 C

    90이나 40일때 예외 처리

    50 이상이면 L

    10 이상일 동안 X를 더함

    9나 4일때 예외 처리

    5 이면 V

    1 이상일 동안 I
    */

    if (num >= 900) {
        printf("900");
        num -= 900;

        ans[cnt] = 'C'; 
        cnt++;
        ans[cnt] = 'M';
        cnt++;
        chk_900 = 1;
    }
    if (chk_900 && num) printf(" + ");

    else if (num >= 400 && num < 500) {
        printf("400");
        num -= 400;

        ans[cnt] = 'C';
        cnt++;
        ans[cnt] = 'D';
        cnt++;
        chk_400 = 1;
    }
    if (chk_400 && num) printf(" + ");

    if (num >= 500) {
        printf("500");
        num -= 500;

        ans[cnt] = 'D';
        cnt++;
        chk_500 = 1;
    }
    if (chk_500 && num) printf(" + ");

    int cnt_100 = 0;
    while (num >= 100) {
        num -= 100;

        ans[cnt] = 'C';
        cnt++;
        cnt_100++;
    }
    if (cnt_100) printf("%d", 100 * cnt_100);
    if(cnt_100 && num) printf(" + ");

    if (num >= 90) {
        printf("90");
        num -= 90;

        ans[cnt] = 'X';
        cnt++;
        ans[cnt] = 'C';
        cnt++;
        chk_90 = 1;
    }
    if (chk_90 && num) printf(" + ");

    else if (num >= 40 && num < 50) {
        printf("40");
        num -= 40;

        ans[cnt] = 'X';
        cnt++;
        ans[cnt] = 'L';
        cnt++;
        chk_40 = 1;
    }
    if (chk_40 && num) printf(" + ");

    if (num >= 50) {
        printf("50");
        num -= 50;

        ans[cnt] = 'L';
        cnt++;
        chk_50 = 1;
    }
    if (chk_50 && num) printf(" + ");

    int cnt_10 = 0;
    while (num >= 10) {
        num -= 10;

        ans[cnt] = 'X';
        cnt++;
        cnt_10++;
    }
    if (cnt_10) printf("%d", 10 * cnt_10);
    if (cnt_10 && num) printf(" + ");

    if (num == 9) {
        printf("9");
        num -= 9;

        ans[cnt] = 'I';
        cnt++;
        ans[cnt] = 'X';
        cnt++;
        chk_9 = 1;
    }
    if (chk_9 && num) printf(" + ");

    else if (num == 4) {
        printf("4");
        num -= 4;

        ans[cnt] = 'I';
        cnt++;
        ans[cnt] = 'V';
        cnt++;
        chk_4 = 1;
    }
    if (chk_4 && num) printf(" + ");

    if (num >= 5) {
        printf("5");
        num -= 5;

        ans[cnt] = 'V';
        cnt++;
        chk_5 = 1;
    }
    if (chk_5 && num) printf(" + ");

    int cnt_1 = 0;
    while (num >= 1) {
        num--;

        ans[cnt] = 'I';
        cnt++;
        cnt_1++;
    }    
    if (cnt_1) printf("%d", 1 * cnt_1);
    if (cnt_1 && num) printf(" + ");

    // 메모리 문자열 크기 만큼 재할당
    ans = realloc(ans, sizeof(char) * (cnt + 1));
    int len = _msize(ans);
    
    printf(" = %s, ", ans);
    printf("%d", len - 1);

    free(ans);

	return 0;
}