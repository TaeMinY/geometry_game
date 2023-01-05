#pragma once
#define MAPSIZEX 80
#define MAPSIZEY 20
#define WALL 1
#define PLAYER 2
#define END 4

// User ����ü ����
typedef struct _User {
	int point;
	char name[30];
} User;

// controller ����
int mainController();
int GameController(int map[MAPSIZEY][MAPSIZEX], int type);

// ui ����
void gameUI(int map[MAPSIZEY][MAPSIZEX], int type);
void mainUI(User user[], int userN);


// screen ����
int mainscreen(void);
int gamescreen(int rt);

// utils ����
void gotoxy(int x, int y);
void removecursor(void);
void sort(User a[], int num);
void swap(User* user1, User* user2);


extern int m; //q w e selector duqn
extern int playerscore ;
extern int fan ;
extern int x , y;//player pos