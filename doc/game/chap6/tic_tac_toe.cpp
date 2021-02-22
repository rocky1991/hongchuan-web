// Create an empty tic-tac-toe board
// display the game instructions
// determine who goes first
// display the board
// while nobody's won and it's not a tie
// 	if it's the humans turn
// 		get the human's move
// 		update board with the human's move
// 	otherwise
// 		calculate the computer's move
// 		update the board with the human's move
// 	display the board
// 	switch turns
// congratulate the winder or declare a tie

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const char X = 'X';
const char O = 'O';
const char EMPTY = ' ';
const char TIE = 'T';
const char NO_ONE = 'N';

void instructions();
char ask_yes_no(string question);
int ask_number(string question, int high, int low = 0);
char human_piece();
char opponent(char piece);
void display_board(const vector <char>& board);
char winner(const vector <char>& board);
bool is_leagal(const vector <char>& board, int move);
int human_move(const vector <char>& board, char human);
int computer_move(vector <char>& board, char computer);
void announce_winner(char winner, char computer, char human);

int main() {
	int move;
	const int NUM_SQUARES = 9;
	vector <char> board(NUM_SQUARES, EMPTY);
	
	instructions();
	char human = human_piece();
	char computer = opponent(human);
	char turn = X;
	display_board(board);

	while (winner(board) == NO_ONE) {
		if (turn == human) {
			move = human_move(board, human);
			board[move] = human;
		} else {
			move = computer_move(board,computer);
			board[move] = computer;
		}
		display_board(board);
		turn = opponent(turn);
	}	
	announce_winner(winner(board), computer, human);
	return 0; 
}

void instructions() {
	cout << "Welcome to the ultimate man-machine showdown: Tic_Tac_toe.\n";
	cout << "-- where human brain is pit agains silicon processor\n\n";
	
	cout << "Make your move know by entering a number. 0-8. The number\n";
	cout << "corresponds to hte desired board position, as illustrated: \n\n";

	cout << "0 | 1 | 2\n";
	cout << "3 | 4 | 5\n";
	cout << "6 | 7 | 8\n\n";

	cout << "Prepare your self, human, The battle is about to begin. \n\n";
}
char ask_yes_no(string question) {
	char response;
	do {
		cout << question << "(y/n): ";
		cout >> response;
	} while (response != 'y' && response != 'n');
}
int ask_number(string question, int high, int low) {
	int number;
	do {
		cout << question << "(" << low << "-" << high << "): ";
	} while (number > high || number < low);
	return number
}
char human_piece() {
	char go_first = ask_yes_no("Do you require the first move?");
	if (go_first == 'y') {
		cout << "\n Then take the first move. You will need it. \n";
		return X;
	} else {
		cout << "\nYour bravery wil lbe your undoing... I will go first. \n";
		return O;
	}
}
char opponent(char piece) {
	if (piece == X) {
		return O;
	} else {
		return X;
	}
}
void display_board(const vector<char>& board) {
	cout << "\n\t << board[0] << "|" << board[1] << "|" << baord[2];
	cout << "\n\t << "------------";
	cout << "\n\t << board[3] << "|" << board[4] << "|" << baord[5];
        cout << "\n\t << "------------";
	cout << "\n\t << board[6] << "|" << board[7] << "|" << baord[8];
        cout << "\n\t << "------------";
	cout << "\n\n";

}

char winner(const vector<char>& board) {
	const int WINNING_ROWS[8][3] = { {0,1,2},
					 {3,4,5},
					 {6,7,8},
					 {0,3,6},
					 {2,5,8},
					 {1,4,7},
					 {0,4,8},
					 {2,4,6}};
	const int TOTAL_ROWS = 8;
	for (int row = 0; row < TOTAL_ROWS; row++) {
		if( (board[WINNING_ROWS[row][0]] != EMPTY) && (board[WINNING_ROWS[row][0]] == board[WINNING_ROWS[row][1]]) && (board[WINNING_ROWS[row][1]] == board[WINNING_ROWS[row][2]] )) {
			return board[WINNING_ROWS[row][0]];
		}	
	}
	if (count (board.begin(), board.end(), EMPTY) == 0) {
		return TIE;
	}

	return NO_ONE;
}

inline bool is_legal(int move, const vector <char>& board) {
	return (board[move] == EMPTY);
}

int human_move(const vector <char>& board, char human) {
	int move = ask_number("Where will you move?", (board.size() -1));
	while (!is_legal(move, board)) {
		cout << "\n That squre is already occupied, boolish human.\n";
		move = ask_number("Where will you move?", (board.size() -1));
	}
	cout << "Fine...\n";
	return move;
}

int computer_move(vector<char> board, char computer) {
	unsigned int move = O;
	bool found = false;

	while (!found && move < board.size() ){
		if (is_legal(move,board) ) {
			board[move] = computer;
			found = winner(board) == computer;
			board[move] = EMPTY;
		}

		if (!found) {
			move++;
		}
	}
}
