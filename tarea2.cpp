#include <iostream>
#include <string>
using namespace std;
string texto_unidad(int valor, bool esMillar = false);
string texto_decena(int valor, bool esMillar = false);
string texto_centena(int valor, bool esMillar = false);
string texto_millar(int valor);
string convertir_a_texto(int valor);
string convertir_restante(int valor, bool esMillar);

int main() {
    int numeroIngresado;
    cout << "Ingresa un numero: ";
    cin >> numeroIngresado;
    convertir_a_texto(numeroIngresado);
    string numero = convertir_a_texto(numeroIngresado);
    cout << "El numero en letras es: " << numero;
 
}

string convertir_restante(int valor, bool esMillar = false) {
    if (valor == 0) {
        return "";
    }
    else if (valor < 100) {
        return texto_decena(valor, esMillar);
    }
    else {
        return texto_centena(valor, esMillar);
    }
}

string convertir_a_texto(int valor) {
    if (valor == 0) {
        return "cero";
    }

    if (valor >= 1000000) {
        return "FUERA DE RANGO OE";
    }
    else if (valor >= 1000) {
        return texto_millar(valor);
    }
    else {
        return convertir_restante(valor);
    }
}

string texto_unidad(int valor, bool esMillar) {
    if (valor >= 1 && valor <= 9) {
        switch (valor) {
        case 1: return esMillar ? "un" : "uno";
        case 2: return "dos";
        case 3: return "tres";
        case 4: return "cuatro";
        case 5: return "cinco";
        case 6: return "seis";
        case 7: return "siete";
        case 8: return "ocho";
        case 9: return "nueve";
        }
    }
    return "";
}

string texto_decena(int valor, bool esMillar) {
    if (valor >= 10 && valor <= 19) {
        switch (valor) {
        case 10: return "diez";
        case 11: return "once";
        case 12: return "doce";
        case 13: return "trece";
        case 14: return "catorce";
        case 15: return "quince";
        case 16: return "dieciséis";
        case 17: return "diecisiete";
        case 18: return "dieciocho";
        case 19: return "diecinueve";
        }
    }
    else if (valor >= 20) {
        switch (valor / 10) {
        case 2: return (valor % 10 == 0) ? "veinte" : "veinti" + texto_unidad(valor % 10, esMillar);
        case 3: return (valor % 10 == 0) ? "treinta" : "treinta y " + texto_unidad(valor % 10, esMillar);
        case 4: return (valor % 10 == 0) ? "cuarenta" : "cuarenta y " + texto_unidad(valor % 10, esMillar);
        case 5: return (valor % 10 == 0) ? "cincuenta" : "cincuenta y " + texto_unidad(valor % 10, esMillar);
        case 6: return (valor % 10 == 0) ? "sesenta" : "sesenta y " + texto_unidad(valor % 10, esMillar);
        case 7: return (valor % 10 == 0) ? "setenta" : "setenta y " + texto_unidad(valor % 10, esMillar);
        case 8: return (valor % 10 == 0) ? "ochenta" : "ochenta y " + texto_unidad(valor % 10, esMillar);
        case 9: return (valor % 10 == 0) ? "noventa" : "noventa y " + texto_unidad(valor % 10, esMillar);
        }
    }
    else {
        return texto_unidad(valor, esMillar);
    }
    return "";
}

string texto_centena(int valor, bool esMillar) {
    if (valor >= 100) {
        switch (valor / 100) {
        case 1: return (valor % 100 == 0) ? "cien" : "ciento " + texto_decena(valor % 100, esMillar);
        case 2: return "doscientos " + texto_decena(valor % 100, esMillar);
        case 3: return "trescientos " + texto_decena(valor % 100, esMillar);
        case 4: return "cuatrocientos " + texto_decena(valor % 100, esMillar);
        case 5: return "quinientos " + texto_decena(valor % 100, esMillar);
        case 6: return "seiscientos " + texto_decena(valor % 100, esMillar);
        case 7: return "setecientos " + texto_decena(valor % 100, esMillar);
        case 8: return "ochocientos " + texto_decena(valor % 100, esMillar);
        case 9: return "novecientos " + texto_decena(valor % 100, esMillar);
        }
    }
    else {
        return texto_decena(valor, esMillar);
    }
    return "";
}

string texto_millar(int valor) {
    if (valor >= 1000) {
        int valorMillar = valor / 1000;
        int resto = valor % 1000;

        string textoMillar;
        if (valorMillar == 1) {
            textoMillar = "mil";
        }
        else {
            textoMillar = texto_centena(valorMillar, true) + " mil";
        }

        if (resto > 0) {
            textoMillar += " " + texto_centena(resto);
        }

        return textoMillar;
    }
    else {
        return texto_centena(valor);
    }
}
