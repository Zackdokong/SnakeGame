#ifndef BOARD_H
#define BOARD_H

#define BOARD_SIZE 30 // ���� ũ�� ����
#define EMPTY ' '     // �� ���� ���� ����
#define WALL '#'      // �� ���� ����
#define SNAKE 'O'    // �� ���� ����
#define FOOD '*'      // ���� ���� ����

extern char board[BOARD_SIZE][BOARD_SIZE]; // ���� �迭 �ܺ� ����
extern int food_x; 
extern int food_y;

void init_board(); // ���� �ʱ�ȭ �Լ� ����
void draw_board(); // ���� �׸��� �Լ� ����
void place_food(); // ���� ��ġ �Լ� ����

#endif // BOARD_H

