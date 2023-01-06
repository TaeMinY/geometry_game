#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#include "main.h"
#include "map.h" //�� ��������

int mainscreen(void) {
    FILE* fp;
    errno_t err;
    char k[1000]; //text
    User user[100] = { {0, NULL}, };

    err = fopen_s(&fp, "rank_result.txt", "r"); //rank_result.txt �б� Ÿ������ open
    char* str2 = NULL;
    char* str3 = NULL;
    int i = 0;

    if (err == 0) {
        fgets(k, sizeof(k), fp);
        char* temp = strtok_s(k, "-", &str2);
        while (temp != NULL) { //NULL�� �ƴҶ����� �ݺ�

            str3 = NULL;

            char* temp2 = strtok_s(temp, "+", &str3); //������ +�� �������� ������

            strcpy_s(user[i].name, sizeof(user[i].name), temp2);
            user[i].point = atoi(str3); //str3(����)�� char������ int������ ����

            temp = strtok_s(NULL, "-", &str2); //������ -�� �������� ������

            i++;

        }
        fclose(fp);
    }

    //����� �������� ������ �������� sort
    sort(&user, i);

    while (1) {
        mainUI(user, i); //���� UI ȣ��
        if (mainController() == 1) { //������Ʈ�ѷ� ȣ��
            return 1;
        }

    }



}

int gamescreen(int rt) {
    while (1) {
        if (rt == 1) {
            gameUI(fan == 1 ? map : fan == 2 ? map2 : map3, fan); //�Ű������� map�� �־��ش�.
            int k = GameController(fan == 1 ? map : fan == 2 ? map2 : map3, fan);
            if (k == 1)
            {
                return -1;
            }
            else if (k == 2) { //re ���� ���θ� �����.
                system("cls");
                printf("[��������]\n�ٽ��ϱ� : ���� 1�� �Է�\n�޴� : 2\n�Է� : ");
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