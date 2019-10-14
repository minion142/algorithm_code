//Minion142 - 19.01.08 - gameboard(x_pos,y_pos 사용)
#include <iostream>
#include <algorithm>
using namespace std;

int answer;
int H,W;
bool board[22][22];

void set_gameboard()
{
	for (int i = 0; i < H + 2; i++)
		for (int j = 0; j < W + 2; j++)
			board[i][j] = 0;
	
	char color;
	for (int i = 1; i < H + 1; i++)
		for (int j = 1; j < W + 1; j++) {
			cin >> color;
			if (color == '#')
				board[i][j] = 0;
			else
				board[i][j] = 1;
		}
}

bool cover_gameboard()
{
	const int x_pos[8] = {1,0,1,1,0,1,-1,0};
	const int y_pos[8] = {0,1,0,1,1,1, 1,1};
	for (int i = 1; i < H + 1; i++)
		for (int j = 1; j < W + 1; j++) {
			if (board[i][j] == 1) {
				for (int k = 0; k < 8; k += 2) {
					if (board[i + y_pos[k]][j + x_pos[k]] == 1 && board[i + y_pos[k+1]][j + x_pos[k+1]] == 1) {
						board[i][j] = 0;
						board[i + y_pos[k]][j + x_pos[k]] = 0;
						board[i + y_pos[k+1]][j + x_pos[k+1]] = 0;
						cover_gameboard();
						board[i][j] = 1;
						board[i + y_pos[k]][j + x_pos[k]] = 1;
						board[i + y_pos[k+1]][j + x_pos[k+1]] = 1;
						
					}
				}
				return 0;
			}
		}
	answer++;
	return 0;
}

int main()
{
	int C;
	int result[30];
	cin >> C;
	for (int c = 0; c < C; c++) {
		cin >> H >> W;
		answer = 0;
		set_gameboard();
		cover_gameboard();
		result[c] = answer;
	}
	for (int c = 0; c < C; c++)
		cout << result[c] << endl;
}