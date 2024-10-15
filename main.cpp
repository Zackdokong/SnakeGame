#include "snake.h"
#include "board.h"
#include "input.h"
#include <stdio.h>

int main() {
    init_board();      // 보드 초기화 
    init_snake();      // 뱀 초기화
    
    while (1) {
        draw_board();  // 보드 그리기
        process_input(); // 입력 처리
        update_snake();  // 뱀 이동 업데이트
        if (check_collision()) {  // 충돌 체크
            printf("Game Over!\n");
            break;
        }
    }
    return 0;
}

