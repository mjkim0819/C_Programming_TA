#define _CRT_SECURE_NO_WARNINGS // 보안 경고를 무시하기 위한 매크로 정의
#include <stdio.h>
#include <malloc.h> // malloc, free 함수 사용을 위한 헤더 파일
#include <string.h> // 문자열 처리 함수 사용을 위한 헤더 파일

void main() // 메인 함수의 시작
{
    char* p[3]; // 문자열을 저장할 포인터 배열 (3개의 문자열 저장)
    char imsi[100]; // 사용자 입력을 임시로 저장할 배열
    int i, size; // 반복문 카운터 및 문자열 크기 저장 변수
    int size_hap = 0; // 두 문자열의 총 길이를 저장할 변수

    // 사용자로부터 2개의 문자열 입력받기
    for (i = 0; i < 2; i++) {
        printf("%d 번째 문자열 : ", i + 1); // 사용자에게 문자열 입력 요청
        gets(imsi); // 입력된 문자열을 imsi 배열에 저장 (gets는 안전하지 않으므로 주의 필요)

        size = strlen(imsi); // 입력된 문자열의 길이를 계산
        p[i] = (char*)malloc((sizeof(char) * size) + 1); // 동적 메모리 할당 (문자열 길이 + 1 (null terminator))

        strcpy(p[i], imsi); // imsi의 내용을 동적으로 할당한 메모리(p[i])에 복사
        size_hap += size; // 문자열 길이를 size_hap에 누적
    }

    // 총 길이에 맞게 세 번째 문자열을 위한 메모리 할당
    p[2] = (char*)malloc((sizeof(char) * size_hap) + 1); // 두 문자열의 총 길이에 맞는 메모리 할당

    // 두 문자열을 결합하여 p[2]에 저장
    strcpy(p[2], p[0]); // 첫 번째 문자열을 p[2]에 복사
    strcat(p[2], p[1]); // 두 번째 문자열을 p[2]에 결합

    // 결과 출력
    printf("\n -- 입력과 합쳐진 문자열 출력(포인터)--\n");
    for (i = 0; i < 3; i++) {
        printf(" %d : %s\n", i + 1, p[i]); // 각 문자열 출력
    }

    // 동적으로 할당된 메모리 해제
    for (i = 0; i < 3; i++) {
        free(p[i]); // 각 문자열에 대해 할당된 메모리 해제
    }
}
