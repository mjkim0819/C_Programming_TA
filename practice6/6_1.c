#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <malloc.h>

int main()
{
    char* p[3]; // 사용자 입력 문자열을 저장할 char 포인터 배열
    char imsi[100]; // 사용자 입력 임시 저장소
    int i, j, size;

    char* temp[3]; // 역순 문자열을 저장할 char 포인터 배열
    FILE* wfp;

    // 파일을 쓰기 모드로 열기 (저장되는 위치 주의)
    wfp = fopen("output1.txt", "w");

    // 사용자로부터 3개의 문자열을 입력받는 반복문
    for (i = 0; i < 3; i++)
    {
        printf("%d 번째 문자열 : ", i + 1); // 입력 요청 메시지
        gets(imsi); // 사용자 입력을 `imsi`에 저장 (gets는 안전하지 않으므로, fgets 사용을 권장)

        size = strlen(imsi); // 입력된 문자열의 길이 계산
        p[i] = (char*)malloc((sizeof(char) * size) + 1); // 문자열 길이 + null 종료 문자 크기만큼 메모리 할당

        strcpy(p[i], imsi); // 입력된 문자열을 동적으로 할당한 메모리(p[i])에 복사

        temp[i] = (char*)malloc(sizeof(char) * size + 1); // 역순 문자열을 위한 메모리 할당

        // 문자열을 거꾸로 복사하여 역순으로 저장
        for (j = 0; j < size; j++)
        {
            temp[i][j] = p[i][size - 1 - j]; // 문자열을 뒤집어 복사
        }
        temp[i][size] = '\0'; // 문자열 끝에 null 문자 추가
    }

    // 파일에 결과 헤더를 작성
    fprintf(wfp, "-- 입력과 반대로 출력(포인터) : 글자 순서도 거꾸로 --\n");

    // 역순 문자열을 반대 순서로 파일에 출력
    for (j = 2; j >= 0; j--) {
        fprintf(wfp, "%d : %s\n", j + 1, temp[j]); // 반대 순서로 문자열 출력
    }

    // 입력된 원본 문자열에 대한 메모리 해제
    for (j = 0; j < i; j++) {
        free(p[j]);
    }
    // 역순 문자열에 대한 메모리 해제
    for (j = 0; j < i; j++)
    {
        free(temp[j]);
    }
    fclose(wfp); // 파일 닫기
    return 0; // 프로그램 종료
}
