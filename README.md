Ciencia de la Computación II CCOMP3-1
void ordenarArray(int* arr, int tam) {
    int* puntero1 = arr; 
    int* puntero2 = arr + tam / 2;

    // Primer bucle: Comparación y ordenamiento entre las dos mitades.
    while (puntero1 < arr + tam / 2) {
        int* tempPtr1 = puntero1;
        int* tempPtr2 = puntero2;

        while (tempPtr1 < arr + tam / 2) {
            if (*tempPtr1 > *tempPtr2) {
                int temp = *tempPtr1;
                *tempPtr1 = *tempPtr2;
                *tempPtr2 = temp;
            }
            tempPtr1++;
            tempPtr2++;
        }
        puntero1++;
        puntero2++;
    }

    // Segundo bucle: Ordenamiento total del array usando burbuja sin índices.
    int* endPtr = arr + tam - 1;
    while (arr









    
