#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#include "main.h"
#include "map.h" //맵 가져오기

int mainscreen(void) {
    FILE* fp;
    errno_t err;
    char k[1000]; //text
    User user[100] = { {0, NULL}, };

    err = fopen_s(&fp, "rank_result.txt", "r"); //rank_result.txt 읽기 타입으로 open
    char* str2 = NULL;
    char* str3 = NULL;
    int i = 0;

    if (err == 0) {
        fgets(k, sizeof(k), fp);
        char* temp = strtok_s(k, "-", &str2);
        while (temp != NULL) { //NULL이 아닐때까지 반복

            str3 = NULL;

            char* temp2 = strtok_s(temp, "+", &str3); //구분자 +를 기준으로 나누기

            strcpy_s(user[i].name, sizeof(user[i].name), temp2);
            user[i].point = atoi(str3); //str3(점수)를 char형에서 int형으로 변경

            temp = strtok_s(NULL, "-", &str2); //구분자 -를 기준으로 나누기

            i++;

        }
        fclose(fp);
    }

    //저장된 유저들을 점수를 기준으로 sort
    sort(&user, i);

    while (1) {
        mainUI(user, i); //메인 UI 호출
        if (mainController() == 1) { //메인컨트롤러 호출
            return 1;
        }

    }



}

int gamescreen(int rt) {
    while (1) {
        if (rt == 1) {
            gameUI(fan == 1 ? map : fan == 2 ? map2 : map3, fan); //매개변수로 map을 넣어준다.
            int k = GameController(fan == 1 ? map : fan == 2 ? map2 : map3, fan);
            if (k == 1)
            {
                return -1;
            }
            else if (k == 2) { //re 게임 여부를 물어본다.
                system("cls");
                printf("[게임종료]\n다시하기 : 숫자 1을 입력\n메뉴 : 2\n입력 : ");
                int in;
                fflush(stdin);
                scanf_s("%d", &in);

                if (in == 1) {
                    return 1;
                }
                else if (in == 2) {
                    system("cls");
                    return -1;
                }
            }
        }
    }
}