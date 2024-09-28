#include <iostream>
using namespace std;
void  split(int* ini, int* medio);
void imprimirArray(int arr[]);

int main() {
    int arr[] = { 2, 6, 5 ,8 ,1, 7 ,5, 9 };
    cout << "Array original: ";
    imprimirArray(arr);

    split(arr, arr + 4);
    cout << "Array ordenado: ";
    imprimirArray(arr);

    return 0;
}
void imprimirArray(int arr[]) {
    for (int i = 0; arr[i] != 9; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void  split(int* ini, int* medio) {

    int* puntero1 = ini;

    int* final = medio + ((medio - ini) - 1);

    while (puntero1 < final)
    {
        if (*puntero1 % 2 == 0) {
            puntero1++;
        }
        else {
            for (int* r = ini + 1;*r < *final;r++) {
                int temp = *ini;
                *ini = *r;
                *r = temp;
                ini++;
                r++;
            }
        }
    }

}
