#ifndef SNAKE_H
#define SNAKE_H

#define BOARD_SIZE 30 // 보드 크기 정의
#define SNAKE 'O' // 뱀 문자 정의

// 보드 배열 외부 선언
extern char board[BOARD_SIZE][BOARD_SIZE];
extern int direction;

// 함수 선언
void init_snake();
void update_snake();
int check_collision();
void grow_snake();

#endif // SNAKE_H

