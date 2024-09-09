#include <iostream>

using namespace std;

// Función para imprimir el array
void imprimirArray(int arr[], int tam) {
    for (int i = 0; i < tam; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Función para ordenar el array usando un enfoque de bubble sort con dos punteros
void ordenarArray(int* arr, int tam) {
    int* puntero1 = arr;  // Puntero que comienza al inicio del array
    int* puntero2 = arr + tam / 2;  // Puntero que comienza en la mitad

    // Usaremos un enfoque similar al bubble sort para ordenar el array
    // Primero, compararemos y ordenaremos las dos mitades del array
    for (int i = 0; i < tam / 2; ++i) {
        for (int j = 0; j < tam / 2; ++j) {
            if (*(puntero1 + j) > *(puntero2 + j)) {
                int temp = *(puntero1 + j);
                *(puntero1 + j) = *(puntero2 + j);
                *(puntero2 + j) = temp;
            }
        }
    }

    // Ahora ordenamos el array completo usando bubble sort
    for (int i = 0; i < tam - 1; ++i) {
        for (int j = 0; j < tam - i - 1; ++j) {
            if (*(arr + j) > *(arr + j + 1)) {
                int temp = *(arr + j);
                *(arr + j) = *(arr + j + 1);
                *(arr + j + 1) = temp;
            }
        }
    }
}

int main() {
    // Array de ejemplo con números primos y no primos
    int arr[] = { 1, 4, 8, 9, 2, 3, 19, 5 };
    int tam= sizeof(arr) / sizeof(arr[0]);

    cout << "Array original: ";
    imprimirArray(arr, tam);

    // Llamada a la función de ordenación
    ordenarArray(arr, tam);

    cout << "Array ordenado: ";
    imprimirArray(arr, tam);

    return 0;
}
