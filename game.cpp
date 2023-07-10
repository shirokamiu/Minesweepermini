#define _CRT_SECURE_NO_WARNINGS
#include"game.h"
/*
* 
マインスイーパーミニゲームです。
9 * 9　サイズの盤面に 10 個爆弾がランダムに配置されています。
勝利するには、爆弾が埋まっていない全ての座標を選択する必要があります。
爆弾が埋まっていない座標を選択すると、周囲　8　座標にある爆弾の数を示す数字が表れます。

ヘッダーファイルで盤面のサイズと爆弾の数を変更することができます。
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

//周囲の爆弾の数を表す
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
		printf("座標を入力せよ:>");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (mine[x][y] == '1')
			{
				printf("ごめんなさい。爆弾です\n");
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
			printf("エラー、もう一度入力してください\n");
		}
	}
	if (win == row * col - COUNT)
	{
		printf("勝利!おめでとうございます!\n");
		DisplayBoard(mine, row, col);
	}


}


