#include<iostream>
#include<cstdlib>
#include<vector>
using namespace std;

void CountSort(vector<int> A[], int arrSize, int k){
	
	vector<int>* B = new vector<int>[arrSize];
	
	int i, C[10];

	for(i = 0; i < 10; i++){
		C[i] = 0;
	}
	
	for (i = 0; i < arrSize; i++){
		C[A[i][k]]++;
	}
	
	for (i = 1; i < 10; i++){
		C[i] += C[i - 1];
	}
	
	for (i = arrSize-1; i >= 0; i--){
		B[C[A[i][k]] - 1] = A[i];
		C[A[i][k]]--;
	}
	
	for (i = 0; i < arrSize; i++){
		A[i] = B[i];
	}
}

void RadixSort(vector<int> arr[], int arrSize){
	for (int k = 9; k >= 0; k--){
		CountSort(arr, arrSize, k);
	}
}

int main(){
	int arrSize = 0;
	cin >> arrSize;
	
	if(arrSize == 0){
		cout << ";";
		return 0;
	}
	
	vector<int>* arr = new vector<int>[arrSize];
	
	int n;
	
	for(int i =0; i < arrSize; i++){
		for(int j = 0; j < 10; j++){
			cin >> n;
			arr[i].push_back(n);
		}
	}
	
	RadixSort(arr, arrSize);
	
	for (int i = 0; i < arrSize; i++){
		for(vector<int>::iterator j = arr[i].begin(); j != arr[i].end(); j++){
			cout << *j << ";";
		}
		cout << endl;
	}
	
	return 0;
}
