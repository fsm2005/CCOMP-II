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

    int* final = medio + ((medio - ini) - 1);

    for (int* t = ini; t <= final;++t) {
        if (*ini % 2 == 0) {
            ini++;
        }

        else {
            for (int* r = final; r > ini; r --) {
                swap(*r, *ini);
            }
        }
    }
}
