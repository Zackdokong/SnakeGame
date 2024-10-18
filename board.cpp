#include "board.h"
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define BOARD_SIZE 30
#define EMPTY ' '   // �� ����
#define WALL '#'    // ��
#define SNAKE 'O'   // ��
#define FOOD '*'     // ���� 

char board[BOARD_SIZE][BOARD_SIZE];  // ���� ���� �迭

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
}

void draw_board() {
	system("cls"); //������ �׸� ���� ����� 
	
    // ���� �׸���
    // �����Ÿ� �ذ����ؼ� �츸 �׸����ؾߵ�
	// ���ۿ� �� �׷����� �ѹ��� ����ϴ� ����� ���� 
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
        	printf("%c ", board([i][j]);
        }
        printf("\n");
    }
    
    Sleep(1); // ȭ���� �ʹ� �����ŷ��� �ణ ������ �� 
}

// ���� ��ġ�� ���忡 ǥ���ϴ� �Լ�
void place_food(int food_x, int food_y) {
    board[food_x][food_y] = FOOD;  // ���� ��ġ�� ���� ��ġ
}

printf("�� ���� �ʹ�....");

