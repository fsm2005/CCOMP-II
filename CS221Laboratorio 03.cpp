#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

void shiftRight(bitset<16>& A, bitset<16>& Q, int& Q1, int n) {
    int msbA = A[n - 1];
    Q1 = Q[0];
    Q >>= 1;
    Q[n - 1] = A[0];  
    A >>= 1; 
    A[n - 1] = msbA; 
}

bitset<16> addBinary(bitset<16> a, bitset<16> b, int n) {
    bitset<16> sum;
    int carry = 0;
    for (int i = 0; i < n; ++i) {
        int bitSum = a[i] + b[i] + carry;
        sum[i] = bitSum % 2;
        carry = bitSum / 2;
    }
    return sum;
}

bitset<16> twosComplement(bitset<16> b, int n) {
    bitset<16> complement;
    complement = ~b; 
    bitset<16> one(1); 
    return addBinary(complement, one, n);
}

void boothAlgorithm(int M, int Q, int n) {
    bitset<16> A(0), M_bin(M), Q_bin(Q);
    int Q1 = 0;

    for (int i = 0; i < n; ++i) {
        if (Q_bin[0] == 1 && Q1 == 0) {
            A = addBinary(A, twosComplement(M_bin, n), n); 
        }
        else if (Q_bin[0] == 0 && Q1 == 1) {
            A = addBinary(A, M_bin, n); 
        }

        shiftRight(A, Q_bin, Q1, n);  
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

    boothAlgorithm(M, Q, n);

    return 0;
}



