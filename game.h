#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROW 9
#define COL 9
//�Q�[���Ֆʂ̃T�C�Y

#define COUNT 10
//���e�̐�


#define ROWS ROW + 2
#define COLS COL + 2

void InitBoard(char board[ROWS][COLS], int rows, int cols, char set);
//�Ֆʂ�����������

void DisplayBoard(char board[ROWS][COLS], int row, int col);
//�Ֆʂ�\��

void SetMine(char mine[ROWS][COLS], int row, int col);
//���e��ݒu����

void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);
//���e��T��