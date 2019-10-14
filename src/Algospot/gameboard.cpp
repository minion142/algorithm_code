//Minion142 - 게임판 덮기 - 181007
#include <iostream>
#include <algorithm>
using namespace std;

int answer;

void set_gameboard(bool (*board)[22], int H, int W)
{
	// 테두리를 0으로 초기화 하기 위해 전체 0으로 초기화
	for (int i = 0; i < H + 2; i++)
		for (int j = 0; j < W + 2; j++) {
			board[i][j] = 0;
		}
	
	char color;
    for (int i = 1; i < H + 1; i++) // 입력에 맞게 게임판 초기화
		for (int j = 1; j < W + 1; j++) {
			cin >> color;
			if (color == '#')
				board[i][j] = 0;
			else if (color == '.')
				board[i][j] = 1;
		}
}

bool cover_gameboard(bool (*board)[22], int H, int W)
{
	bool copy_board[22][22]; // 원래 board에 영향을 미치지 않기위해 copy선언
	
	
	//copy...
	for (int i = 0; i < H + 2; i++) {
		for (int j = 0; j < W + 2; j++) {
			copy_board[i][j] = board[i][j];
		}
	}
	for (int i = 1; i < H + 1; i++) {
		for (int j = 1; j < W + 1; j++) {
			if (copy_board[i][j] == 1) {
				if (copy_board[i][j+1] == 1 && copy_board[i+1][j] == 1) {
					copy_board[i][j] = 0;
					copy_board[i][j+1] = 0;
					copy_board[i+1][j] = 0;
					cover_gameboard(copy_board, H, W);
					copy_board[i][j] = 1;
					copy_board[i][j+1] = 1;
					copy_board[i+1][j] = 1;
				}
					
				if (copy_board[i+1][j] == 1 && copy_board[i+1][j+1] == 1) {
					copy_board[i][j] = 0;
					copy_board[i+1][j] = 0;
					copy_board[i+1][j+1] = 0;
					cover_gameboard(copy_board, H, W);
					copy_board[i][j] = 1;
					copy_board[i+1][j] = 1;
					copy_board[i+1][j+1] = 1;
				}
					
				if (copy_board[i][j+1] == 1 && copy_board[i+1][j+1] == 1) {
					copy_board[i][j] = 0;
					copy_board[i][j+1] = 0;
					copy_board[i+1][j+1] = 0;
					cover_gameboard(copy_board, H, W);
					copy_board[i][j] = 1;
					copy_board[i][j+1] = 1;
					copy_board[i+1][j+1] = 1;
				}
					
				if (copy_board[i+1][j-1] == 1 && copy_board[i+1][j] == 1) {
					copy_board[i][j] = 0;
					copy_board[i+1][j-1] = 0;
					copy_board[i+1][j] = 0;
					cover_gameboard(copy_board, H, W);
				}
				return 0;
			}
		}
	}
	answer++;
	return 0;
}

int main_gameboard()
{
    bool board[22][22];
    int C, H, W;
	
	cin >> C;
	for (int i = 0; i < C; i++) {
		cin >> H >> W;
		answer = 0;
		set_gameboard(board, H, W);
		cover_gameboard(board, H, W);
		cout << answer << endl;
	}
}