#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <malloc.h>  // 메모리 할당 함수를 사용하기 위해 malloc.h 포함

// 오름차순 정렬 함수
void sortAscending(char** str, int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (strcmp(str[i], str[j]) > 0) {
                char* tmp = str[i];
                str[i] = str[j];
                str[j] = tmp;
            }
        }
    }
}

// 내림차순 정렬 함수
void sortDescending(char** str, int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (strcmp(str[i], str[j]) < 0) {
                char* tmp = str[i];
                str[i] = str[j];
                str[j] = tmp;
            }
        }
    }
}

// 결과를 파일에 쓰는 함수
void write_result_to_file(char** str, int count, const char* filename) {
    FILE* file = fopen(filename, "w");
    if (!file) {  // 파일 열기 실패 시 오류 메시지 출력
        printf("파일을 열 수 없습니다: %s\n", filename);
        return;
    }

    // 가장 긴 문자열의 길이를 계산하여 정렬 출력 시 사용
    int max_length = 0;
    for (int i = 0; i < count; i++) {
        int len = strlen(str[i]);
        if (len > max_length) max_length = len;
    }

    // 정렬된 결과를 파일에 작성
    fprintf(file, "=====Sorting Result=====\n");
    for (int i = 0; i < count; i++) {
        fprintf(file, "[%*s]\n", max_length, str[i]);
    }
    fclose(file);  // 파일 닫기
}

int main(void) {
    char* pointerArray_A[5]; // 단어를 임시로 저장할 포인터 배열
    char* pointerArray_B[20]; // 정렬할 최종 단어를 저장할 포인터 배열
    int word_count = 0;  // 추출된 단어의 개수

    FILE* file = fopen("data.txt", "r");
    if (!file) {  // 파일 열기 실패 시 오류 메시지 출력
        printf("파일을 열 수 없습니다: data.txt\n");
        return 1;
    }

    // 포인터 배열의 각 요소에 메모리 할당 (malloc 사용)
    for (int i = 0; i < 5; i++) pointerArray_A[i] = (char*)malloc(100);
    for (int i = 0; i < 20; i++) pointerArray_B[i] = (char*)malloc(100);

    int ch;
    int char_index = 0;  // 각 단어의 문자 위치 인덱스
    int line_index = 0;  // pointerArray_A의 인덱스
    while ((ch = fgetc(file)) != EOF) {  // 파일에서 문자 단위로 읽기
        if (ch != ' ' && ch != '\n') {  // 공백이나 줄바꿈이 아니면 단어에 추가
            pointerArray_A[line_index][char_index++] = ch;
        }
        else if (char_index > 0) {  // 단어가 완성되었을 경우
            pointerArray_A[line_index][char_index] = '\0';
            strcpy(pointerArray_B[word_count++], pointerArray_A[line_index]);
            char_index = 0;
            line_index = (line_index + 1) % 5;
            if (word_count >= 20) break;
        }
    }
    fclose(file);  // 파일 닫기

    // 오름차순 정렬 및 파일 쓰기
    sortAscending(pointerArray_B, word_count);
    write_result_to_file(pointerArray_B, word_count, "Result_Ascending.txt");

    // 내림차순 정렬 및 파일 쓰기
    sortDescending(pointerArray_B, word_count);
    write_result_to_file(pointerArray_B, word_count, "Result_Descending.txt");

    // 메모리 해제
    for (int i = 0; i < 5; i++) free(pointerArray_A[i]);
    for (int i = 0; i < 20; i++) free(pointerArray_B[i]);

    return 0;
}
