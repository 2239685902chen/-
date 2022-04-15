#include "game2.h"
void Initialization_board1(char arr[ROW][COL], int row, int col)//��ʼ������
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
void Print_board1(char arr[ROW][COL], int row, int col)//��ӡ����
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
void Game_player1(char arr[ROW][COL], int row, int col)//���1����
{
	int q = 0;
	int w = 0;
	int e = 0;
	while (1)
	{
		if (e == 0)
		{
			printf("1P��\n");
			printf("���������꣺");
		}
		else if (e > 0)
		{
			Print_board(arr, ROW, COL);
			printf("�������,�������������꣺");
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
void Game_player2(char arr[ROW][COL], int row, int col)//���2����
{
	int q = 0;
	int w = 0;
	int e = 0;
	while (1)
	{
		if (e == 0)
		{
			printf("2P��\n");
			printf("���������꣺");
		}
		else if (e > 0)
		{
			Print_board(arr, ROW, COL);
			printf("�������,�������������꣺");
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
char Right_to_left_lower1(char arr[ROW][COL], int row, int col, int q, int w)//��������б�������ͬ������
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
char Right_to_left_left1(char arr[ROW][COL], int row, int col, int w)//��������б�������ͬ������
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
char Left_to_right_lower1(char arr[ROW][COL], int row, int col, int q)//��������б�������ͬ������
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
char Left_to_right_right1(char arr[ROW][COL], int row, int col, int w)//��������б�����ͬ������
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
char Win_or_lose1(char arr[ROW][COL], int row, int col)//�ж���Ӯ
{
	int q = 0;
	int w = 0;
	char e = 0;
	for (q = 0; q < row; q++)//���������ͬ
	{
		for (w = 0; w < col; w++)
		{
			if (arr[q][w] == arr[q][w + 1] && arr[q][w + 1] == arr[q][w + 2] && arr[q][w + 2] == arr[q][w + 3] && arr[q][w + 3] == arr[q][w + 4] && arr[q][w] != ' ')
			{
				return arr[q][w];
			}

		}
	}
	for (w = 0; w < col; w++)//���������ͬ
	{
		for (q = 0; q < row; q++)
		{
			if (arr[q][w] == arr[q + 1][w] && arr[q + 1][w] == arr[q + 2][w] && arr[q + 2][w] == arr[q + 3][w] && arr[q + 3][w] == arr[q + 4][w] && arr[q][w] != ' ')
			{
				return arr[q + 1][w];
			}
		}
	}
	for (w = 0; w + 4 < col; w++)//��������б�������ͬ������
	{
		e = Left_to_right_right1(arr, row, col, w);//��������б�������ͬ������
		if (e != 'T')
		{
			return e;
		}
	}
	for (q = 0; q + 4 < row; q++)//��������б�������ͬ������
	{
		e = Left_to_right_lower1(arr, ROW, COL, q);
		if (e != 'T')
		{
			return e;
		}
	}
	for (w = col - 1; w - 4 > 0; w--)//��������б�������ͬ������
	{
		e = Right_to_left_left1(arr, ROW, COL, w);//��������б�������ͬ������
		if (e != 'T')
		{
			return e;
		}
	}
	for (q = 0; q + 4 < row; q++)//��������б�������ͬ������
	{
		e = Right_to_left_lower1(arr, ROW, COL, q, w);//��������б�������ͬ������
		if (e != 'T')
		{
			return e;
		}
	}
	for (q = 0; q < row; q++)//�ж���û�пո�
	{
		for (w = 0; w < col; w++)
		{
			if (arr[q][w] == ' ')
			{
				return 'B';//'B'�Ǽ���
			}
		}
	}
	return 'C';
}