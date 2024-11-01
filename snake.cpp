#include "snake.h"
#include "board.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define INITIAL_LENGTH 1 // 뱀의 초기 길이

typedef struct {
    int x; // 뱀의 x 좌표
    int y; // 뱀의 y 좌표
} SnakePart;

SnakePart snake[100]; // 뱀의 몸통을 저장할 배열
int snake_length = INITIAL_LENGTH; // 뱀의 길이
int direction = 1; // 초기 방향 (1: 오른쪽, 2: 아래, 3: 왼쪽, 4: 위)


void init_snake() {
    snake[0].x = BOARD_SIZE / 2; // 초기 x 위치
    snake[0].y = BOARD_SIZE / 2; // 초기 y 위치
    board[snake[0].x][snake[0].y] = SNAKE; // 보드에 뱀 초기 위치 그리기
}

int check_food() {
    // 뱀의 머리와 먹이의 위치가 같은지 확인
    if (snake[0].x == food_x && snake[0].y == food_y) {
        return 1; // 먹이를 먹음
    }
    return 0; // 먹이를 먹지 않음
}

void update_snake() {
    // 이전 머리 위치 저장
    int prev_x = snake[snake_length-1].x;
    int prev_y = snake[snake_length-1].y;
    int temp_x, temp_y;
    
    // 방향에 따라 머리 위치 업데이트
    switch (direction) {
        case 1: // 오른쪽
        	for(int i = 0; i < snake_length; i++)
        		snake[i].y += 1;
            break;
        case 2: // 아래
            for(int i = 0; i < snake_length; i++)
				snake[i].x += 1;
			break;
        case 3: // 왼쪽
            for(int i = 0; i < snake_length; i++)
				snake[i].y -= 1;
            break;
        case 4: // 위
            for(int i = 0; i < snake_length; i++)
				snake[i].x -= 1;
            break;
    }

    // 먹이를 먹었는지 확인하고 길이 증가
    if (check_food()) {
        grow_snake(); // 길이 증가
        place_food(); // 새로운 먹이 위치
        //board[prev_x][prev_y] = EMPTY;
    } else {
        board[prev_x][prev_y] = EMPTY; // 이전 머리 위치 지우기
    }

    // 몸통 업데이트 (뒤에서 앞으로)
    for (int i = 1; i < snake_length; i++) {
        temp_x = snake[i].x;
        temp_y = snake[i].y;
        snake[i].x = prev_x;
        snake[i].y = prev_y;
        prev_x = temp_x;
        prev_y = temp_y;
    }

    // 보드에 뱀의 새로운 위치 업데이트
    board[snake[0].x][snake[0].y] = SNAKE;
}

int check_collision() {
    // 벽과 충돌 체크
    if (snake[0].x == 0 || snake[0].x == BOARD_SIZE - 1 || 
        snake[0].y == 0 || snake[0].y == BOARD_SIZE - 1) {
        return 1; // 벽과 충돌
    }

    // 자기 몸과 충돌 체크
    for (int i = 1; i < snake_length; i++) {
        if (snake[0].x == snake[i].x && snake[0].y == snake[i].y) {
            return 1; // 자기 몸과 충돌
        }
    }

    return 0; // 충돌 없음
}

void grow_snake() {
    // 뱀의 길이를 증가시키는 함수 (먹이를 먹었을 때 호출)
    snake_length++;
}


