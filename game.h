#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROW 9
#define COL 9
//ƒQ[ƒ€”Õ–Ê‚ÌƒTƒCƒY

#define COUNT 10
//”š’e‚Ì”


#define ROWS ROW + 2
#define COLS COL + 2

void InitBoard(char board[ROWS][COLS], int rows, int cols, char set);
//”Õ–Ê‚ğ‰Šú‰»‚·‚é

void DisplayBoard(char board[ROWS][COLS], int row, int col);
//”Õ–Ê‚ğ•\‚·

void SetMine(char mine[ROWS][COLS], int row, int col);
//”š’e‚ğİ’u‚·‚é

void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);
//”š’e‚ğ’T‚·