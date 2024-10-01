
int main() {
    int arr[] = { 2, 16, 34 ,88 ,1, 13 ,55, 99,
        0 }; 
        0 };
    cout << "Array original: ";
    imprimirArray(arr);

    merge(arr);
    //merge(arr,arr+5);

    cout << "Array ordenado: ";
    imprimirArray(arr);
    cout << endl;
}

//void merge(int* ini. int *med) 
void merge(int* arr) {

    for (int i = 0; i < 7; i++) {

        int* temp = arr;
        for (; *temp; temp++) {}

        int* puntero2 = puntero1 + (temp - puntero1) / 2;

        int* final = puntero2 + (puntero2 - puntero1);

        // final = med + ((med-ini)-1)
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
