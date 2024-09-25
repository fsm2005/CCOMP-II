#include <iostream>
#include <cmath>
#include <cstdint>

using namespace std;

uint32_t convertirFloatABinario(float valor) {
    union {
        float flotante;
        uint32_t entero;
    } unionValor;
    unionValor.flotante = valor;
    return unionValor.entero;
}

float convertirBinarioAFloat(uint32_t binario) {
    union {
        float flotante;
        uint32_t entero;
    } unionValor;
    unionValor.entero = binario;
    return unionValor.flotante;
}

void descomponer(float valor, int& signo, int& exponente, uint32_t& mantisa) {
    uint32_t bits = convertirFloatABinario(valor);
    signo = (bits >> 31) & 1;
    exponente = (bits >> 23) & 0xFF;
    mantisa = bits & 0x7FFFFF;
    mantisa |= 0x800000;
}

uint32_t ensamblarNumero(int signo, int exponente, uint32_t mantisa) {
    mantisa &= 0x7FFFFF;
    uint32_t resultado = (signo << 31) | (exponente << 23) | mantisa;
    return resultado;
}

float emularMultiplicacionPuntoFlotante(float num1, float num2) {
    if (num1 == 0.0f || num2 == 0.0f) {
        return 0.0f;
    }

    int signo1, exp1;
    uint32_t mantisa1;
    int signo2, exp2;
    uint32_t mantisa2;

    descomponer(num1, signo1, exp1, mantisa1);
    descomponer(num2, signo2, exp2, mantisa2);

    int expResultado = (exp1 - 127) + (exp2 - 127) + 127;

    uint64_t mantisaResultado = (uint64_t)mantisa1 * (uint64_t)mantisa2;

    if (mantisaResultado & (1ULL << 47)) {
        mantisaResultado >>= 1;
        expResultado++;
    }

    mantisaResultado = (mantisaResultado >> 23) & 0x7FFFFF;

    if (expResultado >= 255) {
        expResultado = 255;
        mantisaResultado = 0;
    }
    else if (expResultado <= 0) {
        return 0.0f;
    }

    int signoResultado = signo1 ^ signo2;
    uint32_t resultadoBits = ensamblarNumero(signoResultado, expResultado, mantisaResultado);

    return convertirBinarioAFloat(resultadoBits);
}

int main() {
    float numero1, numero2;

    cout << "Ingrese el primer numero: ";
    cin >> numero1;
    cout << "Ingrese el segundo numero: ";
    cin >> numero2;

    float resultadoEmulado = emularMultiplicacionPuntoFlotante(numero1, numero2);
    float resultadoReal = numero1 * numero2;

    cout << " Resultado: \n" << resultadoEmulado << endl;
    cout << "Resultado real: " << resultadoReal << endl;

    if (fabs(resultadoEmulado - resultadoReal) < 1e-6) {
        cout << "\nLos resultados coinciden dentro de la tolerancia.\n";
    }
    else {
        cout << "\nLos resultados difieren.\n";
    }

    return 0;
}
