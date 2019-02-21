#include <iostream>
#include <cmath>

using namespace std;

void Max_Heapify(int arr[], int i, int arrSize){
	
	int l = 2*i + 1;
	int r = 2*i + 2;
	int largest = i;
	
	if(l < arrSize && arr[l] > arr[largest]){
		largest = l;
	}
	if(r < arrSize && arr[r] > arr[largest]){
		largest = r;
	}
	if(largest != i){
		swap(arr[i], arr[largest]);
		
		Max_Heapify(arr, largest, arrSize);
	}
	
}

void Build_Max_Heap(int arr[], int n){
	
	for (int i = floor(n/2) - 1; i >= 0; i--) {
		Max_Heapify(arr, i, n);
	}
	
}

void HeapSort(int arr[], int n){

	if(n == 0){
		cout << ";";
		return;
	}
	
	Build_Max_Heap(arr, n);
	
	for (int i = n - 1; i >= 0; i--) {
		swap(arr[0], arr[i]);
		
		Max_Heapify(arr, 0, i);
	}
	
}

int main(){
	
	int arrSize = 0;
	
	cin >> arrSize;
	
	int arr[arrSize];
	
	for (int i = 0; i < arrSize; i++) {
		cin >> arr[i];
	}
	
	HeapSort(arr, arrSize);
	
    //print sorted array
	for (int i = 0; i < arrSize; i++)
		cout << arr[i] << ";";
	
	return 0;
}
