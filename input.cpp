#include "input.h"
#include <conio.h>

#define UP_KEY 72
#define DOWN_KEY 80
#define LEFT_KEY 75
#define RIGHT_KEY 77

void process_input() {
    if (_kbhit()) { // 키가 눌렸는지 확인
        switch (_getch()) {
            case UP_KEY:
                if (direction != 1) direction = 3; // 아래로 향할 수 없게 막기
                break;
            case DOWN_KEY:
                if (direction != 3) direction = 1; // 위로 향할 수 없게 막기
                break;
            case LEFT_KEY:
                if (direction != 0) direction = 2; // 오른쪽으로 향할 수 없게 막기
                break;
            case RIGHT_KEY:
                if (direction != 2) direction = 0; // 왼쪽으로 향할 수 없게 막기
                break;
        }
    }
}

