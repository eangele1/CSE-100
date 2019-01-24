#include <iostream>

using namespace std;

void InsertionSort(int arr[], int arrSize){
    
    int key;
    int counter = 1;
    
    for (int i = 1; i < arrSize; i++){
        key = arr[i];
        int j = i - 1;
        
        while(j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
        
        counter++;
        
        for (int i = 0; i < counter; i++){
            cout << arr[i] << ";";
        }
        cout << endl;
    }
    
}

int main(int argc, char const *argv[]){
    
    int arrSize;
    
    cin >> arrSize;
    
    int arr[arrSize];
    
    for (int i = 0; i < arrSize; i++){
        cin >> arr[i];
    }
    
    InsertionSort(arr, arrSize);
    
    return 0;
}
