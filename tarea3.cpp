#include <iostream>

using namespace std;

void merge(int* arr);

void imprimirArray(int arr[]);

int main() {
    int arr[] = { 2, 16, 34 ,88 ,1, 13 ,55, 99,
        0 }; 
    cout << "Array original: ";
    imprimirArray(arr);

    merge(arr);

    cout << "Array ordenado: ";
    imprimirArray(arr);

    return 0;
}
void imprimirArray(int arr[]) {
    for (int i = 0; arr[i] != 0; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void merge(int* arr) {

    for (int i = 0; i < 7; i++) {
        int* puntero1 = arr;

        int* temp = arr;
        for (; *temp; temp++) {}

        int* puntero2 = puntero1 + (temp - puntero1) / 2;

        int* final = puntero2 + (puntero2 - puntero1);

        while ((puntero1 < puntero2) && (puntero2 < final)) {
            int* r = puntero1;

            while (r < final) {
                puntero1 = r;
                puntero2 = r + 1;

                if (*puntero1 > *puntero2 && puntero2 < final) {
                    int temp = *puntero1;
                    *puntero1 = *puntero2;
                    *puntero2 = temp;
                }
                r++;
            }

            puntero1++;
            puntero2++;
        }
    }
}
