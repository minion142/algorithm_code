//포기;;;;
#include <iostream>
#include <algorithm>

using namespace std;

int sum[100], sqSum[100], input[100];
int C, N, S;
#define INF 1987654321;

void initialize() {
	sum[0] = input[0];
	sqSum[0] = input[0] * input[0];
	for (int i = 0; i < 100; i++) {
		sum[i] = sum[i-1] + input[i];
		sqSum[i] = sqSum[i-1] + input[i] * input[i];
	}
}

int minError(int a, int b) {
	int m;
	if (a != 0) {
		m = int(double(sum[b] - sum[a - 1]) / (b-a+1) + 0.5);
		return (b-a+1) * m * m - 2 * (sum[b] - sum[a - 1]) * m + (sqSum[b] - sqSum[a - 1]);
	}
	else {
		m = int(double(sum[b]) / (b-a+1) + 0.5);
		return (b-a+1) * m * m - 2 * (sum[b]) * m + (sqSum[b]);
	}
}

int quantize(int from, int parts) {
	int result;
	if (from == N - 1) return 0;
	if (parts < 1) return INF;
	result = INF;
	for (int size = 1; size < N-from; size++)
		result = min(minError(from, from+size-1) + quantize(from+size, parts-1), result);
	cout << result << endl;
	return result;
}  

int main() {
	int answer[100];
	cin >> C;
	for (int c = 0; c < C; c++) {
		cin >> N >> S;
		for (int n = 0; n < N; n++) {
			cin >> input[n];
		}
		sort(input, input + N);
		initialize();
		answer[c] = quantize(0,S);
	}
	for (int c = 0; c < C; c++) {
		cout << answer[c] << endl;
	}
}



