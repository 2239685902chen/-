#define _CRT_SECURE_NO_WARNINGS
#include "game.h"
void Interface()
{
	printf("***********1.单人游戏********\n");
	printf("***********2.双人游戏********\n");
	printf("***********0.退出游戏********\n");
}
void game2()
{
	char q = 0;
	srand((unsigned)time(NULL));
	char arr[ROW][COL] = { 0 };
	Initialization_board(arr, ROW, COL);//初始化棋盘
	Print_board(arr, ROW, COL);//打印棋盘
	while (1)
	{
		Game_player1(arr, ROW, COL);//玩家1下棋
		Print_board(arr, ROW, COL);//打印棋盘
		q = Win_or_lose(arr, ROW, COL);//判断输赢
		if (q != 'B')//游戏结束
		{
			break;
		}
		Game_player2(arr, ROW, COL);//玩家2下棋
		Print_board(arr, ROW, COL);//打印棋盘
		q = Win_or_lose(arr, ROW, COL);//判断输赢
		if (q != 'B')//游戏结束
		{
			break;
		}
	}
	if (q == '#')
	{
		printf("1P赢\n");
	}
	else if (q == '*')
	{
		printf("2P赢\n");
	}
	else if (q == 'C')
	{
		printf("平局\n");
	}
}
void game()
{
	char q = 0;
	srand((unsigned)time(NULL));
	char arr[ROW][COL] = { 0 };
	Initialization_board(arr, ROW, COL);//初始化棋盘
	Print_board(arr, ROW, COL);//打印棋盘
	while (1)
	{
		Game_player(arr, ROW, COL);//玩家下棋
		Print_board(arr, ROW, COL);//打印棋盘
		q = Win_or_lose(arr, ROW, COL);//判断输赢
		if (q != 'B')//游戏结束
		{
			break;
		}
		Computer(arr, ROW, COL);//电脑下棋
		Print_board(arr, ROW, COL);//打印棋盘
		q = Win_or_lose(arr, ROW, COL);//判断输赢
		if (q != 'B')//游戏结束
		{
			break;
		}
	}
	if (q == '#')
	{
		printf("玩家赢\n");
	}
	else if (q == '*')
	{
		printf("电脑赢\n");
	}
	else if(q=='C')
	{
		printf("平局\n");
	}
}
void Gobang()
{
	int q = 1;
	while (q)
	{
		Interface();
		printf("请选择:");
		scanf("%d", &q);
		switch (q)
		{
		case 1:
			game();
			break;
		case 2:
			game2();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("输入错误，请重新输入:");
			break;
		}
	}
}
int main()
{
	Gobang();
	return 0;
}