#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROW 18
#define COL 18
void Initialization_board1(char arr[ROW][COL], int row, int col);//初始化棋盘
void Print_board1(char arr[ROW][COL], int row, int col);//打印棋盘
void Game_player1(char arr[ROW][COL], int row, int col);//玩家1下棋
char Win_or_lose1(char[ROW][COL], int row, int col);
void Game_player2(char arr[ROW][COL], int row, int col);//玩家2下棋