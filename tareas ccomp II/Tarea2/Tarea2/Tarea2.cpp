#include <iostream>
#include <string>
using namespace std;

string unidades[10] = { " ", "Uno", "Dos", "Tres", "Cuatro", "Cinco", "Seis", "Siete", "Ocho", "Nueve" };
string decenas[10] = { " ", "Diez", "Veinte", "Treinta", "Cuarenta", "Cincuenta", "Sesenta", "Setenta", "Ochenta", "Noventa" };
string problema[10] = { "Diez", "Once", "Doce", "Trece", "Catorce", "Quince", "Dieciséis", "Diecisiete", "Dieciocho", "Diecinueve" };
string centenas[10] = { " ", "Cien", "Doscientos", "Trescientos", "Cuatrocientos", "Quinientos", "Seiscientos", "Setecientos", "Ochocientos", "Novecientos" };

string transmutar(int num);

int main() {
    int valor;
    cout << "Ingrese un numero: ";
    cin >> valor;
    cout << "El numero en letras es: " << transmutar(valor) << endl;
}

string transmutar(int num) {
    if (num == 0) return "Cero";

    string resul;

    if (num >= 1000) {
        int miles = num / 1000;
        if (miles > 1) resul += unidades[miles] + " Mil ";
        else  resul += "Mil ";
        num %= 1000;
    }

    if (num >= 100) {
        if (num == 100) return  resul + "Cien";
        resul += centenas[num / 100] + " ";
        num %= 100;
    }

    if (num >= 20) {
        resul += decenas[num / 10] + " ";
        num %= 10;
    }
    else if (num >= 10) {
        return  resul + problema[num - 10];
    }

    resul += unidades[num];

    return resul;
}