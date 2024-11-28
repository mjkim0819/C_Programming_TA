#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <malloc.h>  // 동적 메모리 할당을 위한 라이브러리

#define MAX_BOOKS 1000
#define MAX_LINE_LENGTH 256
#define ID_LEN 20
#define PW_LEN 20

struct Book {
    int id;             // 도서 ID
    char* title;        // 도서 제목 (동적 할당)
    int quantity;       // 보유 권수
};

struct Book* bookList = NULL;  // 동적으로 할당된 도서 목록
struct Book* storageList = NULL; // 동적으로 할당된 창고 도서 목록
int bookCount = 0;
int storageCount = 0;

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
        if (buffer[len - 1] != '\n') i++;
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

// 도서 현황 출력 함수
void print_booklist() {
    if (bookList == NULL) {
        printf("도서 목록을 초기화할 수 없습니다.\n");
        return;
    }

    printf("[현재 보유 도서 목록]\n");
    printf("ID  보유권수 제목\n");
    for (int i = 0; i < bookCount; i++) {
        printf("%-3d %d권      %s\n", bookList[i].id, bookList[i].quantity, bookList[i].title);
    }
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

// 관리자 로그인 처리
int admin_check() {
    char input_id[ID_LEN], input_pw[PW_LEN];
    char admin_id[ID_LEN], admin_pw[PW_LEN];
    FILE* file = fopen("admin_auth.txt", "r");

    if (file == NULL) {
        printf("admin_auth.txt 파일을 열 수 없습니다.\n");
        return 0;
    }

    // 파일에서 관리자 ID/PW 읽기
    fscanf(file, "ID %s", admin_id);
    fscanf(file, "\nPW %s", admin_pw);
    fclose(file);

    printf("관리자 ID: ");
    scanf("%s", input_id);
    printf("관리자 PW: ");
    scanf("%s", input_pw);

    if (strcmp(admin_id, input_id) == 0 && strcmp(admin_pw, input_pw) == 0) {
        return 1;
    }
    return 0;
}

// 창고 초기화 함수
void initial_storage() {
    FILE* file = fopen("storage.txt", "r");
    if (file == NULL) {
        printf("창고 파일을 열 수 없습니다.\n");
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
        if (buffer[len - 1] != '\n') i++;
        // 보유 권수 추출 (문자가 아닌 숫자로 변환)

        char number[MAX_LINE_LENGTH];
        int number_index = 0;

        // 숫자 부분만 추출
        while (i >= 0 && buffer[i] >= '0' && buffer[i] <= '9') {
            number[number_index++] = buffer[i];
            i--;
        }
        number[number_index] = '\0';

        // 추출한 숫자를 뒤집어서 정수로 변환
        int quantity = 0;
        for (int j = number_index - 1; j >= 0; j--) {
            quantity = quantity * 10 + (number[j] - '0');
        }

        // 도서 목록을 동적으로 재할당
        storageList = (struct Book*)realloc(storageList, (storageCount + 1) * sizeof(struct Book));
        if (storageList == NULL) {
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
        storageList[storageCount].title = (char*)malloc(strlen(buffer) + 1); // 제목 크기만큼 메모리 할당
        if (storageList[storageCount].title == NULL) {
            printf("메모리 할당에 실패했습니다.\n");
            fclose(file);
            return;
        }

        // 도서 정보 저장
        storageList[storageCount].quantity = quantity;  // 보유 권수 저장
        strcpy(storageList[storageCount].title, buffer); // 제목 저장
        storageList[storageCount].id = storageCount + 1;    // ID 부여

        storageCount++;
    }

    fclose(file);
}

// 창고 현황 출력
void print_storage() {
    printf("\n[창고 현황]\n");
    printf("ID  잔여권수 제목\n");
    for (int i = 0; i < storageCount; i++) {
        printf("%-3d %d권      %s\n", storageList[i].id, storageList[i].quantity, storageList[i].title);
    }
}

// 재고 확장 기능
void expand_inventory_from_storage() {
    printf("\n[재고 확장 작업 시작]\n");
    for (int i = 0; i < bookCount; i++) {
        if (bookList[i].quantity == 0) { // 보유 도서가 0인 경우
            for (int j = 0; j < storageCount; j++) {
                if (strcmp(bookList[i].title, storageList[j].title) == 0) {
                    int transferCount = (storageList[j].quantity >= 3) ? 3 : storageList[j].quantity;
                    bookList[i].quantity += transferCount;    // 보유 도서에 3권 추가
                    storageList[j].quantity -= transferCount; // 창고 재고 감소
                    printf("'%s' 도서: 창고에서 %d권 가져와 보유 도서 재고를 %d권으로 확장\n",
                        bookList[i].title, transferCount, bookList[i].quantity);
                    break;
                }
            }
        }
    }
    printf("[재고 확장 작업 완료]\n");
}

// 메인 함수
void main(int argc, char* argv[]) {

    if (argc > 1 && strcmp(argv[1], "관리자") == 0) {
        printf("관리자 모드에 진입합니다.\n");

        if (admin_check()) {
            printf("관리자 인증 성공!\n");
            // 초기화
            initial_booklist();
            initial_storage();

            // 도서 목록 출력
            print_booklist();
            print_storage();

            // 도서 채우기
            expand_inventory_from_storage();

            // 채운후 결과
            printf("\n===================부족한 도서 채운 후 결과===================\n");
            print_booklist();
            print_storage();

            char choice;
            printf("서비스 모드로 전환하시겠습니까? (y/n): ");
            scanf(" %c", &choice);

            if (choice == 'y' || choice == 'Y') {
                printf("서비스 모드로 전환합니다.\n");
                int bookId;

                // 사용자 입력 처리
                printf("\n대여를 원하는 도서의 ID를 입력하세요: ");
                if (scanf("%d", &bookId) == 1) {  // 사용자로부터 대여할 도서 ID를 int로 입력받음
                    manage_booklist(bookId); // 대여 처리
                }
                else {
                    printf("잘못된 입력입니다.\n");
                }
            }
            else {
                printf("프로그램을 종료합니다.\n");
                return;
            }
        }
        else {
            printf("관리자 인증 실패! 프로그램을 종료합니다.\n");
            return;
        }
    }
    else {
        printf("관리자 모드로 실행되지 않았습니다.\n");
        return;
    }

    // 동적 메모리 해제 후 종료
    for (int i = 0; i < bookCount; i++) {
        free(bookList[i].title);  // 각 도서 제목에 대한 메모리 해제
    }
    free(bookList);  // 동적 메모리 해제
    printf("프로그램을 종료합니다.\n");
}
