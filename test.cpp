#define _CRT_SECURE_NO_WARNINGS

#include"game.h"

void menu()
{
	printf("***************************\n");
	printf("*****  1. �Q�[���J�n  *****\n");
	printf("*****  0. �Q�[���I��  *****\n");
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
		printf("�I��ł�������:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("�Q�[���J�n\n");
			game();
			break;
		case 0:
			printf("�Q�[���I��\n");
			break;
		default:
			printf("�G���[�A������x���͂��Ă�������\n");
			break;
		}
	} while (input);
	
	return 0;
}