#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 학생 성적 정보를 담을 구조체
struct student {
    char name[20];  // 학생 이름
    int kor;        // 국어 점수
    int eng;        // 영어 점수
};

// 결과 정보를 담을 구조체
struct result {
    float avg;       // 각 학생들의 평균 점수
    float kor_avg;   // 국어 과목 평균 점수
    float eng_avg;   // 영어 과목 평균 점수
    float total_avg; // 모든 학생들의 총 평균 점수
};

int main() {
    int n;
    printf("학생 수를 입력하세요 : ");
    scanf("%d", &n);

    // 학생 정보 동적 할당 (포인터 사용)
    struct student* students = (struct student*)malloc(n * sizeof(struct student));
    if (students == NULL) {
        printf("메모리 할당 실패!\n");
        return 1;
    }

    // 각 학생의 성적 입력
    for (int i = 0; i < n; i++) {
        struct student* s = &students[i];  // 학생 포인터

        printf("\n학생 %d의 정보를 입력하세요\n", i + 1);
        printf("이름: ");
        scanf("%s", s->name);
        printf("국어 점수: ");
        scanf("%d", &s->kor);
        printf("영어 점수: ");
        scanf("%d", &s->eng);
    }

    // 파일 열기 (쓰기 모드)
    FILE* file = fopen("average_student.txt", "w");
    if (file == NULL) {
        printf("파일 열기 실패!\n");
        free(students);
        return 1;
    }

    // 각 과목별 평균 점수, 학생별 평균 점수 및 전체 평균 점수 계산
    struct result result_data = { 0 };  // 결과 정보를 담을 구조체 초기화
    float total_kor = 0, total_eng = 0, total_avg = 0;

    for (int i = 0; i < n; i++) {
        struct student* s = &students[i];  // 학생 포인터

        float avg = (s->kor + s->eng) / 2.0;
        total_kor += s->kor;
        total_eng += s->eng;
        total_avg += avg;

        // 학생 정보를 파일에 기록
        fprintf(file, "%s의 평균 점수: %.2f\n", s->name, avg);
        fprintf(file, "국어 점수: %d, 영어 점수: %d\n\n", s->kor, s->eng);
    }

    result_data.kor_avg = total_kor / n;
    result_data.eng_avg = total_eng / n;
    result_data.total_avg = total_avg / n;

    // 과목별 평균 점수와 전체 평균 점수 파일에 기록
    fprintf(file, "\n과목별 평균 점수\n");
    fprintf(file, "국어 평균: %.2f\n", result_data.kor_avg);
    fprintf(file, "영어 평균: %.2f\n", result_data.eng_avg);
    fprintf(file, "전체 학생들의 평균 점수: %.2f\n", result_data.total_avg);

    // 파일 닫기
    fclose(file);

    // 동적 할당 해제
    free(students);

    printf("결과가 'average_student.txt'에 저장되었습니다.\n");

    return 0;
}
