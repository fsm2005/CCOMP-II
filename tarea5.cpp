#include <iostream>

using namespace std;

void ordenar(int* arr, int n);

void intercambiar(int* a, int* b);

int main() {
    int arr[] = { 51, 3, 28, 35, 4, 2, 7, 23, 15,10};
    

    cout << "Original: ";
    for (int i = 0; i < ta; i++)
        cout << arr[i] << " ";
    cout << endl;

   
    ordenar(arr, arr+5);

    cout << "Ordenado: ";
    for (int i = 0; i < ta; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}

void ordenar(int* arr, int* medio) {
    bool cambio = true;
    int* ini = arr;
    int* fin = medio + ((medio - ini) - 1);

    while (ini < fin&& cambio) {
        cambio = false;

        for (int* ptr = ini; ptr < fin; ++ptr) {
            if (*ptr > *(ptr + 1)) {
                intercambiar(ptr, ptr + 1);  
                cambio = true;
            }
        }

        if (!cambio)
            break;

        --fin;

        cambio = false;

        for (int* ptr = fin; ptr > ini; --ptr) {
            if (*ptr < *(ptr - 1)) {
                intercambiar(ptr, ptr - 1);  
                cambio = true;
            }
        }

        ++ini;
    }
}

void intercambiar(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
