#define _CRT_SECURE_NO_WARNINGS
#include "game.h"
void Interface()
{
	printf("***********1.������Ϸ********\n");
	printf("***********2.˫����Ϸ********\n");
	printf("***********0.�˳���Ϸ********\n");
}
void game2()
{
	char q = 0;
	srand((unsigned)time(NULL));
	char arr[ROW][COL] = { 0 };
	Initialization_board(arr, ROW, COL);//��ʼ������
	Print_board(arr, ROW, COL);//��ӡ����
	while (1)
	{
		Game_player1(arr, ROW, COL);//���1����
		Print_board(arr, ROW, COL);//��ӡ����
		q = Win_or_lose(arr, ROW, COL);//�ж���Ӯ
		if (q != 'B')//��Ϸ����
		{
			break;
		}
		Game_player2(arr, ROW, COL);//���2����
		Print_board(arr, ROW, COL);//��ӡ����
		q = Win_or_lose(arr, ROW, COL);//�ж���Ӯ
		if (q != 'B')//��Ϸ����
		{
			break;
		}
	}
	if (q == '#')
	{
		printf("1PӮ\n");
	}
	else if (q == '*')
	{
		printf("2PӮ\n");
	}
	else if (q == 'C')
	{
		printf("ƽ��\n");
	}
}
void game()
{
	char q = 0;
	srand((unsigned)time(NULL));
	char arr[ROW][COL] = { 0 };
	Initialization_board(arr, ROW, COL);//��ʼ������
	Print_board(arr, ROW, COL);//��ӡ����
	while (1)
	{
		Game_player(arr, ROW, COL);//�������
		Print_board(arr, ROW, COL);//��ӡ����
		q = Win_or_lose(arr, ROW, COL);//�ж���Ӯ
		if (q != 'B')//��Ϸ����
		{
			break;
		}
		Computer(arr, ROW, COL);//��������
		Print_board(arr, ROW, COL);//��ӡ����
		q = Win_or_lose(arr, ROW, COL);//�ж���Ӯ
		if (q != 'B')//��Ϸ����
		{
			break;
		}
	}
	if (q == '#')
	{
		printf("���Ӯ\n");
	}
	else if (q == '*')
	{
		printf("����Ӯ\n");
	}
	else if(q=='C')
	{
		printf("ƽ��\n");
	}
}
void Gobang()
{
	int q = 1;
	while (q)
	{
		Interface();
		printf("��ѡ��:");
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
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("�����������������:");
			break;
		}
	}
}
int main()
{
	Gobang();
	return 0;
}