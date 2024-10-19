#ifndef BOARD_H
#define BOARD_H

#define BOARD_SIZE 30 // 보드 크기 정의
#define EMPTY ' '     // 빈 공간 문자 정의
#define WALL '#'      // 벽 문자 정의
#define SNAKE 'O'    // 뱀 문자 정의
#define FOOD '*'      // 먹이 문자 정의

extern char board[BOARD_SIZE][BOARD_SIZE]; // 보드 배열 외부 선언
extern int food_x; 
extern int food_y;

void init_board(); // 보드 초기화 함수 선언
void draw_board(); // 보드 그리기 함수 선언
void place_food(); // 먹이 배치 함수 선언

#endif // BOARD_H

