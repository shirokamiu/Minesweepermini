#define _CRT_SECURE_NO_WARNINGS

#include"game.h"

void menu()
{
	printf("***************************\n");
	printf("*****  1. ゲーム開始  *****\n");
	printf("*****  0. ゲーム終了  *****\n");
	printf("***************************\n");
}



void game()
{
	char mine[ROWS][COLS] = {0};
	char show[ROWS][COLS] = {0};
	InitBoard(mine, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '*');

	
	DisplayBoard(show, ROW, COL);

	SetMine(mine, ROW, COL);
	/*DisplayBoard(mine, ROW, COL);*/

	FindMine(mine, show, ROW, COL);
}


int main()
{
	int input = 0;
	srand((unsigned)time(NULL));
	do {
		menu();
		printf("選んでください:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("ゲーム開始\n");
			game();
			break;
		case 0:
			printf("ゲーム終了\n");
			break;
		default:
			printf("エラー、もう一度入力してください\n");
			break;
		}
	} while (input);
	
	return 0;
}