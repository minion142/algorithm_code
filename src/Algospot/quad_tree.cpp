//Minion142 - 19.01.08 - Quad_tree
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int cursor = 1;

string quad_tree(string picture)
{
	string str[4];
	for (int i = 0; i < 4; i++) {
		if (picture[cursor] == 'x') {
			cursor++;
			str[i] = 'x' + quad_tree(picture);
		}
		else {
			str[i] = picture[cursor];
			cursor++;
		}
	}
	return str[2] + str[3] + str[0] + str[1];
}

int main()
{
	int C;
	string picture[50];
	cin >> C;
	for (int c = 0; c < C; c++) {
		cin >> picture[c];
		if (picture[c][0] == 'x')
			picture[c] = 'x' + quad_tree(picture[c]);
		cursor = 1;
	}
	
	for (int c = 0; c < C; c++)
		cout << picture[c] << endl;
}