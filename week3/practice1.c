#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// my_strcmp 함수: 두 문자열을 비교
int my_strcmp(const char* str1, const char* str2) {
    // 각 문자열의 문자들을 비교
    while (*str1 != '\0' && *str2 != '\0') {
        if (*str1 > *str2) {
            return 1;  // 첫 번째 문자열이 클 경우
        }
        else if (*str1 < *str2) {
            return -1; // 두 번째 문자열이 클 경우
        }
        str1++;  // 다음 문자로 이동
        str2++;  // 다음 문자로 이동
    }
    // 앞 글자가 같고 문자열의 길이가 다를 경우, 더 긴 문자열이 더 큼 ( cat, catch )
    if (*str1 != '\0') {
        return 1;   // str1이 더 길 경우
    }
    else if (*str2 != '\0') {
        return -1;  // str2가 더 길 경우
    }
    return 0;  // 두 문자열이 같을 경우
}

// my_strcat 함수: 두 문자열을 병합
char* my_strcat(const char* str1, const char* str2, char* result) {
    // 첫 번째 문자열을 결과에 복사
    while (*str1 != '\0') {
        *result = *str1;  // 현재 문자 복사
        result++;          // 결과 포인터를 다음 위치로 이동
        str1++;           // 첫 번째 문자열 포인터를 다음 문자로 이동
    }
    // 두 번째 문자열을 결과에 붙이기
    while (*str2 != '\0') {
        *result = *str2;  // 현재 문자 복사
        result++;          // 결과 포인터를 다음 위치로 이동
        str2++;           // 두 번째 문자열 포인터를 다음 문자로 이동
    }
    *result = '\0'; // 결과 문자열의 끝에 null 문자 추가
    return result - (result - result); // 병합된 문자열 반환 (결과 포인터를 원래 시작 위치로 조정)
}

// my_strcpy 함수: 문자열을 문자형 배열에 복사
char* my_strcpy(const char* str, char* result) {
    while (*str != '\0') {
        *result = *str;  // 현재 문자 복사
        result++;         // 결과 포인터를 다음 위치로 이동
        str++;            // 원본 문자열 포인터를 다음 문자로 이동
    }
    *result = '\0'; // 복사된 문자열의 끝에 null 문자 추가
    return result - (result - result); // 복사된 배열 반환 (결과 포인터를 원래 시작 위치로 조정)
}

int main() {
    char str1[6], str2[6];  // 5글자 이내의 단어를 저장하기 위한 배열
    char result[11];        // 결과를 저장할 배열 (최대 5글자씩 두 문자열 병합)

    // 사용자로부터 입력 받기
    printf("첫 번째 단어(5글자 이내)를 입력하세요: ");
    scanf("%5s", str1);
    printf("두 번째 단어(5글자 이내)를 입력하세요: ");
    scanf("%5s", str2);

    // 문자열 비교 my_strcmp 호출
    int cmp_result = my_strcmp(str1, str2);
    printf("my_strcmp 결과: %d\n", cmp_result);

    // 문자열 병합 my_strcat 호출
    my_strcat(str1, str2, result);
    printf("my_strcat 결과: %s\n", result);

    // 문자열 복사 my_strcpy 호출
    char copied_str[6];  // 문자열을 복사할 배열
    my_strcpy(str1, copied_str);
    printf("my_strcpy 결과: %s\n", copied_str);

    return 0;
}
