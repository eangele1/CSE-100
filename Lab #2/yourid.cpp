#include <iostream>

using namespace std;

void printArray(int arr[], int arrSize){

	if(arrSize == 0){
		cout << ";";
		return;
	}
	else{
		for (int i = 0; i < arrSize; i++){
			cout << arr[i] << ";";
		}
	}

}

void merge(int arr[], int p, int q, int r){
	int s1 = q - p + 1;
	int s2 = r - q;

	int L[s1], R[s2];

	for (int i = 0; i < s1; i++){
		L[i] = arr[p + i];
	}
	for (int i = 0; i < s2; i++){
		R[i] = arr[q + 1 + i];
	}

	int i = 0;
	int j = 0;
	int k = p;

	while(i < s1 && j < s2){
		if (L[i] <= R[j]){
			arr[k] = L[i];
			i++;
		}
		else{
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < s1){ 
		arr[k] = L[i]; 
		i++; 
		k++; 
	}

	while (j < s2){ 
		arr[k] = R[j]; 
		j++; 
		k++; 
	} 

}

void MergeSort(int arr[], int p, int r){

	int q;

	if (p < r){
		q = p+(r-p)/2;
		MergeSort(arr, p, q);
		MergeSort(arr, q + 1, r);
		merge(arr, p, q, r);
	}

}

int main(int argc, char const *argv[]){

	int arrSize;

	cin >> arrSize;

	int arr[arrSize];

	for (int i = 0; i < arrSize; i++){
		cin >> arr[i];
	}
	
	MergeSort(arr, 0, arrSize - 1);

	printArray(arr, arrSize);
	
	return 0;
}
