#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROW 18
#define COL 18
void Initialization_board1(char arr[ROW][COL], int row, int col);//��ʼ������
void Print_board1(char arr[ROW][COL], int row, int col);//��ӡ����
void Game_player1(char arr[ROW][COL], int row, int col);//���1����
char Win_or_lose1(char[ROW][COL], int row, int col);
void Game_player2(char arr[ROW][COL], int row, int col);//���2����