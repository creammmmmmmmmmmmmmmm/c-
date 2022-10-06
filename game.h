#pragma once
#define ROW 5
#define COL 5
extern void inItBoard(char board[ROW][COL], int row, int col);
extern void disPlayBoard(char board[ROW][COL], int row, int col);
extern void game();
extern char computerisWin(char board[ROW][COL]);
extern char playerisWin(char board[ROW][COL]);
