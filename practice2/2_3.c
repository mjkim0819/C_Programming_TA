#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 전역 변수로 원주율 설정
const double PI = 3.14;  // 부동소수점으로 인해 발생하는 문제를 해결하기 위해 double형태 사용
// 컴퓨터는 이진법을 사용하기 때문에 소수를 표현하고 연산하는데 어려움이 있음
// 소수는 정확한 값이 아니라 근사치로 표현하는데 그 과정에서 오차가 발생
// float(7자리 유효숫자)보다 double(15~16자리 유효숫자)이 더 정확하게 표현 가능 

// 원의 넓이를 구하는 함수
double calculate_area(double radius) {
    return PI * radius * radius;
}

// 원의 둘레를 구하는 함수
double calculate_circumference(double radius) {
    return 2 * PI * radius;
}

int main() {
    double radius, area, circumference;  // float 대신 double 사용

    // 사용자로부터 반지름 입력 받기
    printf("넓이/둘레를 구할 원의 반지름을 입력하시오 : ");
    scanf("%lf", &radius);  // double 입력 받기 위한 %lf

    // 넓이와 둘레 계산
    area = calculate_area(radius);
    circumference = calculate_circumference(radius);

    // 결과 출력
    printf("입력한 반지름 : %.0f 에 대한\n", radius); //실수를 정수형으로 출력하기 위해 %.0f 사용
    printf("원의 넓이는 %.6f\n", area);
    printf("원의 둘레는 %.6f\n", circumference);  //소수점 6자리까지 출력하기 위해 %.6f 사용

    return 0;
}