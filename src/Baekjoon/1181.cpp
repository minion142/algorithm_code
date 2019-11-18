#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int N;
	string input;
	vector<pair<int,string> > arr;
	
	cin >> N;
	
	//단어 길이와 단어를 한 벡터에 저장
	for(int i = 0; i < N; i++) {
		cin >> input;
		arr.push_back(pair<int,string>(input.length(),input));
	}
	
	sort(arr.begin(), arr.end());
	
	for (int i = 0; i < arr.size(); i++) {
		if (i > 0 && arr[i].second == arr[i-1].second)
			continue;		
		cout <<  arr[i].second << endl;
	}
}