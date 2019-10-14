//Minion142 - 시계 맞추기 - 181010 (수학적 접근으로 0ms 도전 스위치-시계 -> 시계-스위치)
#include <iostream>
#include <algorithm>
#define MAX 1987654321

using namespace std;

void button_click(int (*button)[5], int* clock, int button_num, int press_times)
{
	for (int j = 0; j < press_times; j++)
		for (int i = 0; i < 5; i++)
			if (button[button_num][i] != -1)
				if (clock[button[button_num][i]] != 12)
					clock[button[button_num][i]] += 3;
				else
					clock[button[button_num][i]] = 3;
}

void clock_set(int (*button)[5], int* clock, int* clock_copy, int* times)
{
	times[0]++;
	copy(clock, clock+16, clock_copy);
	for (int i = 0; i < 10; i++) {
		if (times[i] == 4) {
			times[i] = 0;
			times[i+1]++;
		}
		button_click(button, clock_copy, i, times[i]);
	}
}

int check(int* clock, int answer, int* times) 
{
	int result = 0;
	int i;
	
	for (i = 0; i < 16; i++)
		if (clock[i] != 12)
			break;
	if (i == 16) {
		for (int j = 0; j < 10; j++)
			result += times[j];
		
		//cout << "times : ";
		//for (int j = 0; j < 10; j++)
		//	cout << times[j] << " ";
		
		return min(result,answer);
	}
	else
		return answer;
}
int main()
{
	int C, clock[16], answer = MAX, result[30];
	int clock_copy[16] = {0};
	int times[11] = {0}; //버튼 누른 횟수 저장용
	int button[10][5] {
		{0, 1, 2, -1 ,-1},
		{3, 7, 9, 11, -1},
		{4, 10, 14, 15, -1},
		{0, 4, 5, 6, 7},
		{6, 7, 8, 10, 12},
		{0, 2, 14, 15, -1},
		{3, 14, 15, -1, -1},
		{4, 5, 7, 14, 15},
		{1, 2, 3, 4, 5},
		{3, 4, 5, 9, 13}	
	};	
	
	cin >> C;
	
	for (int i = 0; i < C; i++)
		result[i] = MAX;
	for (int i = 0; i < C; i++) {
		for (int j = 0; j < 16; j++)
			cin >> clock[j];
		result[i] = min(result[i],check(clock, answer, times));
		while (times[10] == 0) {
			clock_set(button, clock, clock_copy, times);
			result[i] = min(result[i],check(clock_copy, answer, times));
		}
		fill_n(times, 11, 0);
		answer = MAX;
	}
	
	for (int i = 0; i < C; i++) {
		if (result[i] == MAX)
			cout << "-1" << endl;
		else
			cout << result[i] << endl;
	}
}