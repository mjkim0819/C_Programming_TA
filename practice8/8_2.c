#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1000

FILE* file; // 파일 포인터
char line[255]; // 파일에서 읽어온 한 줄을 저장할 배열
char subjects[100][100]; // 과목명을 저장할 배열
float score[100]; // 과목별 점수를 저장할 배열
float total_score; // 총 점수를 저장할 변수
int total_credit; // 총 학점을 저장할 변수
int subject_cnt; // 과목 수를 저장할 변수

int main() {

	file = fopen("grade.txt", "r"); // grade.txt 파일을 읽기 모드로 열기

	if (file == NULL) {
		printf("File Error\n"); // 파일을 열 수 없는 경우 에러 메시지 출력
		return 0;
	}

	// 파일의 각 줄을 읽어와서 처리
	while (fgets(line, sizeof(line), file) != NULL) {
		if (subject_cnt != 0) { // 첫 줄은 제외하고 과목 데이터를 읽음
			int subject_check = 0; // 과목명이 확인되었는지 체크하는 변수
			int credit_check = 0; // 학점이 확인되었는지 체크하는 변수
			int score_check = 0; // 성적이 확인되었는지 체크하는 변수
			int tmp_credit = 0; // 임시로 학점을 저장할 변수
			float tmp_score = 0; // 임시로 점수를 저장할 변수

			// 탭 문자를 기준으로 문자열을 분리하여 처리
			char* ptr = strtok(line, "\t");
			while (ptr != NULL) {
				if (subject_check == 0) {
					subject_check = 1; // 과목명 부분 처리 완료
					strcpy(subjects[subject_cnt], ptr); // 과목명 저장
				}
				else if (subject_check == 1 && credit_check == 0) {
					credit_check = 1; // 학점 부분 처리 완료
					tmp_credit = atoi(ptr); // 학점을 정수로 변환하여 저장
					total_credit += tmp_credit; // 총 학점에 추가
				}
				else if (subject_check == 1 && credit_check == 1 && score_check == 0) {
					score_check = 1; // 성적 부분 처리 완료
					char tmp[4];
					strcpy(tmp, ptr);

					// 성적 문자열을 점수로 변환
					if (strncmp(tmp, "A+", 2) == 0) tmp_score = 4.5;
					if (strncmp(tmp, "A0", 2) == 0) tmp_score = 4.0;
					if (strncmp(tmp, "B+", 2) == 0) tmp_score = 3.5;
					if (strncmp(tmp, "B0", 2) == 0) tmp_score = 3.0;
					if (strncmp(tmp, "C+", 2) == 0) tmp_score = 2.5;
					if (strncmp(tmp, "C0", 2) == 0) tmp_score = 2.0;
					if (strncmp(tmp, "D+", 2) == 0) tmp_score = 1.5;
					if (strncmp(tmp, "D0", 2) == 0) tmp_score = 1.0;
					if (strncmp(tmp, "F", 2) == 0) tmp_score = 0.0;

					// 과목 점수를 학점과 곱한 값을 저장
					score[subject_cnt] = tmp_credit * tmp_score;
					total_score += tmp_credit * tmp_score; // 총 점수에 추가
				}
				ptr = strtok(NULL, "\t"); // 다음 토큰으로 이동
			}
		}

		// line 배열을 초기화
		for (int i = 0; i < 100; ++i) line[i] = " ";
		subject_cnt++; // 과목 수 증가
	}

	// 각 과목과 해당 점수 출력
	printf("Each Subject\n");
	for (int i = 1; i <= subject_cnt - 1; ++i) {
		printf("%s: %.1f\n", subjects[i], score[i]);
	}

	// 총 평점 출력
	printf("\nTotal : %.2f", total_score / total_credit);

	fclose(file); // 파일 닫기
	return 0;
}
