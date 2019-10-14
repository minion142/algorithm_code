//Minion142 - 19.01.08 - MergeSort
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> merge_Sort(vector<int>& array)
{
	//base_case : 배열 길이가 1이라면
	if (array.size() == 1)
		return array;
	
	//나누는 부분!
	int half = array.size()/2;
	vector<int> child1(&array[0],&array[half]);
	child1 = merge_Sort(child1);
	vector<int> child2(&array[half],&array[array.size()]);
	child2 = merge_Sort(child2);
	
	array.clear();
	//합치는 부분!
	while (child1.size() != 0 && child2.size() != 0) {
		//첫번째 원소가 젤 작음!
		if (child1[0] < child2[0]) {
			array.push_back(child1[0]);
			child1.erase(child1.begin()); //첫번째 원소 ㅃㅃ
		}
		else {
			array.push_back(child2[0]);
			child2.erase(child2.begin()); //첫번째 원소 ㅃㅃ
		}
	}
	
	if (child1.size() == 0) {
		while (child2.size() != 0) {
			array.push_back(child2[0]);
			child2.erase(child2.begin()); //첫번째 원소 ㅃㅃ
		}
	}
	else {
		while (child1.size() != 0) {
			array.push_back(child1[0]);
			child1.erase(child1.begin()); //첫번째 원소 ㅃㅃ
		}
	}
	return array;
}

int main()
{
	int N; // 입력할 숫자 개수
	vector<int> array; //숫자를 넣을 배열
	int tmp;
	
	cin >> N;
	for (int i = 0; i < N; i++) {
		//입력받아서 array에 push
		cin >> tmp;
		array.push_back(tmp);
	}
	
	array = merge_Sort(array);
	
	for (int i = 0; i < array.size(); i++)
		cout << array[i] << " ";
	cout << endl;
}