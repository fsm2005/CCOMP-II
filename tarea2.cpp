#include <iostream>
#include <string>
using namespace std;

string unidades[10] = { "", "uno", "dos", "tres", "cuatro", "cinco", "seis", "siete", "ocho", "nueve" };
string decenas[10] = { "", "diez", "veinte", "treinta", "cuarenta", "cincuenta", "sesenta", "setenta", "ochenta", "noventa" };
string problema[10] = { "diez", "once", "doce", "trece", "catorce", "quince", "dieciséis", "diecisiete", "dieciocho", "diecinueve" };
string centenas[10] = { "", "ciento", "doscientos", "trescientos", "cuatrocientos", "quinientos", "seiscientos", "setecientos", "ochocientos", "novecientos" };

string transmutar(int num);

int main() {
    int valor;
    cout << "Ingrese un numero: ";
    cin >> valor;
    cout << "El número en letras es: " << transmutar(valor) << endl;
}

string transmutar(int num) {
    if (num == 0) return "Cero";
 
    string resul;

    if (num >= 100000) {
        int centenasMil = num / 100000;
        resul += centenas[centenasMil] + " ";
        num %= 100000;
    }
    if (num >= 21000 && num < 22000) {
        resul += "Veintiun Mil ";
        num %= 1000;
    }
    if (num >= 20000) {
        int decenasMil = num / 10000;
        int unidadesMil = (num / 1000) % 10;

        if (decenasMil == 2 && unidadesMil > 0) { 
            resul += "Veinti" + unidades[unidadesMil] + " Mil ";
            num %= 1000;
        }
        else {
            resul += decenas[decenasMil] + " y ";
            num %= 10000;
        }
    }
    else if (num >= 10000) { 
        int miles = (num / 1000) % 10;
        resul += problema[miles] + " Mil ";
        num %= 1000;
    }

    if (num >= 1000) {
        int unidadesMil = num / 1000;
        if (unidadesMil == 1 && num % 1000 == 0) {
            return resul + "Mil";
        }
        else if (unidadesMil == 1) {
            resul += "Mil ";
        }
        else {
            resul += unidades[unidadesMil] + " Mil ";
        }
        num %= 1000;
    }

    if (num >= 100) {
        int centegan = num / 100;
        resul += centenas[centegan] + "  ";
        num %= 100;
    }

    if (num >= 20) {
        if (num / 10 == 2 && num % 10 > 0) {
            resul += "Veinti" + unidades[num % 10];
            num = 0;
        }
        else {
            resul += decenas[num / 10] + " y ";
            num %= 10;
        }
    }
    else if (num >= 10) { 
        return resul + problema[num - 10];
    }

    resul += unidades[num];

    return resul;
}
