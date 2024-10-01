#include <iostream>
using namespace std;
void  split(int* ini, int* medio);
void imprimirArray(int arr[], int size);


int main() {
    int arr[] = { 1,2,3,4 };
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << "Array original: ";
    imprimirArray(arr, size); 

    split(arr, arr + 2 ); 
    cout << "Array ordenado: ";
    imprimirArray(arr, size); 

    return 0;
}

void imprimirArray(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void  split(int* ini, int* medio) {

    int* puntero1 = ini;

    int* final = medio + ((medio - ini) - 1);

    while (puntero1 < final) {
        if (*puntero1 % 2 == 0) {
            puntero1++;
        }
        else {
            int temp = *puntero1;
            for (int* r = puntero1; r < final; r++) {
                *r = *(r + 1);  
            }
            *final = temp; 
            final--; 
        }
    }
}
