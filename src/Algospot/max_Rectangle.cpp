//Minion142 - 19.01.09 - max_Rectangle
#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 1987654321
using namespace std;

int max_area = 0;
vector<pair<int,int>> height_sort;
int min_hight = 0;

// 3 1 5 9 6 7 7
// 3   5 9 6 7 7
//     5 9 6 7

vector<int> max_Rectangle(vector<int>& height)
{
	int width = height.size();
	max_area = max_area > height_sort[min_hight].first * width ? max_area : height_sort[min_hight].first;
	vector<int> child1(&height[0], &height[height_sort[min_hight].second]);
	vector<int> child2(&height[height_sort[min_hight].second] + 1, &height[height.size()]);
	for (int i = 0; i < width; i++)
		cout << height[i] << " ";
	cout << endl;
	while(child1.size() != 0 || child2.size() != 0)
		if (height_sort[min_hight].second > height_sort[min_hight + 1].second) {
			min_hight++;
			child1 = max_Rectangle(child1);
		}
		else {
			child2 = max_Rectangle(child2);
			min_hight++;
		}
	return child1;
}

int main()
{
	int C;
	int N;
	int result[50];
	int tmp;
	vector<int> height;
	cin >> C;
	
	
	for (int c = 0; c < C; c++) {
		cin >> N;
		for (int i = 0; i < N; i++) {
		cin >> tmp;
		height.push_back(tmp);
		height_sort.push_back(pair<int,int>(tmp,i));
		}
		height_sort.push_back(pair<int,int>(MAX,0));
		sort(height_sort.begin(), height_sort.end());
		max_Rectangle(height);
		
		result[c] = max_area;
		max_area = 0;
		height.clear();
		height_sort.clear();
	}
	
	for (int c = 0; c < C; c++)
		cout << result[c] << endl;
}