#define _CRT_SECURE_NO_WARNINGS
#include"game.h"
/*
* 
�}�C���X�C�[�p�[�~�j�Q�[���ł��B
9 * 9�@�T�C�Y�̔Ֆʂ� 10 ���e�������_���ɔz�u����Ă��܂��B
��������ɂ́A���e�����܂��Ă��Ȃ��S�Ă̍��W��I������K�v������܂��B
���e�����܂��Ă��Ȃ����W��I������ƁA���́@8�@���W�ɂ��锚�e�̐��������������\��܂��B

�w�b�_�[�t�@�C���ŔՖʂ̃T�C�Y�Ɣ��e�̐���ύX���邱�Ƃ��ł��܂��B
*/


void InitBoard(char board[ROWS][COLS], int rows, int cols, char set)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			board[i][j] = set;
		}
	}
}

void DisplayBoard(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	printf("----------minesweeper----------\n");
	for (i = 0; i <= col; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);
		for (j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
	printf("----------minesweeper----------\n");

}

void SetMine(char mine[ROWS][COLS], int row, int col)
{
	
	int count = COUNT;
	while (count)
	{
		int x = rand()%row + 1;
		int y = rand()%col + 1;
		if (mine[x][y] == '0')
		{
			mine[x][y] = '1';
			count--;
		}
	}
}

//���͂̔��e�̐���\��
static int get_mine_count(char mine[ROWS][COLS], int x, int y)
{
	return
		mine[x - 1][y] +
		mine[x - 1][y - 1] +
		mine[x][y - 1] +
		mine[x + 1][y - 1] +
		mine[x + 1][y] +
		mine[x + 1][y + 1] +
		mine[x][y + 1] +
		mine[x - 1][y + 1] - 8 * '0';
}

void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int win = 0;

	while (win < row * col - COUNT) {
		printf("���W����͂���:>");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (mine[x][y] == '1')
			{
				printf("���߂�Ȃ����B���e�ł�\n");
				DisplayBoard(mine, row, col);
				break;
			}
			else
			{
				int count = get_mine_count(mine, x, y); 
				show[x][y] = count + '0';
				DisplayBoard(show, row, col);
				win++;
			}
		}
		else
		{
			printf("�G���[�A������x���͂��Ă�������\n");
		}
	}
	if (win == row * col - COUNT)
	{
		printf("����!���߂łƂ��������܂�!\n");
		DisplayBoard(mine, row, col);
	}


}


