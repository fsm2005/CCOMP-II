#include <iostream>

void ordenarParesyImparesDescendente(int* arr, int size);

int main() {
    int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
    int size = sizeof(arr) / sizeof(arr[0]);

    std::cout << "original: ";
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    ordenarParesyImparesDescendente(arr, size);

    std::cout << "ordenado: ";
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
void intercambiar(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void ordenarDescendente(int* inicio, int* fin) {
    for (int* i = inicio; i < fin - 1; i++) {
        for (int* j = inicio; j < fin - (i - inicio) - 1; j++) {
            if (*j < *(j + 1)) {
                intercambiar(j, j + 1);
            }
        }
    }
}
void ordenarParesyImparesDescendente(int* arr, int size) {
    int* inicio = arr;
    int* fin = arr + size - 1;


    while (inicio < fin) {
        if (*inicio % 2 != 0) {
            intercambiar(inicio, fin);
            fin--;
        }
        else {
            inicio++;
        }
    }

    int* mitad = inicio;

    ordenarDescendente(arr, mitad);

    ordenarDescendente(mitad, arr + size);
}