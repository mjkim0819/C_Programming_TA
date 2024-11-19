#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

// 문자열을 대소문자 구분 없이 비교하는 함수
int my_strcmp(const char* str1, const char* str2) {
    while (*str1 && *str2) {
        // 소문자로 변환 (A-Z는 ASCII 값이 65-90, a-z는 97-122)
        char c1 = (*str1 >= 'A' && *str1 <= 'Z') ? *str1 + 32 : *str1;
        char c2 = (*str2 >= 'A' && *str2 <= 'Z') ? *str2 + 32 : *str2;

        if (c1 != c2) {
            return c1 - c2;
        }
        str1++;
        str2++;
    }
    return *str1 - *str2;
}

// 단어를 사전식으로 정렬하는 함수
void make_dictionary(char words[][MAX_WORD_LENGTH], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (my_strcmp(words[i], words[j]) > 0) {
                char temp[MAX_WORD_LENGTH];
                strcpy(temp, words[i]);
                strcpy(words[i], words[j]);
                strcpy(words[j], temp);
            }
        }
    }
}

// 문자열 끝의 개행 문자와 공백을 제거하는 함수
void trim_newline(char* str) {
    int len = strlen(str);
    while (len > 0 && (str[len - 1] == '\n' || str[len - 1] == ' ')) {
        str[--len] = '\0';
    }
}

// 파일에서 단어를 읽고 정렬 후 저장하는 main 함수
int main() {
    FILE* input = fopen("words.txt", "r");
    FILE* output = fopen("dictionary.txt", "w");
    if (input == NULL || output == NULL) {
        fprintf(stderr, "파일을 열 수 없습니다.\n");
        return 1;
    }

    char words[MAX_WORDS][MAX_WORD_LENGTH];
    int count = 0;
    char line[1024];

    // 단어를 구분하는 문자
    const char* delimiters = "\t;|, ";

    // 파일에서 각 라인을 읽어와서 단어를 분리
    while (fgets(line, sizeof(line), input)) {
        trim_newline(line);  // 각 라인의 끝에서 개행 문자와 공백을 제거
        char* token = strtok(line, delimiters);
        while (token != NULL) {
            trim_newline(token);  // 토큰의 끝에서 개행 문자와 공백을 제거
            if (strlen(token) > 0) {
                strcpy(words[count++], token);
            }
            token = strtok(NULL, delimiters);
        }
    }

    // 사전식으로 정렬
    make_dictionary(words, count);

    // 정렬된 단어를 파일에 저장
    for (int i = 0; i < count; i++) {
        if (strlen(words[i]) > 0) {
            fprintf(output, "%s\n", words[i]);
        }
    }

    fclose(input);
    fclose(output);

    printf("단어가 사전식으로 정렬되어 dictionary.txt에 저장되었습니다.\n");
    return 0;
}
