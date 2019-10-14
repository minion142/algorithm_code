#include <iostream>
using namespace std;
int C, n, board[100][100], cache[100][100];

bool jump(int y, int x) {
	if (y >= n || x >= n)
		return 0;
	if (y == n-1 && x == n-1)
		return 1;
	if (cache[y][x] != 0)
		return cache[y][x];
	return cache[y][x] = (jump(y-board[y][x],x) || jump(y, x-board[y][x]));
}

int main()
{
	cin >> C >> n;
	for(int c = 0; c < C; c++) {
		for (int i = 0; i < 100; i++)
			for (int j = 0; j < 100; j++)
				cache[i][j] = -1;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				cin >> board[i][j];
		if(jump(0,0))
			cout << "YES";
		else
			cout << "NO";
	}
} // 개망힘