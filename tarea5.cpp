#include <iostream>

using namespace std;
void koctel(int* arr, int*medio);
void imprimirArray(int arr[], int size);

int main() {
    int arr[] = { 51, 3, 28, 35, 4, 2, 7, 23, 15,10};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << "Original: ";
    imprimirArray(arr, size); 
    koctel(arr, arr+5);
    cout << "Ordenado: ";
    imprimirArray(arr, size); 
    return 0;
}
void imprimirArray(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void koctel(int* arr, int* medio) {
    bool cambio = true;
    int* ini = arr;
    int* fin = medio + ((medio - ini) - 1);

    while (ini < fin&& cambio) {
        cambio = false;

        for (int* ptr = ini; ptr < fin; ++ptr) {
            if (*ptr > *(ptr + 1)) {
                int temp = *(ptr+1);
                *(ptr+1) = *ptr;
                *ptr = temp;

                cambio = true;
            }
        }
        
        if (!cambio)
            break;
        --fin;
        cambio = false;

        for (int* ptr = fin; ptr > ini; --ptr) {
            if (*ptr < *(ptr - 1)) {
                int temp = *(ptr-1);
                *(ptr-1) = *ptr;
                *ptr = temp;
                
                
                cambio = true;
            }
        }
        ++ini;
    }
}
