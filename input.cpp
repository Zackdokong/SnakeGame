#include "input.h"
#include <conio.h>

#define UP_KEY 72
#define DOWN_KEY 80
#define LEFT_KEY 75
#define RIGHT_KEY 77

void process_input() {
    if (_kbhit()) {
        switch (_getch()) {
            case UP_KEY:
                if(direction != 2) direction = 4; // 방향 위로
                break;
            case DOWN_KEY:
                if(direction != 4) direction = 2; // 방향 아래로
                break;
            case LEFT_KEY:
                if(direction != 1) direction = 3; // 방향 왼쪽으로
                break;
            case RIGHT_KEY:
                if(direction != 3) direction = 1; // 방향 오른쪽으로
                break;
        }
    }
}


