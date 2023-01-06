#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include <stdlib.h>
#include<string.h>

#include "main.h"

//mainController 함수 선언
int mainController() {

    if (_kbhit() != 0) { //키보드의 입력 상태 확인
        int key;
        key = _getch(); //입력된 키의 아스키코드 값
        if (key == 'q' || key == 'Q') {
            gotoxy(9, 11);
            printf("  ");
            gotoxy(9, 10);
            printf("  ");
            gotoxy(9, 9);
            printf("▶");
            //int key = 0;
            m = 1;
            fan = 1;
        }
        else if (key == 'w' || key == 'W') {
            gotoxy(9, 9);
            printf("  ");
            gotoxy(9, 10);
            printf("▶");
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
            printf("▶");
            //int key = 0;
            m = 1;
            fan = 3;
        }
        else if (key == 27) {
            system("cls");
            int c;
            gotoxy(0, 0);

            //점수 저장을 물어보는 곳
            printf("점수를 저장하시겠습니까? (yes : 1, no : 1을 제외한 숫자) : ");
            scanf_s("%d", &c);

            //유저 플레이어 정의
            User user = { playerscore , "" };
            if (c == 1) {

                //저장될 닉네임 입력
                printf("저장 될 닉네임을 입력해주세요(+와 -는 입력 금지입니다.) : ");
                scanf_s("%s", &user.name, 30);

                while (regexName(user.name)) {
                    printf("저장 될 닉네임을 다시 입력해주세요(+와 -는 입력 금지입니다.) : ");
                    scanf_s("%s", &user.name, 30);
                }

                //rank_result를 타입 a로 받아 가져오기, 만약 없다면 생성
                FILE* fp;
                errno_t err;

                err = fopen_s(&fp, "rank_result.txt", "a");
                if (err == 0)
                {
                    char text[100] = ""; //파일에 추가 할 텍스트
                    char pointt[10];

                    //user point를 pointt변수에 char형으로 변경하여 저장
                    _itoa_s(user.point, pointt, sizeof(pointt), 10);

                    //text에 user.name과 point 사이에 +를 넣어 구분을 해줄 수 있도록 하고 마지막에 -를 넣어 다른 유저와 구별할 수 있도록 한다.
                    strcat_s(text, sizeof(text), user.name);
                    strcat_s(text, sizeof(text), "+");
                    strcat_s(text, sizeof(text), pointt);
                    strcat_s(text, sizeof(text), "-");

                    //파일에 입력하는 로직
                    // fwrite(text, sizeof(char), strlen(text), fp);
                    fputs(text, fp);

                    //파일 닫기
                    fclose(fp);
                    printf("저장이 완료되었습니다. 게임을 종료합니다.");
                }
                else {
                    printf("저장하는 도중 오류가 발생하여 저장하지 못하였습니다.");
                }
                exit(1);
            }
            else {
                printf("게임을 종료하셨습니다.\n");
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


    //키보드가 입력되었는지를 확인하는 함수 입력 버퍼의 내용을 확인하여 키의 입력이 있다면 true
    if (_kbhit())
    {

        //하나의 키를 입력 받음
        key = _getch();

        if (key == 32)//jump
        {
            if (map[y - 1][x] != WALL) { //플레이어의 한칸 위에 벽이 있는지 확인
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
                        //플레이어 위치였던 곳에 0(빈공간)으로 초기화
                        map[i][j] = 0;
                        break;
                    }
                }
            }
            //플레이어를 9,2에 초기화
            map[9][2] = PLAYER;
            return 1;
        }
    }

    if (map[y][x + 1] != WALL)//오른쪽 move
    {
        map[y][x] = 0;
        if (map[y][x + 1] == END) //통과(승리)지점에 이동할 시
        {
            //change
            playerscore = (30 * type) + playerscore; // 30 * type(라운드) 만큼의 플레이어 포인터를 지급
            map[9][2] = PLAYER; // 9,2에 플레이어 초기화
            return 1;
        }

        map[y][x + 1] = 2; //플레이어를 오른쪽 한칸 이동
        x += 1; //플레이어 x값 1증가
    }
    else {
        map[y][x] = 0;
        map[9][2] = PLAYER;
        return 2;
    }

    if (map[y + 1][x] != WALL) //down
    {
        if (enterStatus == 0) { //엔터 키를 입력 받지 않았을 때
            map[y][x] = 0;
            if (map[y + 1][x] == END) //통과(승리)지점에 이동할 시
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