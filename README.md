Ciencia de la Computación II CCOMP3-1
void ordenarArray(int* arr, int tam) {
    int* puntero1 = arr; 
    int* puntero2 = arr + tam / 2;
    int* finalPuntero1 = arr + tam / 2;
    int* finalArr = arr + tam;

    // Primer bucle para comparar elementos entre puntero1 y puntero2
    for (int* p1 = puntero1, *p2 = puntero2; p1 < finalPuntero1; ++p1, ++p2) {
        if (*p1 > *p2) {
            int temp = *p1;
            *p1 = *p2;
            *p2 = temp;
        }
    }

    // Segundo bucle para ordenar todo el array usando punteros
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









    
