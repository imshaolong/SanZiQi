#pragma once
#define _CRT_SECURE_NO_WARNINGS
#define ROW 3
#define COL 3

#include<stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

void init_board(char board[ROW][COL],int row, int col);
void show_board(char board[ROW][COL], int row, int col);
void player_move(char board[ROW][COL],int row, int col);
void computer_move(char board[ROW][COL],int row, int col);
char is_win(char board[ROW][COL], int row, int col);
int is_full(char board[ROW][COL],int row, int col);
