#include "game.h"
void menu() 
{
	printf("***********************************\n");
	printf("*****         1. play         *****\n");
	printf("*****         0. exit         *****\n"); 
	printf("***********************************\n");

}
void game() {
	char board[ROW][COL];//定义棋盘
	char result = ' ';
	init_board(board, ROW, COL);
	show_board(board, ROW, COL);
	while(1){

		player_move(board,ROW, COL);
		show_board(board, ROW, COL);
		if ('C' != (result = is_win(board, ROW, COL)))
			break;
		computer_move(board, ROW, COL);
		show_board(board, ROW, COL);
		if ('C' != (result = is_win(board, ROW, COL)))
			break;
	
	}
	switch (result) 
	{
	case '*':
		system("cls");
		printf("恭喜玩家获胜！\n");
		break;
	case '#':
		system("cls");
		printf("很遗憾电脑获胜！\n");
		break;
	case 'Q':
		system("cls");
		printf("哈哈！~皆大欢喜！平局！~~\n");
		break;
	}
}


int main() 
{
	srand((unsigned)time(NULL));
	int input = 0;
	do{
	menu();
	printf("请做出选择: >");
	scanf("%d",&input);
	switch (input)
	{
	case 1:
		game();
		break;
	case 0:
		printf("游戏结束！~~~\n");
		break;
	default:
		printf("输入有误，请重新选择!~\n");
		break;
	}
	} while (input);
	return 0;
}