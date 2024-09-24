#include <iostream>

using namespace std;

void merge_par_impar (int* arr);

void imprimirArray(int arr[]);

int main() {
    int arr[] = { 2, 6, 4 ,8 ,1, 7 ,5, 9,
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

void merge_par_impar(int* arr) {

    for (int i = 0; i < 7; i++) {
        int* puntero1 = arr;

        int* temp = arr;
        for (; *temp; temp++) {}
  
        int* puntero2 = puntero1 + (temp - puntero1) / 2;

        for (int* p1 = puntero1; p1 < puntero2 - 1; ++p1) {
            for (int* p2 = p1 + 1; p2 < puntero2; ++p2) {
                if (*p1 < *p2) {  
                    int temp = *p1;
                    *p1 = *p2;
                    *p2 = temp;
                }
            }
        }
        for (int* p1 = puntero2; *p1 != 0; ++p1) {
            for (int* p2 = p1 + 1; *p2 != 0; ++p2) {
                if (*p1 < *p2) {  
                    int temp = *p1;
                    *p1 = *p2;
                    *p2 = temp;
                }
            }
        }
    }
}
