#include <iostream>

using namespace std;

int main(void) {
	int arr[20] = {1,2,4,3,4,5,1,2,4,3,5,1,2,4,5,3,2,4,2,3};
	int count[5] = {0,0,0,0,0};
	
	for(int i = 0; i < 20; i++) {
		count[arr[i] - 1]++;
	}
	
	for (int i = 0; i < 5; i++)
		if (count[i] != 0)
			for (int j = 0; j < count[i]; j++)
				cout << i+1 << " ";
	return 0;
}