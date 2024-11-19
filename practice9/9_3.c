#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <malloc.h>  // 동적 메모리 할당을 위한 라이브러리

struct Book {
    int id;             // 도서 ID
    char* title;        // 도서 제목 (동적 할당)
    int quantity;       // 보유 권수
};

struct Book* bookList = NULL;  // 동적으로 할당된 도서 목록
int bookCount = 0;

// 도서 목록 초기화 함수
void initial_booklist() {
    FILE* file = fopen("books.txt", "r");
    if (file == NULL) {
        printf("도서 파일을 열 수 없습니다.\n");
        return;
    }

    char buffer[50]; // 제목(최대 30자) + 보유 권수 + 공백
    int lineCount = 0;

    // 첫 번째 줄(헤더) 건너뛰기
    fgets(buffer, sizeof(buffer), file);

    // 파일에서 도서 목록 읽기
    while (fgets(buffer, sizeof(buffer), file)) {
        int len = strlen(buffer);
        int i = len - 2; // '\n' 제외한 마지막 글자부터 시작

        // 보유 권수 추출 (문자가 아닌 숫자로 변환)
        int quantity = 0;
        while (i >= 0 && buffer[i] >= '0' && buffer[i] <= '9') {
            quantity = quantity * 10 + (buffer[i] - '0'); // 아스키 코드를 사용해서 문자를 숫자로 변환 (자리수가 1개가 아니어도 하나의 수로 인식)
            i--;
        }

        // 도서 목록을 동적으로 재할당
        bookList = (struct Book*)realloc(bookList, (bookCount + 1) * sizeof(struct Book));
        if (bookList == NULL) {
            printf("메모리 재할당에 실패했습니다.\n");
            fclose(file);
            return;
        }

        // 도서 제목 추출 (뒤에서부터 공백 제거)
        buffer[i + 1] = '\0';  // 숫자 뒤 제거
        int j = i; // 제목 끝 위치
        // 뒤쪽 공백 제거
        while (j >= 0 && (buffer[j] == ' ' || buffer[j] == '\t')) {
            j--;
        }
        // 제목 끝에서 공백까지 잘라내기
        buffer[j + 1] = '\0';  // 제목 끝을 올바르게 마무리

        // 도서 제목에 대해 동적 메모리 할당
        bookList[bookCount].title = (char*)malloc(strlen(buffer) + 1); // 제목 크기만큼 메모리 할당
        if (bookList[bookCount].title == NULL) {
            printf("메모리 할당에 실패했습니다.\n");
            fclose(file);
            return;
        }

        // 도서 정보 저장
        bookList[bookCount].quantity = quantity;  // 보유 권수 저장
        strcpy(bookList[bookCount].title, buffer); // 제목 저장
        bookList[bookCount].id = bookCount + 1;    // ID 부여

        bookCount++;
    }

    fclose(file);
}

// 도서 대여 관리 함수
void manage_booklist(int bookId) {
    for (int i = 0; i < bookCount; i++) {
        if (bookList[i].id == bookId) {
            if (bookList[i].quantity > 0) {
                bookList[i].quantity--;
                printf("'%s' 도서를 대여했습니다.\n", bookList[i].title);
                return;
            }
            else {
                printf("'%s' 도서는 모두 대여되어 대여할 수 없습니다.\n", bookList[i].title);
                return;
            }
        }
    }
    printf("해당 도서를 찾을 수 없습니다. 올바른 도서 ID를 입력하세요.\n");
}

// 메인 함수
void main() {
    int bookId;

    // 초기화
    initial_booklist();

    if (bookList == NULL) {
        printf("도서 목록을 초기화할 수 없습니다.\n");
        return;
    }

    // 보유 도서 목록 출력
    printf("[현재 보유 도서 목록]\n");
    printf("ID  보유권수 제목\n");
    for (int i = 0; i < bookCount; i++) {
        printf("%-3d %d권      %s\n", bookList[i].id, bookList[i].quantity, bookList[i].title);
    }

    // 사용자 입력 처리
    printf("\n대여를 원하는 도서의 ID를 입력하세요: ");
    if (scanf("%d", &bookId) == 1) {  // 사용자로부터 대여할 도서 ID를 int로 입력받음
        manage_booklist(bookId); // 대여 처리
    }
    else {
        printf("잘못된 입력입니다.\n");
    }

    // 동적 메모리 해제 후 종료
    for (int i = 0; i < bookCount; i++) {
        free(bookList[i].title);  // 각 도서 제목에 대한 메모리 해제
    }
    free(bookList);  // 동적 메모리 해제
    printf("프로그램을 종료합니다.\n");
}
