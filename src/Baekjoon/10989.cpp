#include <iostream>

using namespace std;

int main(void) {
	//cin cout 빠르게 처리
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N;
	int input;
	int number[10001];
	
	cin >> N;
	
	for(int i = 0; i < 10001; i++) {
		number[i] = 0;
	}
	
	for(int i = 0; i < N; i++) {
		cin >> input;
		number[input]++;
	}
	
	for(int i = 1; i < 10001; i++) {
		if (number[i] != 0)
			for (int j = 0; j < number[i]; j++)
				cout << i << '\n';
	}
}