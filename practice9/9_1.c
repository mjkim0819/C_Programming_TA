#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 과목 정보를 담을 구조체 정의
typedef struct {
    char name[20];    // 과목명
    int credit;       // 학점
    float score;      // 과목 별 성적
    float weighted_score;  // 평점 (학점 * 성적 점수)
} Subject;

// 성적에 따른 점수를 반환하는 함수
float get_score_value(const char* grade) {
    if (strcmp(grade, "A+") == 0) return 4.5;
    if (strcmp(grade, "A0") == 0) return 4.0;
    if (strcmp(grade, "B+") == 0) return 3.5;
    if (strcmp(grade, "B0") == 0) return 3.0;
    if (strcmp(grade, "C+") == 0) return 2.5;
    if (strcmp(grade, "C0") == 0) return 2.0;
    if (strcmp(grade, "D+") == 0) return 1.5;
    if (strcmp(grade, "D0") == 0) return 1.0;
    if (strcmp(grade, "F") == 0) return 0.0;
    return 0.0;  // 예상치 못한 값에 대한 기본 반환
}

// 문자열 끝의 '\n'을 제거하는 함수
void trim_newline(char* str) {
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

int main() {
    FILE* file = fopen("grade.txt", "r"); // grade.txt 파일을 읽기 모드로 열기
    if (file == NULL) {
        printf("파일을 열 수 없습니다: grade.txt\n");
        return 1;
    }

    Subject* subjects = NULL; // 동적 배열을 위한 포인터
    int subject_count = 0;    // 과목 수
    int total_credit = 0;     // 총 학점
    float total_weighted_score = 0.0;  // 총 점수 (학점 x 성적의 합)

    char line[60];  // 한 줄을 읽어오는 버퍼, 최대 60자

    // 첫 번째 줄(설명)을 건너뛰기
    fgets(line, sizeof(line), file);

    // 두 번째 줄부터 실제 데이터 읽기
    while (fgets(line, sizeof(line), file) != NULL) {
        trim_newline(line);  // 각 줄의 끝에 '\n' 제거

        // 동적 배열 크기 확장
        Subject* temp = realloc(subjects, (subject_count + 1) * sizeof(Subject));
        if (temp == NULL) {
            printf("메모리 할당 실패\n");
            free(subjects);  // 이전에 할당된 메모리 해제
            fclose(file);
            return 1;
        }
        subjects = temp;  // realloc이 성공하면 subjects에 새 메모리 할당 주소를 할당

        // 과목명, 학점, 성적 파싱
        char* name_end = strchr(line, '\t');  // 첫 번째 탭 위치 찾기
        if (name_end == NULL) continue;  // 탭이 없다면 잘못된 줄이므로 넘어가기

        *name_end = '\0';  // 탭을 문자열 종료로 바꾸기 (과목명 끝)

        char* credit_start = name_end + 1; // 학점 시작 위치
        char* credit_end = strchr(credit_start, '\t');  // 두 번째 탭 위치
        if (credit_end == NULL) continue;  // 잘못된 형식이라면 넘어가기

        *credit_end = '\0';  // 두 번째 탭을 문자열 종료로 바꾸기 (학점 끝)

        char* grade_start = credit_end + 1;  // 성적 시작 위치

        // 과목 정보를 구조체에 저장
        strcpy(subjects[subject_count].name, line);  // 과목명
        subjects[subject_count].credit = atoi(credit_start);  // 학점
        subjects[subject_count].score = get_score_value(grade_start);  // 성적 점수
        subjects[subject_count].weighted_score = subjects[subject_count].credit * subjects[subject_count].score; // 학점 * 성적 점수

        total_credit += subjects[subject_count].credit;  // 총 학점에 추가
        total_weighted_score += subjects[subject_count].weighted_score;  // 총 점수에 학점 × 성적 점수 추가

        subject_count++;  // 과목 수 증가
    }

    fclose(file);  // 파일 닫기

    // 각 과목별 점수 출력
    printf("각 과목별 점수:\n");
    for (int i = 0; i < subject_count; i++) {
        printf("%s: %.1f\n", subjects[i].name, subjects[i].score);  // 성적 점수만 출력
    }

    // 총 평점 계산 및 출력
    if (total_credit > 0) {
        float total_gpa = total_weighted_score / total_credit;  // 총 평점 = 총 점수 / 총 학점
        printf("\n총 평점: %.2f\n", total_gpa);  // 총 평점 출력
    }
    else {
        printf("총 학점이 0입니다.\n");
    }

    // 동적 메모리 해제
    free(subjects);

    return 0;
}
