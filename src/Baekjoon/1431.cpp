#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;

int getsum(string a) {
	int sum = 0;
	for (int i = 0; i < a.length(); i++) {
		if('0' <= a[i] && a[i] <= '9')
			sum += a[i] - '0';
		else
			sum += 0;
	}
	return sum;
}

bool compare(string a, string b) {
	int sum_a = 0, sum_b = 0;
	if (a.length() < b.length())
		return 1;
	else if (a.length() > b.length())
		return 0;
	else {
		for (int i = 0; i < a.length(); i++) {
			sum_a += getsum(a);
			sum_b += getsum(b);
		}
		
		if (sum_a < sum_b)
			return 1;
		else if (sum_a > sum_b)
			return 0;
		else
			return a < b;
	}
		
}

int main(void) {
	int N;
	string guitar[1000];
	
	cin >> N;
	
	for (int i = 0; i < N; i++) {
		cin >> guitar[i];
	}
	
	sort(guitar, guitar + N, compare);
	
	for (int i = 0; i < N; i++) {
		cout << guitar[i] << endl;
	}
	
}
