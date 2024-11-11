#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main() {
    // 학생 정보를 담을 구조체 정의
    struct student {
        char name[20]; // 학생 이름
        int age;       // 학생 나이
    };

    int n; // 학생 수
    printf("학생 수를 입력하세요: ");
    scanf("%d", &n);

    // 학생 정보 동적 할당
    struct student* students = (struct student*)malloc(n * sizeof(struct student));
    if (students == NULL) {
        printf("메모리 할당 실패!\n");
        return;
    }

    // 학생 정보 입력
    for (int i = 0; i < n; i++) {
        struct student* p = &students[i]; // 구조체 포인터

        printf("\n학생 %d의 정보를 입력하세요:\n", i + 1);
        printf("이름: ");
        scanf("%s", p->name); // 이름 입력 받기
        printf("나이: ");
        scanf("%d", &p->age); // 나이 입력 받기
    }

    // 학생 명단 출력
    printf("\n---- 학생 명단 ----\n");
    for (int i = 0; i < n; i++) {
        struct student* p = &students[i]; // 구조체 포인터

        printf("이름: %s, 나이: %d\n", p->name, p->age); // 이름과 나이 출력
    }

    // 동적 메모리 해제
    free(students);
}
