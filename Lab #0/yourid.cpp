#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc,char **argv) {

	vector<int> arr;
	int arrsize = 0;
	int currNum = 0;

	cin >> arrsize;

	for (int i = 0; i < arrsize; i++){

		cin >> currNum;

		arr.push_back(currNum);
	}

	sort(arr.begin(), arr.end());

	cout << arr.back() << ";" << arr.front();

}
