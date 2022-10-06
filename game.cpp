#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include "game.h"
void inItBoard(char board[ROW][COL], int row, int col)//初始化
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}

void disPlayBoard(char board[ROW][COL],int row,int col)
{
	for (int e = 0; e < col; e++)
	{
		printf("----");
		if (e == col - 1)
			printf("\n");
	}
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			printf("| %c ", board[i][j]);
		}
		printf("|\n");
		for (int m = 0; m < col; m++)
		{
			printf("----");
			if (m == col - 1)
				printf("\n");
		}
	}
}
void playerMove(char board[ROW][COL])
{
	int r, c;
	printf("该你了。第一个数字代表行，第二个代表列\n");
	scanf("%d %d", & r, &c);
	if (r <= ROW && c <= COL && r > 0 && c > 0)
	{
		if (board[r - 1][c - 1] == ' ')
		{
			board[r - 1][c - 1] = '*';
		}
		else
		{
			printf("这个格子已经下过子了！");
			playerMove(board);
		}
		system("cls");
		disPlayBoard(board, ROW, COL);
	}
}
void computerMove(char board[ROW][COL])
{
	int r, c;
	r = rand() % 3;
	c = rand() % 3;
	if (board[r - 1][c - 1] == ' ')
	{
		board[r - 1][c - 1] = '#';
	}
	else
	{
		computerMove(board);
	}
	system("cls");
	disPlayBoard(board, ROW, COL);
}
char playerisWin(char board[ROW][COL])
{	
	int f=0;
	for (int i = 0; i < ROW; i++)
	{
		int j;
		for (j = 0; j <COL-1; j++)
		{
			if (board[i][j] == board[i][j + 1] && board[i][j] == '*')
				f+=1;
		}
		if (j == COL-1&&f>=2)
		{
				return 'p';
		}
	}
	int e = 0;
	for (int j = 0; j < COL; j++)
	{
		int i;
		for (i = 0; i <COL-1; i++)
		{
			if (board[i][j] == board[i+1][j] && board[i][j] == '*')
				e+=1;
		}
		if (i == COL-1&&e>=2)
		{
			return 'p';
		}
	}
	int m = 0;
	for (int j = 0; j <COL-1; j++)
	{
		if (board[j][j] == board[j + 1][j + 1] && board[j][j] == '*')
			m+=1;
		if (j == COL-2&&m>=2)
		{
				return 'p';
		}
	}
	int n = 0;
	for (int j = 0; j <COL-1; j++)
	{
		if (board[j][COL - j - 1] == board[j + 1][COL - j - 2] && board[j][COL - j - 1] == '*')
			m+=1;
		if (j == COL-2&&m>=2)
		{
			return 'p';
		}
	}
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < ROW; j++)
		{
			if (board[i][j] == ' ')
				return 'c';
			if (i == ROW - 1 && j == ROW - 1)
				return 'n';
		}
	}
	return 'c';
}
char computerisWin(char board[ROW][COL])
{
	int u = 0;
	for (int i = 0; i < ROW; i++)
	{
		int j;
		for (j = 0; j < COL - 1; j++)
		{
			if (board[i][j] == board[i][j + 1] && board[i][j] == '#')
				u+=1;
		}
		if (j == COL - 1&&u>=2)
		{
			return 'a';
		}
	}
	int o = 0;
	for (int j = 0; j < COL; j++)
	{
		int i;
		for (i = 0; i < COL - 1; i++)
		{
			if (board[i][j] == board[i][j + 1] && board[i][j] == '#')
				o += 1;;
			if (i == COL - 1 && o >= 2)
			{
				return 'a';
			}
		}
	}
	int k = 0;
	for (int j = 0; j < COL - 1; j++)
	{
		if (board[j][j] == board[j + 1][j + 1] && board[j][j] == '#')
			k+=1;
		if (j == COL - 2&&k>=2)
		{
			return 'a';
		}
	}
	int h = 0;
	for (int j = 0; j < COL - 1; j++)
	{
		if (board[j][COL - j - 1] == board[j + 1][COL - j - 2] && board[j][COL - j - 1] == '#')
			h+=1;
		if (j == COL - 2&&h>=2)
		{
			return 'a';
		}
	}
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < ROW; j++)
		{
			if (board[i][j] == ' ')
				return 'c';
			if (i == ROW - 1 && j == ROW - 1)
				return 'n';
		}
	}
	return 'c';
}

void game()
{
	char board[ROW][COL] = { 0 };
	inItBoard(board, ROW, COL);
	disPlayBoard(board,ROW,COL);
	while (1)
	{
		playerMove(board);
		Sleep(500);
		if (playerisWin(board) != 'c')
			break;
		computerMove(board);
		if (computerisWin(board) != 'c')
			break;
	}
	if (playerisWin(board) == 'p')
		printf("你胜利了\n");
	else if(playerisWin(board) == 'n')
		printf("平局了\n");
	else if (computerisWin(board) == 'a')
		printf("你输了\n");
	else if (computerisWin(board) == 'n')
		printf("平局了\n");
}