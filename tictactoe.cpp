//https://inventwithpython.com/invent4thed/chapter10.html
//https://www.geeksforgeeks.org/implementation-of-tic-tac-toe-game/
//http://www.angelfire.com/ny5/consigliere/tictactoe.html

#include <bits/stdc++.h>
using namespace std;
#define PLAYER 1
#define COMPUTER 2


char matrix[4][4];
char done;
int win;

void init_matrix();
void display_matrix();
void get_player_move();
void get_computer_move();
char check(char now);

int main()
{
	done = ' ';
	int playermove = 0, computermove = 0;
	printf("This is the game of Tic Tac Toe.\n");
	//printf("You will be playing against the computer.\n");
	init_matrix();
	
	srand(time(NULL));
	int randNum = rand()%2;
	printf("RandNum %d\n",randNum);
	
	if (randNum == 0){
		printf("Player go first!\n");
		while(done == ' '){
			get_player_move();
			display_matrix();
			done = check('X');
			if (done == 'X') {
				printf("Player won!");
				break;
			}
			playermove++;
			if(playermove == 5 && computermove == 4) {printf("It's a tie!'"); break;}
			get_computer_move();
			display_matrix();
			done = check('O');
			//done = get_computer_move();
			if (done == 'O') {
				printf("Computer won!");
				break;
			}
			computermove++;
			if(playermove == 5 && computermove == 4) {printf("It's a tie!'"); break;}
		}
	}
	else {
		printf("Computer go first\n");
		while(done == ' '){
			get_computer_move();
			display_matrix();
			done = check('O');
			//done = get_computer_move();
			if (done == 'O') {
				printf("Computer won!");
				break;
			}
			computermove++;
			if(playermove == 4 && computermove == 5) {printf("It's a tie!'"); break;}
			get_player_move();
			display_matrix();
			done = check('X');
			if (done == 'X') {
				printf("Player won!");
				break;
			}
			playermove++;
			if(playermove == 4 && computermove == 5) {printf("It's a tie!'"); break;}
		}
	}
	return 0;
}

void init_matrix(){
	for (int i=1;i<=3;i++){
		for (int j=1;j<=3;j++){
			matrix[i][j] = ' ';	
		}
	}
}

void display_matrix(){
	for (int i=1;i<=3;i++){
		for (int j=1;j<=3;j++){
			printf("| %c |",matrix[i][j]);
		}
		printf("\n");
	}
}

void get_player_move(){
	printf("Turn: Player\n");
	int x, y;
	printf("Enter X,Y coordinates for your move: ");
	scanf("%d%*c%d", &x, &y); //skip string ','
	if(matrix[x][y]!= ' ') {
	printf("Invalid move, try again.\n");
	get_player_move();
	}
	else {
		matrix[x][y] = 'X';
	}
}

void get_computer_move(){
	//First, check if computer can win in the next move
	printf("Turn: Computer\n");
	char comwin;
	for (int i=1;i<=3;i++){
		for (int j=1;j<=3;j++){
			if (matrix[i][j] == ' '){
				matrix[i][j] == 'O';
				comwin = check('O');
				if (comwin == 'O') {
					matrix[i][j] = 'O';
					return;
				}
				matrix[i][j] = ' ';
			}
		}
	}
	//Second, check if player can win so computer can block
	for (int i=1;i<=3;i++){
		for (int j=1;j<=3;j++){
			if (matrix[i][j] == ' '){
				matrix[i][j] = 'X';
				comwin = check('X');
				if (comwin == 'X'){
					matrix[i][j] = 'O';
					return;
				}
				matrix[i][j] = ' ';
			}
		}
	}
	
	//check if corner free
	if (matrix[1][1] == ' ') {matrix[1][1] = 'O'; return;}
	if (matrix[1][3] == ' ') {matrix[1][3] = 'O'; return;}
	if (matrix[3][1] == ' ') {matrix[3][1] = 'O'; return;}
	if (matrix[3][3] == ' ') {matrix[3][3] = 'O'; return;}
	
	//check if center is free
	if (matrix[2][2] == ' ') {matrix[2][2] = 'O'; return;}
	
	//Finally check sides
	if (matrix[1][2] == ' ') {matrix[1][2] = 'O'; return;}
	if (matrix[2][1] == ' ') {matrix[2][1] = 'O'; return;}
	if (matrix[2][3] == ' ') {matrix[2][3] = 'O'; return;}
	if (matrix[3][2] == ' ') {matrix[3][2] = 'O'; return;}
}

char check(char now){
	//check rows
	for (int i=1;i<=3;i++){
		if (matrix[i][1] == now && matrix[i][2] == now && matrix[i][3] == now) return now;
	}
	//check column
	for (int i=1;i<=3;i++){
		if (matrix[1][i] == now && matrix[2][i] == now && matrix[3][i] == now) return now;
	}
	//check diagonal
	if (matrix[1][1] == now && matrix[2][2] == now && matrix[3][3] == now) return now;
	if (matrix[1][3] == now && matrix[2][2] == now && matrix[3][1] == now) return now;
	
	return ' ';
}
