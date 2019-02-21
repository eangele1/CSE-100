#include <cstdlib>
#include <iostream>
using namespace std;

int Partition(int arr[], int p, int r){
	int x = arr[r];
	int i = (p - 1);

	for (int j = p; j <= r - 1; j++) {
		if(arr[j] <= x){
			i++;
			swap(arr[i], arr[j]);
		}
	}

	swap(arr[i + 1], arr[r]);

	return (i + 1);
}

int Random_Partition(int arr[], int p, int r){
	srand(time(NULL));
	int i = p + rand() % (r - p);

	swap(arr[i], arr[r]);

	return Partition(arr, p, r);
}

void Random_QuickSort(int arr[], int p, int r){
	if(p < r){
		int q = Random_Partition(arr, p, r);
		Random_QuickSort(arr, p, q - 1);
		Random_QuickSort(arr, q + 1, r);
	}
}

int main(){
	int arrSize = 0;

	cin >> arrSize;

	if(arrSize == 0){
		cout << ";";
		return 0;
	}

	int arr[arrSize];

	for (int i = 0; i < arrSize; i++) {
		cin >> arr[i];
	}

	Random_QuickSort(arr, 0, arrSize - 1);

	for (int i = 0; i < arrSize; i++)
		cout << arr[i] << ";";

	return 0;
}