#include <iostream>

using namespace std;

void imprimirArray(int arr[]) {
    
    for (int i = 0; arr[i] != 0; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void merge(int* arr) {
    int* puntero1 = arr;

    int* temp = arr;

    for (;*temp;temp++) {}
  
    int* puntero2 = puntero1 + (temp - puntero1) / 2;

    int* final = puntero2 + (puntero2 - puntero1);  

    
    while ((puntero1 < puntero2) && (puntero2 > final)) {
        if (*puntero1 > *puntero2) {
            int temp = *puntero1;
            *puntero1 = *puntero2;
            *puntero2 = temp;
            
        }
        else {
            puntero1++;  
            puntero2++;  
        }
    }
}

int main() {
    int arr[] = { 2, 6, 8, 20, 1, 3, 7, 11 ,
        0}; 
    cout << "Array original: ";
    imprimirArray(arr);

    merge(arr);

    cout << "Array ordenado: ";
    imprimirArray(arr);

    return 0;
}
