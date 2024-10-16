#include "snake.h"
#include "board.h"
#include <stdio.h>

#define INITIAL_LENGTH 1 // ���� �ʱ� ����

typedef struct {
    int x; // ���� x ��ǥ
    int y; // ���� y ��ǥ
} SnakePart;

SnakePart snake[100]; // ���� ������ ������ �迭
int snake_length = INITIAL_LENGTH; // ���� ����
int direction = 1; // �ʱ� ���� (1: ������, 2: �Ʒ�, 3: ����, 4: ��)

void init_snake() {
    snake[0].x = BOARD_SIZE / 2; // �ʱ� x ��ġ
    snake[0].y = BOARD_SIZE / 2; // �ʱ� y ��ġ
    board[snake[0].x][snake[0].y] = SNAKE; // ���忡 �� �ʱ� ��ġ �׸���
}

void update_snake() {
    // ���� �Ӹ� ��ġ ����
    int prev_x = snake[0].x;
    int prev_y = snake[0].y;
    int temp_x, temp_y;
    
    // ���⿡ ���� �Ӹ� ��ġ ������Ʈ
    switch (direction) {
    case 0: // ������
        snake[0].y += 1;
        break;
    case 1: // �Ʒ�
        snake[0].x += 1;
        break;
    case 2: // ����
        snake[0].y -= 1;
        break;
    case 3: // ��
        snake[0].x -= 1;
        break;
}
    
    board[prev_x][prev_y] = EMPTY;

    // ���� ������Ʈ (�ڿ��� ������)
    for (int i = 1; i < snake_length; i++) {
        temp_x = snake[i].x;
        temp_y = snake[i].y;
        snake[i].x = prev_x;
        snake[i].y = prev_y;
        prev_x = temp_x;
        prev_y = temp_y;
    }

    // ���忡 ���� ���ο� ��ġ ������Ʈ
    board[snake[0].x][snake[0].y] = SNAKE;
}

int check_collision() {
    // ���� �浹 üũ
    if (snake[0].x == 0 || snake[0].x == BOARD_SIZE - 1 || 
        snake[0].y == 0 || snake[0].y == BOARD_SIZE - 1) {
        return 1; // ���� �浹
    }

    // �ڱ� ���� �浹 üũ
    for (int i = 1; i < snake_length; i++) {
        if (snake[0].x == snake[i].x && snake[0].y == snake[i].y) {
            return 1; // �ڱ� ���� �浹
        }
    }

    return 0; // �浹 ����
}

void grow_snake() {
    // ���� ���̸� ������Ű�� �Լ� (���̸� �Ծ��� �� ȣ��)
    snake_length++;
    // ���ο� ��ġ�� ���� �� �κ��� �߰��ϴ� ������ �ۼ��� �� ����
}

