#include "game2.h"
void Initialization_board1(char arr[ROW][COL], int row, int col)//初始化棋盘
{
	int q = 0;
	int w = 0;
	for (q = 0; q < row; q++)
	{
		for (w = 0; w < col; w++)
		{
			arr[q][w] = ' ';
		}
	}
}
void Print_board1(char arr[ROW][COL], int row, int col)//打印棋盘
{
	int q = 0;
	int w = 0;
	int e = 1;
	for (w = 0; w <= col; w++)
	{
		if (w == 0)
		{
			printf("%d ", w);
		}
		else if (w < 9 && w != 0)
		{
			printf("  %d ", w);
		}
		else
		{
			printf(" %d ", w);
		}
	}
	printf("\n");
	for (q = 0; q < row; q++)
	{
		if (e < 10)
		{
			printf("%d ", e);
		}
		else
		{
			printf("%d", e);
		}
		e++;
		for (w = 0; w < col; w++)
		{
			printf(" %c ", arr[q][w]);
			if (w < col - 1)
			{
				printf("|");
			}
		}
		printf("\n");
		printf("  ");
		for (w = 0; w < col; w++)
		{
			printf("---");
			if (w < col - 1)
			{
				printf("|");
			}
		}
		printf("\n");
	}
}
void Game_player1(char arr[ROW][COL], int row, int col)//玩家1下棋
{
	int q = 0;
	int w = 0;
	int e = 0;
	while (1)
	{
		if (e == 0)
		{
			printf("1P下\n");
			printf("请输入坐标：");
		}
		else if (e > 0)
		{
			Print_board(arr, ROW, COL);
			printf("输入错误,请重新输入坐标：");
		}
		scanf("%d%d", &q, &w);
		if (q <= row && w <= col)
		{
			if (arr[q - 1][w - 1] == ' ')
			{
				arr[q - 1][w - 1] = '#';
				break;
			}
		}
		e++;
	}
}
void Game_player2(char arr[ROW][COL], int row, int col)//玩家2下棋
{
	int q = 0;
	int w = 0;
	int e = 0;
	while (1)
	{
		if (e == 0)
		{
			printf("2P下\n");
			printf("请输入坐标：");
		}
		else if (e > 0)
		{
			Print_board(arr, ROW, COL);
			printf("输入错误,请重新输入坐标：");
		}
		scanf("%d%d", &q, &w);
		if (q <= row && w <= col)
		{
			if (arr[q - 1][w - 1] == ' ')
			{
				arr[q - 1][w - 1] = '*';
				break;
			}
		}
		e++;
	}
}
char Right_to_left_lower1(char arr[ROW][COL], int row, int col, int q, int w)//从右向左斜五个棋相同向下走
{
	for (w = col - 1; w - 4 >= 0; q++, w--)
	{
		if (arr[q][w] == arr[q + 1][w - 1] && arr[q + 1][w - 1] == arr[q + 2][w - 2] && arr[q + 2][w - 2] == arr[q + 3][w - 3] && arr[q + 3][w - 3] == arr[q + 4][w - 4] && arr[q][w] != ' ')
		{
			return arr[q + 2][w - 2];
		}
	}
	return 'T';
}
char Right_to_left_left1(char arr[ROW][COL], int row, int col, int w)//从右向左斜五个棋相同向左走
{
	int q = 0;
	for (q = 0; w - 4 >= 0; q++, w--)
	{
		if (arr[q][w] == arr[q + 1][w - 1] && arr[q + 1][w - 1] == arr[q + 2][w - 2] && arr[q + 2][w - 2] == arr[q + 3][w - 3] && arr[q + 3][w - 3] == arr[q + 4][w - 4] && arr[q][w] != ' ')
		{
			return arr[q + 1][w - 1];
		}
	}
	return 'T';
}
char Left_to_right_lower1(char arr[ROW][COL], int row, int col, int q)//从左向右斜五个棋相同向下走
{
	int w = 0;
	for (w = 0; q + 4 < row; w++, q++)
	{
		if (arr[q][w] == arr[q + 1][w + 1] && arr[q + 1][w + 1] == arr[q + 2][w + 2] && arr[q + 2][w + 2] == arr[q + 3][w + 3] && arr[q + 3][w + 3] == arr[q + 4][w + 4] && arr[q][w] != ' ')
		{
			return arr[q + 2][w + 2];
		}
	}
	return 'T';
}
char Left_to_right_right1(char arr[ROW][COL], int row, int col, int w)//从左向右斜五个相同向右走
{
	int q = 0;
	for (q = 0; w + 4 < col; q++, w++)
	{
		if (arr[q][w] == arr[q + 1][w + 1] && arr[q + 1][w + 1] == arr[q + 2][w + 2] && arr[q + 2][w + 2] == arr[q + 3][w + 3] && arr[q + 3][w + 3] == arr[q + 4][w + 4] && arr[q][w] != ' ')
		{
			return arr[q + 1][w + 1];
		}
	}
	return 'T';
}
char Win_or_lose1(char arr[ROW][COL], int row, int col)//判断输赢
{
	int q = 0;
	int w = 0;
	char e = 0;
	for (q = 0; q < row; q++)//横五个棋相同
	{
		for (w = 0; w < col; w++)
		{
			if (arr[q][w] == arr[q][w + 1] && arr[q][w + 1] == arr[q][w + 2] && arr[q][w + 2] == arr[q][w + 3] && arr[q][w + 3] == arr[q][w + 4] && arr[q][w] != ' ')
			{
				return arr[q][w];
			}

		}
	}
	for (w = 0; w < col; w++)//竖五个棋相同
	{
		for (q = 0; q < row; q++)
		{
			if (arr[q][w] == arr[q + 1][w] && arr[q + 1][w] == arr[q + 2][w] && arr[q + 2][w] == arr[q + 3][w] && arr[q + 3][w] == arr[q + 4][w] && arr[q][w] != ' ')
			{
				return arr[q + 1][w];
			}
		}
	}
	for (w = 0; w + 4 < col; w++)//从左向右斜五个棋相同向右走
	{
		e = Left_to_right_right1(arr, row, col, w);//从左向右斜五个棋相同向右走
		if (e != 'T')
		{
			return e;
		}
	}
	for (q = 0; q + 4 < row; q++)//从左向右斜五个棋相同向下走
	{
		e = Left_to_right_lower1(arr, ROW, COL, q);
		if (e != 'T')
		{
			return e;
		}
	}
	for (w = col - 1; w - 4 > 0; w--)//从右向左斜五个棋相同向左走
	{
		e = Right_to_left_left1(arr, ROW, COL, w);//从右向左斜五个棋相同向左走
		if (e != 'T')
		{
			return e;
		}
	}
	for (q = 0; q + 4 < row; q++)//从右向左斜五个棋相同向下走
	{
		e = Right_to_left_lower1(arr, ROW, COL, q, w);//从右向左斜五个棋相同向下走
		if (e != 'T')
		{
			return e;
		}
	}
	for (q = 0; q < row; q++)//判断有没有空格
	{
		for (w = 0; w < col; w++)
		{
			if (arr[q][w] == ' ')
			{
				return 'B';//'B'是继续
			}
		}
	}
	return 'C';
}