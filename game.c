#include "game.h"
void init_board(char board[ROW][COL], int row, int col)
{
	int i = 0, j = 0;
	for (i = 0; i < row; i++)
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}

}
void show_board(char board[ROW][COL], int row, int col) 
{
	int i = 0, j = 0;
	for (i = 0; i < row; i++) 
	{
		for (j = 0; j < col-1; j++) {
			printf(" %c |",board[i][j]);
		}
		printf(" %c \n",board[i][j]);
		for (j = 0; j < col - 1; j++) {
			printf("___|");
		}
		printf("___\n");

		//printf("___|___|___|\n");

	}

}

void player_move(char board[ROW][COL], int row, int col)
{
	int x = 0, y = 0;
	while(1){
	printf("玩家:>");
	scanf("%d %d",&x, &y);
	if (x < 0 || y < 0 || x >ROW || y > ROW) {
		printf("对不起你的输入有误请重新输入\n");
		continue;
	}
	if (board[x-1][y-1] != ' '){
		printf("您下的位置已被占用，请重新选择位置\n");
		continue;
	}
	board[x-1][y-1] = '*';
	break;
	}
}

void computer_move(char board[ROW][COL], int row, int col)
{
	int x = 0, y = 0;
	printf("本回合轮到电脑下：\n");
	while (1)
	{
		x = rand() % row;
		y = rand() % col;
		if (board[x][y] != ' ')
			continue;
		break;
	}
	board[x][y] = '#';
}


char is_win(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][2] != ' ')
			return board[i][2];
	}
	for (i = 0; i < col; i++)
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[2][i] != ' ')
			return board[2][i];
	}
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[2][2] != ' ')
		return board[2][2];
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[2][0] != ' ')
		return board[2][0];
	if (is_full(board, ROW, COL))
		return 'Q';
	return 'C';

}

int is_full(char board[ROW][COL], int row, int col)
{
	int i = 0, j = 0;
	for (i = 0; i < row; i ++) 
		for (j = 0; j < col; j++) 
		{
			if (board[i][j] == ' ')
				return 0;
		}
	return 1;
}
