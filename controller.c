#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include <stdlib.h>
#include<string.h>

#include "main.h"

//mainController �Լ� ����
int mainController() {

    if (_kbhit() != 0) { //Ű������ �Է� ���� Ȯ��
        int key;
        key = _getch(); //�Էµ� Ű�� �ƽ�Ű�ڵ� ��
        if (key == 'q' || key == 'Q') {
            gotoxy(9, 11);
            printf("  ");
            gotoxy(9, 10);
            printf("  ");
            gotoxy(9, 9);
            printf("��");
            //int key = 0;
            m = 1;
            fan = 1;
        }
        else if (key == 'w' || key == 'W') {
            gotoxy(9, 9);
            printf("  ");
            gotoxy(9, 10);
            printf("��");
            gotoxy(9, 11);
            printf("  ");
            //int key = 0;
            m = 1;
            fan = 2;
        }
        else if (key == 'e' || key == 'E') {
            gotoxy(9, 9);
            printf("  ");
            gotoxy(9, 10);
            printf("  ");
            gotoxy(9, 11);
            printf("��");
            //int key = 0;
            m = 1;
            fan = 3;
        }
        else if (key == 27) {
            system("cls");
            int c;
            gotoxy(0, 0);

            //���� ������ ����� ��
            printf("������ �����Ͻðڽ��ϱ�? (yes : 1, no : 1�� ������ ����) : ");
            scanf_s("%d", &c);

            //���� �÷��̾� ����
            User user = { playerscore , "" };
            if (c == 1) {

                //����� �г��� �Է�
                printf("���� �� �г����� �Է����ּ���(+�� -�� �Է� �����Դϴ�.) : ");
                scanf_s("%s", &user.name, 30);

                while (regexName(user.name)) {
                    printf("���� �� �г����� �ٽ� �Է����ּ���(+�� -�� �Է� �����Դϴ�.) : ");
                    scanf_s("%s", &user.name, 30);
                }

                //rank_result�� Ÿ�� a�� �޾� ��������, ���� ���ٸ� ����
                FILE* fp;
                errno_t err;

                err = fopen_s(&fp, "rank_result.txt", "a");
                if (err == 0)
                {
                    char text[100] = ""; //���Ͽ� �߰� �� �ؽ�Ʈ
                    char pointt[10];

                    //user point�� pointt������ char������ �����Ͽ� ����
                    _itoa_s(user.point, pointt, sizeof(pointt), 10);

                    //text�� user.name�� point ���̿� +�� �־� ������ ���� �� �ֵ��� �ϰ� �������� -�� �־� �ٸ� ������ ������ �� �ֵ��� �Ѵ�.
                    strcat_s(text, sizeof(text), user.name);
                    strcat_s(text, sizeof(text), "+");
                    strcat_s(text, sizeof(text), pointt);
                    strcat_s(text, sizeof(text), "-");

                    //���Ͽ� �Է��ϴ� ����
                    // fwrite(text, sizeof(char), strlen(text), fp);
                    fputs(text, fp);

                    //���� �ݱ�
                    fclose(fp);
                    printf("������ �Ϸ�Ǿ����ϴ�. ������ �����մϴ�.");
                }
                else {
                    printf("�����ϴ� ���� ������ �߻��Ͽ� �������� ���Ͽ����ϴ�.");
                }
                exit(1);
            }
            else {
                printf("������ �����ϼ̽��ϴ�.\n");
                exit(1);
            }

        }
        else if (key == 13)
        {
            if (m == 1) {
                return 1;
            }
        }
        return 0;
    }
    return 0;
}

int GameController(int map[MAPSIZEY][MAPSIZEX], int type)
{
    int key;
    int enterStatus = 0;


    //Ű���尡 �ԷµǾ������� Ȯ���ϴ� �Լ� �Է� ������ ������ Ȯ���Ͽ� Ű�� �Է��� �ִٸ� true
    if (_kbhit())
    {

        //�ϳ��� Ű�� �Է� ����
        key = _getch();

        if (key == 32)//jump
        {
            if (map[y - 1][x] != WALL) { //�÷��̾��� ��ĭ ���� ���� �ִ��� Ȯ��
                map[y][x] = 0;
                map[y - 1][x] = 2;
                y -= 1;
            }
            else {
                map[y][x] = 0;
                map[9][2] = PLAYER;
                return 2;
            }
            enterStatus = 1;
        }
        else {
            enterStatus = 0;
        }

        //esc
        if (key == 27) {
            for (int i = 0; i < MAPSIZEY; i++) {
                for (int j = 0; j < MAPSIZEX; j++) {
                    if (map[i][j] == PLAYER) {
                        //�÷��̾� ��ġ���� ���� 0(�����)���� �ʱ�ȭ
                        map[i][j] = 0;
                        break;
                    }
                }
            }
            //�÷��̾ 9,2�� �ʱ�ȭ
            map[9][2] = PLAYER;
            return 1;
        }
    }

    if (map[y][x + 1] != WALL)//������ move
    {
        map[y][x] = 0;
        if (map[y][x + 1] == END) //���(�¸�)������ �̵��� ��
        {
            //change
            playerscore = (30 * type) + playerscore; // 30 * type(����) ��ŭ�� �÷��̾� �����͸� ����
            map[9][2] = PLAYER; // 9,2�� �÷��̾� �ʱ�ȭ
            return 1;
        }

        map[y][x + 1] = 2; //�÷��̾ ������ ��ĭ �̵�
        x += 1; //�÷��̾� x�� 1����
    }
    else {
        map[y][x] = 0;
        map[9][2] = PLAYER;
        return 2;
    }

    if (map[y + 1][x] != WALL) //down
    {
        if (enterStatus == 0) { //���� Ű�� �Է� ���� �ʾ��� ��
            map[y][x] = 0;
            if (map[y + 1][x] == END) //���(�¸�)������ �̵��� ��
            {
                playerscore = (30 * type) + playerscore;
                map[9][2] = PLAYER;
                return 1;
            }
            map[y + 1][x] = 2;
            y += 1;
        }
    }
    else {
        map[y][x] = 0;
        map[9][2] = PLAYER;
        return 2;
    }
    return 0;
}