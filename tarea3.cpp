#include <iostream>

using namespace std;

void imprimirArray(int arr[], int tam) {
    for (int i = 0; i < tam; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void ordenarArray(int* arr, int tam) {
    int* puntero1 = arr; int* puntero2 = arr + tam / 2; int* finalPuntero1 = arr + tam / 2; int* finalArr = arr + tam;

 
    for (int* p1 = puntero1, *p2 = puntero2; p1 < finalPuntero1; ++p1, ++p2) {
        if (*p1 > *p2) {
            int temp = *p1;
            *p1 = *p2;
            *p2 = temp;
        }
    }

    for (int* p1 = arr; p1 < finalArr - 1; ++p1) {
        for (int* p2 = p1 + 1; p2 < finalArr; ++p2) {
            if (*p1 > *p2) {
                int temp = *p1;
                *p1 = *p2;
                *p2 = temp;
            }
        }
    }
}

int main() {

    int arr[] = { 2, 6, 8,12,20,1,3,7,11,15 };
    int tam = sizeof(arr) / sizeof(arr[0]);

    cout << "Array original: ";
    imprimirArray(arr, tam);

    ordenarArray(arr, tam);

    cout << "Array ordenado: ";
    imprimirArray(arr, tam);

    return 0;
}