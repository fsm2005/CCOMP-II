#include <iostream>
using namespace std;

void cantidad_dinero(double result);

int main() {
    double result;

    cout << "Cantidad en soles: ";
    cin >> result;

    cantidad_dinero(result);

    return 0;
}

void cantidad_dinero(double result) {

    int billetes[5] = { 200, 100, 50, 20, 10 };
    int monedas[3] = { 5, 2, 1 };
    double centimos[3] = { 0.50, 0.20, 0.10 };

    int entero = result;

    int decimal = ((result - entero) * 100);


    for (int i = 0; i < 5; i++) {
        int canbilletes = entero / billetes[i];
        entero %= billetes[i];
        cout << "Billetes de " << billetes[i] << " soles: " << canbilletes << endl;
    }

    for (int i = 0; i < 3; i++) {

        int canmonedas = entero / monedas[i];
        entero %= monedas[i];
        cout << "monedas de " << monedas[i] << " soles: " << canmonedas << endl;
    }

    for (int i = 0; i < 3; i++) {
        int cancentimos = decimal / (centimos[i] * 100);
        decimal = (int)(decimal % (int)(centimos[i] * 100));
        cout << "Centimos de " << centimos[i] << " : " << cancentimos << endl;
    }


}