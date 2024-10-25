#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 좌표 평면 출력 함수
void print_plane(int x, int y) {
    // y축을 위에서 아래로 출력 (-2, -1, 1, 2)
    for (int i = 2; i >= -2; i--) { // y좌표
        // x축을 왼쪽에서 오른쪽으로 출력 (-2, -1, 1, 2)
        for (int j = -2; j <= 2; j++) { // x좌표
            // i 또는 j가 0이면 출력 안함
            if (i == 0 || j == 0) {
                continue;
            }
            else if (i == y && j == x) {
                printf("X "); // 입력된 좌표에 'X' 표시
            }
            else {
                printf("O "); // 나머지 부분에 'O' 표시
            }
        }
        if (i == 0) {
            continue; // i=0인 행은 줄 바꿈 안함
        }
        else {
            printf("\n"); // 다른 행은 줄 바꿈
        }
    }
}

// X축 대칭 변환 함수
void reflect_x(int* y) {
    *y = -(*y); // y좌표를 반전
}

// Y축 대칭 변환 함수
void reflect_y(int* x) {
    *x = -(*x); // x좌표를 반전
}

// 원점 대칭 변환 함수
void reflect_origin(int* x, int* y) {
    *x = -(*x); // x좌표 반전
    *y = -(*y); // y좌표 반전
}

int main() {
    int x, y;
    int original_x, original_y;

    // 사용자로부터 좌표 입력 받기
    printf("x좌표와 y좌표를 입력하세요 (-2, -1, 1, 2): ");
    scanf("%d %d", &x, &y);

    // 입력된 좌표가 유효한지 확인
    while (x != -2 && x != -1 && x != 1 && x != 2) {
        printf("유효하지 않은 x좌표입니다. (-2, -1, 1, 2) 중 하나를 입력하세요: ");
        scanf("%d", &x);
    }
    while (y != -2 && y != -1 && y != 1 && y != 2) {
        printf("유효하지 않은 y좌표입니다. (-2, -1, 1, 2) 중 하나를 입력하세요: ");
        scanf("%d", &y);
    }

    original_x = x;  // 원래 x좌표 저장 (포인터는 값이 아예 바뀌기 때문에 original_x가 없다면 x축 대칭한 값을 다시 y축 대칭하고, 다시 원점 대칭함)
    original_y = y;  // 원래 y좌표 저장

    // 입력 좌표 평면 출력
    printf("입력한 좌표 평면:\n");
    print_plane(original_x, original_y);

    // X축 대칭 결과 출력
    reflect_x(&y);
    printf("X축 대칭 결과:\n");
    print_plane(original_x, y);

    // Y축 대칭 결과 출력
    reflect_y(&x);
    printf("Y축 대칭 결과:\n");
    print_plane(x, original_y);

    // 원점 대칭 결과 출력
    reflect_origin(&original_x, &original_y);
    printf("원점 대칭 결과:\n");
    print_plane(original_x, original_y);

    return 0;
}