// 해당 코드는 Visual Studio 2022 를 기준으로 개발하였습니다.

#include<stdio.h>
#include<windows.h>

#include "main.h"

//전역변수 초기화
int m = 0; //스테이지 선택 status
int playerscore = 0; //플레이어 점수 초기화
int fan = 1;
int x = 9, y = 2;//플레이어 위치

int main() {
    system("mode con cols=200 lines=50"); //콘솔 창 크기 고정
    removecursor(); //커서 지우기
    int rt, rt1;
reset:
    rt = mainscreen();  //return 값
gamereplay:
    rt1 = gamescreen(rt);
    if (rt1 == -1) {
        system("cls"); //화면 초기화
        goto reset;
    }
    else if (rt1 == 1) {
        system("cls"); //화면 초기화
        goto gamereplay;
    }
    return 0;
}
