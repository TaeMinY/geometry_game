
#include <windows.h>
#include "main.h"

// 화면에서 커서 숨기는 함수
void removecursor(void)
{
    CONSOLE_CURSOR_INFO cursorInfo = { 0, };
    cursorInfo.dwSize = 1;
    cursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

// cursur position
void gotoxy(int x, int y) {
    COORD P;
    P.X = x;
    P.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), P);
}

//버블정렬 사용
void sort(User a[], int num) {
    for (int i = 1; i < num; i++) {
        for (int j = 0; j < num - i; j++) {
            if (a[j].point < a[j + 1].point) {
                swap(a + j, a + j + 1);
            }
        }
    }
    int k = 1;
}

//swap 함수
void swap(User* user1, User* user2) {
    User tmp;
    tmp = *user1;
    *user1 = *user2;
    *user2 = tmp;
}
