#include <iostream>

using namespace std;

//funciton to executre insertion sort algorithm. Takes in array and array size as parameters.
void InsertionSort(int arr[], int arrSize){

	if (arrSize < 1){
		cout << ";";
		return;
	}

	if (arrSize == 1){
		cout << arr[0] << ";";
	}

	//initialize an int variable to store current key to compare with array elements
	int key;

	//initialize an int variable to keep track of how many elements to output at once to console
	int counter = 1;

	//iterates through array and sorts elements; two at a time.
	for (int i = 1; i < arrSize; i++){

		//key is equal to element at ith position in array
		key = arr[i];

		//initialize an int variable to store ith position minus one
		int j = i - 1;

		//while jth position is greater than or equal to zero, and element at j is greater than the key,
		//element at j plus one is now element at j. J is one position less.
		while(j >= 0 && arr[j] > key){
			arr[j + 1] = arr[j];
			j--;
		}

		//element at j plus one is now the key
		arr[j + 1] = key;

		//increment counter by one
		counter++;

		//loops through array and prints out counter number of elements in a line.
		for (int i = 0; i < counter; i++){
			cout << arr[i] << ";";
		}

		//adds an enter line after printing out line of elements.
		cout << endl;
	}

}

int main(int argc, char const *argv[]){

    //initialize variable to store array size
	int arrSize;

    //takes in integer for array size
	cin >> arrSize;

    //initialize array to store integer elements
	int arr[arrSize];

    //loops through slots in array and inserts input value
	for (int i = 0; i < arrSize; i++){
		cin >> arr[i];
	}

    //sorts the array and outputs snapshot of each iteration
	InsertionSort(arr, arrSize);

	return 0;
}
