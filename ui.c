#include<stdio.h>
#include<stdlib.h>
#include "main.h"

//mainUI gotoXY�� ���� Ŀ�� ��ġ�� �����Ͽ� printf
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
    printf("������Ʈ�� version TM");
    gotoxy(25, 4);
    printf("Ű");
    gotoxy(25, 5);
    printf("q : 1��������");
    gotoxy(25, 6);
    printf("w : 2��������");
    gotoxy(25, 7);
    printf("e : 3��������");
    gotoxy(25, 8);
    printf("ENTER�� ���� �������ּ���");

    gotoxy(25, 9);
    printf("ESC : ����");
    gotoxy(25, 10);
    printf("���� : %d", playerscore);
    gotoxy(11, 9);
    printf("1��������");
    gotoxy(11, 10);
    printf("2��������");
    gotoxy(11, 11);
    printf("3��������");

    for (int i = 7; i < 53; i++) {
        gotoxy(i, 13);
        printf("-");
    }

    //ranking

    gotoxy(60, 2);
    printf("\t �ٷ�ŷ�� \t");
    gotoxy(60, 3);
    printf("-------------------");
    gotoxy(60, 4);
    if (userN == 0) {
        printf("��ŷ�� �������� �ʽ��ϴ�.");
        gotoxy(60, 5);
    }
    else {
        for (int i = 0; i < userN && i < 5; i++) {

            printf("%d. %s : %d��", i + 1, user[i].name, user[i].point);
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
                printf("��");
            else if (map[i][j] == PLAYER)
            {
                printf("��");
            }
            else if (map[i][j] == END)
            {
                printf("��");
            }
            else
                printf("  ");
        }
    }

    gotoxy(35, 23);
    printf("������Ʈ�� version TM");
    gotoxy(35, 24);
    printf("������ ���� ��� ������");
    gotoxy(35, 25);
    printf("����ϸ� ������ %d�� ����ϴ�", fan * 30);
    gotoxy(35, 26);
    printf("�����̽� : ����");
    gotoxy(35, 27);
    printf("�������� : esc");
    gotoxy(35, 28);
    printf("���� ���� : %d", playerscore);
    return;
}
