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
                direction = 4; // ���� ����
                break;
            case DOWN_KEY:
                direction = 2; // ���� �Ʒ���
                break;
            case LEFT_KEY:
                direction = 3; // ���� ��������
                break;
            case RIGHT_KEY:
                direction = 1; // ���� ����������
                break;
        }
    }
}


