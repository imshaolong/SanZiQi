#include "game.h"
void menu() 
{
	printf("***********************************\n");
	printf("*****         1. play         *****\n");
	printf("*****         0. exit         *****\n"); 
	printf("***********************************\n");

}
void game() {
	char board[ROW][COL];//��������
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
		printf("��ϲ��һ�ʤ��\n");
		break;
	case '#':
		system("cls");
		printf("���ź����Ի�ʤ��\n");
		break;
	case 'Q':
		system("cls");
		printf("������~�Դ�ϲ��ƽ�֣�~~\n");
		break;
	}
}


int main() 
{
	srand((unsigned)time(NULL));
	int input = 0;
	do{
	menu();
	printf("������ѡ��: >");
	scanf("%d",&input);
	switch (input)
	{
	case 1:
		game();
		break;
	case 0:
		printf("��Ϸ������~~~\n");
		break;
	default:
		printf("��������������ѡ��!~\n");
		break;
	}
	} while (input);
	return 0;
}