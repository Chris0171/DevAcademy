#include <iostream>
#include <string>

using namespace std;

struct Usuario
{
    int nroUsuario;
    string nombre;
};


void bubbleSort(int arr[], int n);
void bubbleSortOptimized(Usuario arr[], int n);

void insertionSort(Usuario arr[], int n);


int main()
{

    Usuario arr[] = {
        {4124, "Juan"},
        {1231, "Maria"},
        {3231, "Pedro"},  
    };

    for(auto elem: arr){
        cout << elem.nroUsuario << " " << elem.nombre << " ";
    }
    cout << endl;

    bubbleSortOptimized(arr, 3);

    for(auto elem: arr){
        cout << elem.nroUsuario << " " << elem.nombre << " ";
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

void bubbleSortOptimized(Usuario arr[], int n){
    bool cambiado; 
    int counter = 0;
    for (int i = 0; i < n - 1; i++){ // n = 5
        cambiado = false;
        for(int j = 0; j < n - 1 - i; j++){
            if(arr[j].nroUsuario > arr[j + 1].nroUsuario){
                swap(arr[j], arr[j + 1]);
                cambiado = true;
            }
            counter++;
        }
        if(!cambiado) i = n;
    }

    cout << "Counter: " << counter << endl;
}

// [3 5 7]
// Complejidad: Mejor caso -> O(n); 
// Complejidad: Peor caso -> O(n^2); 
void insertionSort(Usuario arr[], int n){
    for(int i = 1; i <n; i++){
        Usuario clave = arr[i];
        int j = i - 1;

        while(j >= 0 && arr[j].nroUsuario > clave.nroUsuario){
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = clave;
    }
}
