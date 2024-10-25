#define _CRT_SECURE_NO_WARNINGS // 보안 경고를 무시하기 위한 매크로 정의
#include <stdio.h>
#include <stdlib.h> // 동적 메모리 할당을 위한 헤더 파일
#include <string.h> // 문자열 처리 함수 사용을 위한 헤더 파일
#include <time.h> // 시간 함수 사용을 위한 헤더 파일

// 카드 덱을 섞는 함수
int* Shuffle() {
    int* deck = (int*)malloc(sizeof(int) * 20); // 20장의 카드 덱 생성
    int card_check[14] = { 0 }; // 카드 중복 체크 배열 (1~13)

    // 카드 덱에 카드 추가
    for (int i = 0; i < 20; i++) {
        while (1) {
            int card = rand() % 13 + 1; // 1부터 13 사이의 카드 선택
            if (card_check[card] < 4) { // 최대 4장까지 허용
                deck[i] = card; // 카드 저장
                card_check[card]++; // 선택된 카드의 개수 증가
                break; // 카드가 성공적으로 추가되면 루프 종료
            }
        }
    }
    return deck; // 섞인 카드 덱 반환
}

// 플레이어와 딜러의 카드를 초기화하는 함수
void Initialization(int** playerHand, int** dealerHand, int* deck) {
    *playerHand = (int*)malloc(sizeof(int) * 2); // 플레이어 카드 핸드 초기화
    *dealerHand = (int*)malloc(sizeof(int) * 2); // 딜러 카드 핸드 초기화
    (*playerHand)[0] = deck[0]; // 첫 번째 플레이어 카드
    (*dealerHand)[0] = deck[1]; // 첫 번째 딜러 카드
    (*playerHand)[1] = deck[2]; // 두 번째 플레이어 카드
    (*dealerHand)[1] = deck[3]; // 두 번째 딜러 카드
}

// 현재 게임 상태를 체크하고 출력하는 함수
int status(int* playerHand, int* dealerHand, int playerCount, int dealerCount) {
    char* cards[] = { "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K" };
    int dealerSum = card_sum(dealerHand, dealerCount); // 딜러 카드 합 계산
    int playerSum = card_sum(playerHand, playerCount); // 플레이어 카드 합 계산

    // 카드 출력
    printf("Dealer : ");
    for (int i = 0; i < dealerCount; i++) {
        printf("%s ", cards[dealerHand[i] - 1]); // 딜러 카드 출력
    }
    printf("\nUser : ");
    for (int i = 0; i < playerCount; i++) {
        printf("%s ", cards[playerHand[i] - 1]); // 플레이어 카드 출력
    }
    printf("\n");

    // 상태 체크
    if (playerSum > 21) return 1; // 플레이어 버스트
    else if (dealerSum > 21) return 2; // 딜러 버스트
    else if (playerSum == 21) return 3; // 플레이어 블랙잭
    else if (dealerSum == 21) return 4; // 딜러 블랙잭
    else return 0; // 게임 진행 중
}

// 플레이어에게 카드를 추가하는 함수
int* Hit(int** playerHand, int* deck, int idx, int playerCount) {
    int* temp = realloc(*playerHand, sizeof(int) * (playerCount + 1)); // 메모리 재할당
    if (temp != NULL) *playerHand = temp; // 재할당 성공 시 포인터 업데이트
    (*playerHand)[playerCount] = deck[idx]; // 카드 추가
    return *playerHand; // 업데이트된 플레이어 핸드 반환
}

// 딜러에게 카드를 추가하는 함수
int* End(int** dealerHand, int* deck, int idx, int dealerCount) {
    int* temp = realloc(*dealerHand, sizeof(int) * (dealerCount + 1)); // 메모리 재할당
    if (temp != NULL) *dealerHand = temp; // 재할당 성공 시 포인터 업데이트
    (*dealerHand)[dealerCount] = deck[idx]; // 카드 추가
    return *dealerHand; // 업데이트된 딜러 핸드 반환
}

// 게임 결과를 출력하는 함수
void Result(int* playerHand, int* dealerHand, int playerCount, int dealerCount) {
    int playerSum = card_sum(playerHand, playerCount); // 플레이어 카드 합
    int dealerSum = card_sum(dealerHand, dealerCount); // 딜러 카드 합

    // 승패 판별
    if (playerSum > dealerSum) printf("User Wins! Congratulation!\n");
    else if (playerSum < dealerSum) printf("User Lose. Dealer Wins\n");
    else printf("Draw!\n");

    free(playerHand); // 플레이어 핸드 메모리 해제
    free(dealerHand); // 딜러 핸드 메모리 해제
}

// 카드의 합계를 계산하는 함수
int card_sum(int* card, int cardCount) {
    int sum = 0; // 카드 합계 초기화
    for (int i = 0; i < cardCount; i++) {
        sum += (card[i] > 10) ? 10 : card[i]; // 10보다 큰 카드(J, Q, K)는 10으로 계산
    }
    return sum; // 카드의 총 합계 반환
}

