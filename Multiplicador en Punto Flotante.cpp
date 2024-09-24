#include <iostream>
#include <bitset>
#include <cmath>
#include <cstdint>

using namespace std;
uint32_t floatToBinary(float f);
float binaryToFloat(uint32_t binary);
void mostrarBits(float numero);
float multiplicacionInusual(float a, float b);

int main() {
    float a, b;

    cout << "Dame un número (float): ";
    cin >> a;
    cout << "Dame otro número (float): ";
    cin >> b;

    cout << "\nVamos a analizar el primer número:\n";
    mostrarBits(a);
    cout << "\nY ahora, el segundo número:\n";
    mostrarBits(b);

    float resultadoInusual = multiplicacionInusual(a, b);

    float resultadoNormal = a * b;

    cout << "\nResultado de nuestra multiplicación inusual:\n";
    mostrarBits(resultadoInusual);
    cout << "Valor: " << resultadoInusual << endl;

    cout << "\nEl resultado normal es: " << resultadoNormal << endl;

    if (fabs(resultadoInusual - resultadoNormal) < 1e-6) {
        cout << "\n¡Sorpresa! Los resultados coinciden. ¡Misión cumplida!\n";
    }
    return 0;
}
uint32_t floatToBinary(float f) {
    union {
        float f;
        uint32_t i;
    } u;
    u.f = f;
    return u.i;
}
float binaryToFloat(uint32_t binary) {
    union {
        uint32_t i;
        float f;
    } u;
    u.i = binary;
    return u.f;
}
void mostrarBits(float numero) {
    uint32_t bits = floatToBinary(numero);
    cout << "Superpoderes del número (" << numero << "):\n";
    cout << "Bits: " << bitset<32>(bits) << endl;
    cout << "Signo: " << ((bits >> 31) & 1) << " (Este es el temperamento, positivo o negativo)\n";
    cout << "Exponente: " << bitset<8>((bits >> 23) & 0xFF) << " (El nivel de poder del número)\n";
    cout << "Significando: " << bitset<23>(bits & 0x7FFFFF) << " (Es como su ADN)\n";
}

float multiplicacionInusual(float a, float b) {

    if (a == 0.0f || b == 0.0f) {
        cout << "Boom, uno de ellos es 0. Así que el resultado también es 0.\n";
        return 0.0f;
    }

    uint32_t bitsA = floatToBinary(a);
    uint32_t bitsB = floatToBinary(b);

    int signoA = (bitsA >> 31) & 1;
    int signoB = (bitsB >> 31) & 1;
    int signoResultado = signoA ^ signoB;

    int exponenteA = (bitsA >> 23) & 0xFF;
    int exponenteB = (bitsB >> 23) & 0xFF;

    uint32_t significandoA = (bitsA & 0x7FFFFF) | 0x800000;
    uint32_t significandoB = (bitsB & 0x7FFFFF) | 0x800000;

    int exponenteResultado = exponenteA + exponenteB - 127;

    uint64_t significandoResultado = (uint64_t)significandoA * (uint64_t)significandoB;

    if (significandoResultado & (1ULL << 47)) {
        significandoResultado >>= 1;
        exponenteResultado++;
    }

    significandoResultado &= 0x7FFFFF;

    if (exponenteResultado >= 255) {
        cout << "¡Overflow! Nos fuimos al infinito y más allá.\n";
        exponenteResultado = 255;
        significandoResultado = 0;
    }
    else if (exponenteResultado <= 0) {
        cout << "Underflow... el número es tan pequeño que se desvanece en 0.\n";
        return 0.0f;
    }

    uint32_t resultadoBits = (signoResultado << 31) | (exponenteResultado << 23) | significandoResultado;
    return binaryToFloat(resultadoBits);
}