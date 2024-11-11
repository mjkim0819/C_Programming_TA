#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <malloc.h>

void main() {

    char str[100]; // 파일에서 한 줄씩 읽어올 문자열을 저장할 배열
    FILE* rfp, * wfp;

    // 파일을 읽기 모드로 열기 (읽고싶은 파일 위치 주의)
    rfp = fopen("in.txt", "r");
    // 파일을 쓰기 모드로 열기 (저장되는 위치 주의)
    wfp = fopen("output2.txt", "w");

    // 입력 파일의 내용을 한 줄씩 읽어들이는 반복문
    while (fgets(str, sizeof(str), rfp) != NULL) // fgets를 사용하여 한 줄씩 읽기
    {
        int len = strlen(str); // 현재 줄의 문자열 길이 계산

        // 줄 끝에 줄바꿈 문자가 있을 경우 제거
        if (str[len - 1] == '\n') {
            str[--len] = '\0'; // 문자열 길이를 1 줄이고 줄바꿈 문자 제거
        }

        // 문자열을 거꾸로 출력 파일에 쓰기
        for (int i = len - 1; i >= 0; i--) {
            fputc(str[i], wfp); // 문자를 역순으로 출력 파일에 기록
        }

        fprintf(wfp, "\n"); // 한 줄 끝에 줄바꿈 추가
    }

    fclose(wfp); // 출력 파일 닫기
    fclose(rfp); // 입력 파일 닫기

    return 0; // 프로그램 종료
}
