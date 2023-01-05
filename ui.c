#include<stdio.h>
#include<stdlib.h>
#include "main.h"

//mainUI gotoXY를 통해 커서 위치를 변경하여 printf
void mainUI(User user[], int userN) {
    for (int i = 7; i < 53; i++) {
        gotoxy(i, 0);
        printf("-");
    }
    for (int i = 1; i < 13; i++) {
        gotoxy(6, i);
        printf("|");
    }
    for (int i = 1; i < 13; i++) {
        gotoxy(53, i);
        printf("|");
    }
    gotoxy(10, 2);
    printf("지오메트리 version TM");
    gotoxy(25, 4);
    printf("키");
    gotoxy(25, 5);
    printf("q : 1스테이지");
    gotoxy(25, 6);
    printf("w : 2스테이지");
    gotoxy(25, 7);
    printf("e : 3스테이지");
    gotoxy(25, 8);
    printf("ENTER를 눌러 실행해주세요");

    gotoxy(25, 9);
    printf("ESC : 종료");
    gotoxy(25, 10);
    printf("점수 : %d", playerscore);
    gotoxy(11, 9);
    printf("1스테이지");
    gotoxy(11, 10);
    printf("2스테이지");
    gotoxy(11, 11);
    printf("3스테이지");

    for (int i = 7; i < 53; i++) {
        gotoxy(i, 13);
        printf("-");
    }

    //ranking

    gotoxy(60, 2);
    printf("\t ☆랭킹☆ \t");
    gotoxy(60, 3);
    printf("-------------------");
    gotoxy(60, 4);
    if (userN == 0) {
        printf("랭킹이 존재하지 않습니다.");
        gotoxy(60, 5);
    }
    else {
        for (int i = 0; i < userN && i < 5; i++) {

            printf("%d. %s : %d점", i + 1, user[i].name, user[i].point);
            gotoxy(60, 5 + i);
        }
    }

    printf("-------------------");


}

void gameUI(int map[MAPSIZEY][MAPSIZEX], int type) {
    for (int i = 0; i < MAPSIZEY; i++) {
        for (int j = 0; j < MAPSIZEX; j++) {
            if (map[i][j] == PLAYER) {
                x = j;
                y = i;
                break;
            }
        }
    }
    for (int i = 0; i < MAPSIZEY; i++)
    {
        for (int j = 0; j < MAPSIZEX; j++)
        {
            gotoxy(j * 2, i);
            if (map[i][j] == WALL)
                printf("■");
            else if (map[i][j] == PLAYER)
            {
                printf("★");
            }
            else if (map[i][j] == END)
            {
                printf("♠");
            }
            else
                printf("  ");
        }
    }

    gotoxy(35, 23);
    printf("지오메트리 version TM");
    gotoxy(35, 24);
    printf("점프를 통해 통과 지점을");
    gotoxy(35, 25);
    printf("통과하면 점수를 %d점 얻습니다", fan * 30);
    gotoxy(35, 26);
    printf("스페이스 : 점프");
    gotoxy(35, 27);
    printf("메인으로 : esc");
    gotoxy(35, 28);
    printf("현재 점수 : %d", playerscore);
    return;
}
