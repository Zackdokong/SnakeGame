#include "board.h"
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

#define BOARD_SIZE 30
#define EMPTY ' '   // �� ����
#define WALL '#'    // ��
#define SNAKE 'O'   // ��
#define FOOD '*'     // ���� 

char board[BOARD_SIZE][BOARD_SIZE];  // ���� ���� �迭
int food_x, food_y;

void init_board() {
    // ���� �ʱ�ȭ: �� �������� ä��� �� ����
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (i == 0 || i == BOARD_SIZE - 1 || j == 0 || j == BOARD_SIZE - 1) {
                board[i][j] = WALL; // �����ڸ� ��
            } else {
                board[i][j] = EMPTY; // �� ����
            }
        }
    }
    place_food();
}

void draw_board() {
	system("cls"); //������ �׸� ���� ����� 
	
    // ���� �׸���
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    
    Sleep(16); // ȭ���� �ʹ� �����ŷ��� �ణ ������ �� 
}

// ���� ��ġ�� ���忡 ǥ���ϴ� �Լ�
void place_food() {
    // ���̸� ������ ��ġ�� ��ġ
    do {
        food_x = rand() % (BOARD_SIZE - 2) + 1; // ���� ������ ���ο��� ��ġ
        food_y = rand() % (BOARD_SIZE - 2) + 1;
    } while (board[food_x][food_y] != EMPTY); // �� ������ ���� ��ġ
    board[food_x][food_y] = FOOD; // ���忡 ���� ��ġ
}

