#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROW 18
#define COL 18
void Initialization_board(char arr[ROW][COL], int row, int col);//��ʼ������
void Print_board(char arr[ROW][COL], int row, int col);//��ӡ����
void Game_player(char arr[ROW][COL], int row, int col);//��������˫�˶�ս�����1����
void Computer(char[ROW][COL], int row, int col);//��������
char Win_or_lose(char[ROW][COL], int row, int col);
void Game_player2(char arr[ROW][COL], int row, int col);//���2����