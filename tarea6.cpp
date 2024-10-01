#include <iostream>
#include <cstring> 
bool palindromo(char* p);
void uppercase(char* p);

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

void uppercase(char* p) {
    for (; *p; p++) {
        if ((*p >= 'A') && (*p <= 'Z')) {
            *p += 32; 
        }
    }
}

bool palindromo(char* p) {
    uppercase(p);

    int len = std::strlen(p);

    char* inicio = p;
    char* fin = p + len - 1;

    while (inicio < fin) {
        while (*inicio == ' ') {
            inicio++;
        }
        while (*fin == ' ') {
            fin--;
        }
        if (*inicio != *fin) {
            return false;
        }
        inicio++;
        fin--;
    }
    return true;
}