int main(void) {
    srand((unsigned int)time(NULL)); // 랜덤 시드 초기화

    while (1) {
        printf("==============================\n");
        printf("Game Start?(Start/End) "); // 게임 시작 여부 입력 요청
        char command[10] = { 0 }; // 사용자 입력 저장 변수
        int cardIndex = 0; // 카드 인덱스 초기화
        int playerCardCount = 0; // 플레이어 카드 수 초기화
        int dealerCardCount = 0; // 딜러 카드 수 초기화
        int gameStatus = 0; // 게임 상태 초기화
        scanf("%s", command); // 사용자 입력 받기
        if (!strcmp(command, "End")) // "End" 입력 시 게임 종료
            break;

        else if (!strcmp(command, "Start")) { // "Start" 입력 시 게임 시작
            int* deck = Shuffle(); // 카드 덱 섞기
            int* playerHand = NULL; // 플레이어 핸드 초기화
            int* dealerHand = NULL; // 딜러 핸드 초기화
            Initialization(&playerHand, &dealerHand, deck); // 카드 초기화
            playerCardCount += 2; // 플레이어 카드 수 증가
            dealerCardCount += 2; // 딜러 카드 수 증가
            cardIndex += 4; // 카드 인덱스 증가
            gameStatus = status(playerHand, dealerHand, playerCardCount, dealerCardCount); // 초기 상태 체크

            while (1) {
                printf("More Card?(Hit/Stay) "); // 추가 카드 요청
                char action[10] = { 0 }; // 사용자 입력 저장 변수
                scanf("%s", action); // 사용자 입력 받기

                if (!strcmp(action, "Hit")) { // "Hit" 입력 시 카드 추가
                    playerHand = Hit(&playerHand, deck, cardIndex, playerCardCount); // 카드 추가
                    cardIndex++; // 카드 인덱스 증가
                    playerCardCount++; // 플레이어 카드 수 증가

                    // 플레이어 카드 합계 체크
                    if (card_sum(playerHand, playerCardCount) > 21) {
                        status(playerHand, dealerHand, playerCardCount, dealerCardCount); // 최종 카드 상태 출력
                        printf("Busted! Over21! Dealer Wins.\n");
                        break; // 플레이어가 21 초과 시 게임 종료
                    }
                    else if (card_sum(playerHand, playerCardCount) == 21) {
                        status(playerHand, dealerHand, playerCardCount, dealerCardCount); // 최종 카드 상태 출력
                        printf("Blackjack! Winner Winner Chicken Dinner! User Win!\n");
                        break; // 플레이어가 21일 경우 게임 종료
                    }

                    // 딜러의 카드 합계가 16 이하일 경우 카드 추가
                    if (card_sum(dealerHand, dealerCardCount) <= 16) {
                        dealerHand = End(&dealerHand, deck, cardIndex, dealerCardCount); // 딜러에게 카드 추가
                        cardIndex++; // 카드 인덱스 증가
                        dealerCardCount++; // 딜러 카드 수 증가
                    }

                    gameStatus = status(playerHand, dealerHand, playerCardCount, dealerCardCount); // 상태 체크

                    if (gameStatus == 2) {
                        printf("User Wins! Dealer Busted!\n"); // 딜러가 버스트 시
                        break;
                    }
                    if (gameStatus == 4) {
                        printf("Blackjack! User Lose.\n"); // 딜러가 블랙잭 시
                        break;
                    }
                }
                else if (!strcmp(action, "Stay")) { // "Stay" 입력 시
                    // 딜러의 카드 합계가 16 이하일 경우 카드 추가
                    while (card_sum(dealerHand, dealerCardCount) <= 16) {
                        dealerHand = End(&dealerHand, deck, cardIndex, dealerCardCount); // 딜러에게 카드 추가
                        cardIndex++; // 카드 인덱스 증가
                        dealerCardCount++; // 딜러 카드 수 증가
                    }
                    gameStatus = status(playerHand, dealerHand, playerCardCount, dealerCardCount); // 상태 체크

                    if (gameStatus == 2) {
                        printf("User Wins! Dealer Busted!\n"); // 딜러가 버스트 시
                    }
                    else if (gameStatus == 4) {
                        printf("Blackjack! User Lose.\n"); // 딜러가 블랙잭 시
                    }
                    else {
                        Result(playerHand, dealerHand, playerCardCount, dealerCardCount); // 최종 결과 출력
                    }
                    break; // 추가 카드 요청 종료
                }
                else {
                    printf("Error : Wrong Input, Try Again.\n"); // 잘못된 입력 처리
                }
            }
        }
        else {
            printf("Error : Wrong Input, Try Again.\n"); // 잘못된 입력 처리
        }
    }
    printf("==============================\n");
    return 0; // 프로그램 종료
}
