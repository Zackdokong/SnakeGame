#include "snake.h"
#include "board.h"
#include "input.h"
#include <stdio.h>

int main() {
    init_board();      // ���� �ʱ�ȭ 
    init_snake();      // �� �ʱ�ȭ
    
    while (1) {
        draw_board();  // ���� �׸���
        process_input(); // �Է� ó��
        update_snake();  // �� �̵� ������Ʈ
        if (check_collision()) {  // �浹 üũ
            printf("Game Over!\n");
            break;
        }
    }
    return 0;
}

