#include <iostream>
#include <cstring> 
char convertirMinuscula(char c);
bool palindromo(char* p);

int main() {
    char cadena[] = "Anita lava la tina"; 

    if (palindromo(cadena)) {
        std::cout << "Es un palindromo" << std::endl;
    }
    else {
        std::cout << "No es un palindromo" << std::endl;
    }

    return 0;
}

char convertirMinuscula(char c) {
    if (c >= 'A' && c <= 'Z') {
        return c + 32; 
    }
    return c; 
}

bool palindromo(char* p) {

    int len = std::strlen(p);
    char* ini = p;
    char* fin = p + len - 1;

    while (ini< fin) {
        while (*ini == ' ') {
            ini++;
        }
        while (*fin == ' ') {
            fin--;
        }
        if (convertirMinuscula(*ini) != convertirMinuscula(*fin)) {
            return false; 
        }
        ini++;
        fin--;
    }
    return true; 
}
