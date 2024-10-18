#include "board.h"
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define BOARD_SIZE 30
#define EMPTY ' '   // 빈 공간
#define WALL '#'    // 벽
#define SNAKE 'O'   // 뱀
#define FOOD '*'     // 먹이 

char board[BOARD_SIZE][BOARD_SIZE];  // 게임 보드 배열

void init_board() {
    // 보드 초기화: 빈 공간으로 채우고 벽 생성
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (i == 0 || i == BOARD_SIZE - 1 || j == 0 || j == BOARD_SIZE - 1) {
                board[i][j] = WALL; // 가장자리 벽
            } else {
                board[i][j] = EMPTY; // 빈 공간
            }
        }
    }
}

void draw_board() {
	system("cls"); //이전에 그린 내용 지우기 
	
    // 보드 그리기
    // 깜빡거림 해결위해서 뱀만 그리게해야됨
	// 버퍼에 다 그려놓고 한번에 출력하는 방법도 있음 
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
        	printf("%c ", board([i][j]);
        }
        printf("\n");
    }
    
    Sleep(1); // 화면이 너무 깜빡거려서 약간 딜레이 줌 
}

// 먹이 위치를 보드에 표시하는 함수
void place_food(int food_x, int food_y) {
    board[food_x][food_y] = FOOD;  // 먹이 위치에 먹이 배치
}

printf("집 가고 싶다....");

