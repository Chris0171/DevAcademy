#include <iostream>
#include <string>

using namespace std;

// [ 2, 3, 4, 5, 8 ]
void bubbleSort(int arr[], int n);
void bubbleSortOptimized(int arr[], int n);



int main()
{
    int arr[] = {1, 2, 5, 5, 9, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    for(auto elem: arr){
        cout << elem << " ";
    }
    cout << endl;

    bubbleSortOptimized(arr, n);

    for(auto elem: arr){
        cout << elem << " ";
    }
    cout << endl;

    return 0;
}

void bubbleSort(int arr[], int n){
    int counter = 0;
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - 1 - i; j++){
            if(arr[j] > arr[j + 1]){
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
            counter++;
        }
    }
    cout << "Counter: " << counter << endl;
}

void bubbleSortOptimized(int arr[], int n){
    bool cambiado; 
    int counter = 0;
    for (int i = 0; i < n - 1; i++){ // n = 5
        cambiado = false;
        for(int j = 0; j < n - 1 - i; j++){
            if(arr[j] > arr[j + 1]){
                swap(arr[j], arr[j + 1]);
                cambiado = true;
            }
            counter++;
        }
        if(!cambiado) i = n;
    }

    cout << "Counter: " << counter << endl;
}