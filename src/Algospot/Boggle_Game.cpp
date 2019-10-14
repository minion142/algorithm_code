#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

char Boggle[7][7] = {0,}; //5x5 판, 테두리 널값 적용

bool FindString(string find_str, int depth, int x_pos, int y_pos)
{
	char tmp_str;
	bool answer = false;
	//base_case : find_str의 길이가 depth와 같아지면 탈출
	if(find_str.length() == depth)
		return true;
	
	int x[3] = {-1,1,0};
	int y[3] = {-1,1,0};
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++) {
			if (i == 3 && j == 3)
				break;
			if (Boggle[x_pos + x[i]][y_pos + y[j]] == find_str[depth])
				if (FindString(find_str, depth+1, x_pos + x[i], y_pos + y[j]))
					return true;
		}
	return false;
}

int main()
{
	int C; // Test Case
	int N; // Word Count
	string find_str[10]; //최대 개수 10
	bool is_str_exist[10] = {0,};
	int depth = 0;
	bool answer = false;
	char tmp_str;
	
	cin >> C;
	for(int i = 0; i < C; i++) {
		for (int y = 1; y < 6; y++)
			for (int x = 1; x < 6; x++)
				cin >> Boggle[y][x]; //보드판 만들기
		cin >> N;
		for (int j = 0; j < N; j++)
			cin >> find_str[j]; //찾을 단어 입력
		for (int j = 0; j < N; j++) {
			//검색 시작
			for (int x = 1; x < 6 && answer == false; x++)
				for (int y = 1; y < 6 && answer == false; y++)
					if (Boggle[x][y] == find_str[j][depth])
						answer = FindString(find_str[j], depth+1, x, y);
			is_str_exist[j] = answer;
			depth = 0;
			answer = false;
		}
		for (int j = 0; j < N; j++) {
			cout << find_str[j] << " ";
			if (is_str_exist[j] == true)
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
		}
	}
}