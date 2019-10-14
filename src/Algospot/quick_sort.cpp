//Minion142 - 19.01.08 - Quick_Sort
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> Quick_Sort(vector<int>& array)
{
	vector<int> child1;
	vector<int> child2;
	//base_case : 배열 길이가 1보다 작으면
	if (array.size() < 1)
		return array;
	
	//나누는 부분!
	int len  = array.size();
	for (int i = 1; i < len; i++)
		if (array[i] < array[0])
			child1.push_back(array[i]);
		else
			child2.push_back(array[i]);
	
	child1 = Quick_Sort(child1);
	child2 = Quick_Sort(child2);
	
	//합치는 부분!
	child1.push_back(array[0]);
	array = child1;
	array.insert(array.end(), child2.begin(), child2.end());
	//array = child1 + array[0] + child2 랑 같은거임
	
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
	
	array = Quick_Sort(array);
	
	for (int i = 0; i < array.size(); i++)
		cout << array[i] << " ";
	cout << endl;
}