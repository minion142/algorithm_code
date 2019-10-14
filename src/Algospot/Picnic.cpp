#include <iostream>

using namespace std;

int n;
bool areFriend[10][10] = {false,};

int countPairings(bool taken[10])
{
	//남은 학생들 중 가장 번호가 빠른 학생을 찾는다.
	int firstFree = -1;
	for (int i = 0; i < n; i++)
		if (!taken[i]) {
			firstFree = i;
			break;
		}
	//base_case : 모든 학생이 짝을 찾았으면 한가지 방법을 찾았으니 종료한다.
	if (firstFree == -1)
		return 1;
	int ret = 0;
	//이 학생과 짝지을 학생을 결정한다.
	for (int pairWith = firstFree + 1; pairWith < n; pairWith++)
		if (!taken[pairWith] && areFriend[firstFree][pairWith]) {
			taken[firstFree] = taken[pairWith] = true;
			ret += countPairings(taken);
			taken[firstFree] = taken[pairWith] = false;
		}
	return ret;
}

int main()
{
	int C;
	int ret[50] = {0,};
	cin >> C;
	for (int c = 0; c < C; c++) {
		int M;
		int M1, M2;
		bool taken[10] = {false,};
		cin >> n >> M;
		for (int i = 0; i < M; i++) {
			cin >> M1 >> M2;
			areFriend[M1][M2] = true;
			//areFriend[M2][M1] = true;
		}
		ret[c] = countPairings(taken);
		for (int i = 0; i < 10; i++)
			for (int j = 0; j < 10; j++)
				areFriend[i][j] = false;
	}
	
	for (int c = 0; c < C; c++)
		cout << ret[c] << endl;
}