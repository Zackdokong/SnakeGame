#ifndef SNAKE_H
#define SNAKE_H

#define BOARD_SIZE 30 // ���� ũ�� ����
#define SNAKE 'O' // �� ���� ����

// ���� �迭 �ܺ� ����
extern char board[BOARD_SIZE][BOARD_SIZE];
extern int direction;

// �Լ� ����
void init_snake();
void update_snake();
int check_collision();
void grow_snake();

#endif // SNAKE_H

