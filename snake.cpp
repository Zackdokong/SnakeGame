#include "snake.h"
#include "board.h"
#include <stdio.h>

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

void update_snake() {
    // 이전 머리 위치 저장
    int prev_x = snake[0].x;
    int prev_y = snake[0].y;
    int temp_x, temp_y;
    
    // 방향에 따라 머리 위치 업데이트
    switch (direction) {
    case 0: // 오른쪽
        snake[0].y += 1;
        break;
    case 1: // 아래
        snake[0].x += 1;
        break;
    case 2: // 왼쪽
        snake[0].y -= 1;
        break;
    case 3: // 위
        snake[0].x -= 1;
        break;
}
    
    board[prev_x][prev_y] = EMPTY;

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
    // 새로운 위치에 뱀의 끝 부분을 추가하는 로직을 작성할 수 있음
}

