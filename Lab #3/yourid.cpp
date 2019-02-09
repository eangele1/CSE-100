#include <iostream>
#include <cmath>

using namespace std;

int Find_Max_Crossing_Subarray(int arr[], int low, int mid, int high){
	
	int left_sum = 0, right_sum = 0;
	int sum = 0;
	
	for (int i = mid; i >= low; i--) {
		sum = sum + arr[i];
		
		if (sum > left_sum){
			left_sum = sum;
		}
	}
	
	sum = 0;
	
	for (int j = mid + 1; j <= high; j++) {
		sum = sum + arr[j];
		
		if(sum > right_sum){
			right_sum = sum;
		}
	}
	
	return (left_sum + right_sum);
	
}

int Find_Max_Subarray(int arr[], int low, int high){
	
	if(high == low){
		return arr[low];
	}
	else{
		int mid = floor((low + high)/2);
		
		int left_sum = Find_Max_Subarray(arr, low, mid);
		int right_sum = Find_Max_Subarray(arr, mid + 1, high);
		int cross_sum = Find_Max_Crossing_Subarray(arr, low, mid, high);
		
		if(left_sum >= right_sum && left_sum >= cross_sum){
			return left_sum;
		}
		else if(right_sum >= left_sum && right_sum >= cross_sum){
			return right_sum;
		}
		else{
			return cross_sum;
		}
		
	}
}

int main(){
	
	int arrSize = 0;
	
	cin >> arrSize;
	
	int arr[arrSize];
	
	for (int i = 0; i < arrSize; i++) {
		cin >> arr[i];
	}
	
	int result = Find_Max_Subarray(arr, 0, arrSize-1);
	
	cout << result;
	
	return 0;
}
