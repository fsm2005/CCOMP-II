#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

void desplazarDerecha(bitset<16>& A, bitset<16>& Q, int& Q1, int n) {
    int msbA = A[n - 1];
    Q1 = Q[0];
    Q >>= 1;
    Q[n - 1] = A[0];
    A >>= 1;
    A[n - 1] = msbA;
}

bitset<16> sumarBinario(bitset<16> a, bitset<16> b, int n) {
    bitset<16> suma;
    int acarreo = 0;
    for (int i = 0; i < n; ++i) {
        int bitSuma = a[i] + b[i] + acarreo;
        suma[i] = bitSuma % 2;
        acarreo = bitSuma / 2;
    }
    return suma;
}

bitset<16> complementoDos(bitset<16> b, int n) {
    bitset<16> complemento;
    complemento = ~b;
    bitset<16> uno(1);
    return sumarBinario(complemento, uno, n);
}

void algoritmoBooth(int M, int Q, int n) {
    bitset<16> A(0), M_bin(M), Q_bin(Q);
    int Q1 = 0;

    for (int i = 0; i < n; ++i) {
        if (Q_bin[0] == 1 && Q1 == 0) {
            A = sumarBinario(A, complementoDos(M_bin, n), n);
        }
        else if (Q_bin[0] == 0 && Q1 == 1) {
            A = sumarBinario(A, M_bin, n);
        }

        desplazarDerecha(A, Q_bin, Q1, n);
        i + 1;
    }
    cout << "Resultado binario: " << A << Q_bin << endl;
    cout << "Resultado: " << (A.to_ulong() << n | Q_bin.to_ulong()) << endl;
}

int main() {
    int M, Q, n;
    cout << "Ingrese numero (M): ";
    cin >> M;
    cout << "Ingrese numero (Q): ";
    cin >> Q;
    cout << "Ingrese la cantidad de bits : ";
    cin >> n;

    algoritmoBooth(M, Q, n);

    return 0;
}


