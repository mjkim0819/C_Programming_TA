#define _CRT_SECURE_NO_WARNINGS // 보안 경고를 무시하기 위한 매크로 정의
#include <stdio.h>
#include <malloc.h> // malloc 및 free 함수 사용을 위한 헤더 파일

void main() // main 함수의 시작
{
    int* p; // 정수형 포인터 선언 (동적 할당된 배열의 포인터)
    int i, hap = 0; // 반복문 카운터 및 합계를 저장할 변수
    int cnt; // 입력받을 숫자의 개수를 저장할 변수

    printf("입력할 개수는? : "); // 사용자에게 입력할 개수 요청
    scanf("%d", &cnt); // 입력된 개수를 cnt에 저장

    // 동적 메모리 할당: cnt개의 정수를 저장할 수 있는 메모리 블록 요청
    p = (int*)malloc(sizeof(int) * cnt); 

    // 동적 메모리 할당 실패 여부 확인
    if (p == NULL) { // 메모리 할당이 실패했는지 확인
        printf("메모리 할당 실패\n"); // 할당 실패 메시지 출력
        return; // 프로그램 종료
    }

    // 사용자가 입력한 숫자들을 배열에 저장
    for (i = 0; i < cnt; i++) {
        printf("%d 번째 숫자 : ", i + 1); // 사용자에게 숫자 입력 요청
        scanf("%d", p + i); // 입력된 숫자를 배열에 저장
    }

    // 입력된 숫자 중 짝수의 합을 구함
    for (i = 0; i < cnt; i++) {
        if (*(p + i) % 2 == 0) { // 현재 숫자가 짝수인지 확인
            hap = hap + *(p + i); // 짝수이면 hap에 더함
        }
    }   

    // 결과 출력
    printf("입력 숫자 합 ==> %d \n", hap); // 짝수의 합을 출력

    free(p); // 동적 할당된 메모리 해제 (메모리 누수 방지)
}
